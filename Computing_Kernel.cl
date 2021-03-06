#include "Settings_and_Parameters.h"

////////////////////////////////////////////////////////////////////////////////
// Laplacation operator definition, to calculate diffusive fluxes
////////////////////////////////////////////////////////////////////////////////

float d2_dxy2(__global float* pop, int row, int column)
{
    float retval;
    
    int current = row * Grid_Width + column;
    int left    = row * Grid_Width + column-1;
    int right   = row * Grid_Width + column+1;
    int top     = (row-1) * Grid_Width + column;
    int bottom  = (row+1) * Grid_Width + column;
    
    retval = ( ( pop[left] + pop[right]  - 2*pop[current] ) /dX/dX +
               ( pop[top]  + pop[bottom] - 2*pop[current] ) /dY/dY );
    
    return retval;
}

////////////////////////////////////////////////////////////////////////////////
// Gradient operator definition, to calculate advective fluxes
////////////////////////////////////////////////////////////////////////////////


float d_dy(__global float* pop, int row, int column)
{
    float retval;
    
    int current=row * Grid_Width + column;
    int top=(row-1) * Grid_Width + column;
    
    retval =  (( pop[current] - pop[top] ) /dY );
    
    return retval;
}

////////////////////////////////////////////////////////////////////////////////
// Simulation kernel
////////////////////////////////////////////////////////////////////////////////

__kernel void SimulationKernel (__global float* w, __global float* n)
{
    
    float dwdt,dndt,Consumption;
	
    size_t current  = get_global_id(0);
    int    row		= floor((float)current/(float)Grid_Width);
    int    column	= current%Grid_Width;

	if (row > 0 && row < Grid_Width-1)
    {
        Consumption = w[current] * n[current] * n[current];
        
        dwdt = (a-w[current] - Consumption - V*d_dy(w, row, column));
        dndt = (Consumption - m*n[current] + D*d2_dxy2(n, row, column));
        
		w[current]=w[current]+dwdt*dT;
		n[current]=n[current]+dndt*dT;
    }
    
	// Handle Boundaries
	if(row==0)
		//do copy of first row = second last row
    {
        w[current]=w[(Grid_Height-2)*Grid_Width+column];
        n[current]=n[(Grid_Height-2)*Grid_Width+column];
    }
    
	if(row==Grid_Height-1)
		//do copy of last row = second row
    {
        w[current]=w[1*Grid_Width+column];
        n[current]=n[1*Grid_Width+column];
    }
	
} // End KlausmeierKernel

