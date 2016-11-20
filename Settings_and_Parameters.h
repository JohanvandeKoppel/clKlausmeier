//
//  clKlausmeier model settings and parameters
//
//  Created by Johan Van de Koppel on 03-09-14.
//  Copyright (c) 2014 Johan Van de Koppel. All rights reserved.
//

// Compiler directives
#define ON              1
#define OFF             0

#define Print_All_Devices OFF

#define Device_No       1   // 0: CPU; 1: Intel 4000; 2: Nvidia GT 650M
#define ProgressBarWidth 45

#define WorkGroupSize   16
#define DomainSize      512

// Thread block size
#define Block_Size_X	(WorkGroupSize)
#define Block_Size_Y	(WorkGroupSize)

// Number of blox
/* I define the Block_Number_ensions of the matrix as product of two numbers
Makes it easier to keep them a multiple of something (16, 32) when using CUDA*/
#define Block_Number_X	(DomainSize/WorkGroupSize)
#define Block_Number_Y	(DomainSize/WorkGroupSize)

// Matrix Block_Number_ensions
// (chosen as multiples of the thread block size for simplicity)
#define Grid_Width  (Block_Size_X * Block_Number_X)			// Matrix A width
#define Grid_Height (Block_Size_Y * Block_Number_Y)			// Matrix A height
#define Grid_Size (Grid_Width*Grid_Height)                   // Grid Size

// DIVIDE_INTO(x/y) for integers, used to determine # of blocks/warps etc.
#define DIVIDE_INTO(x,y) (((x) + (y) - 1)/(y))

//      Parameters		Original value    Explanation and Units
#define a   2			//  2.00          - Non-dimensional model parameter, reflecting rainfall
#define	m	0.45   		//  0.45          - Non-dimensional model parameter, reflecting plant losses
#define D	1		    //  1             - Non-dimensional model parameter, reflecting plant spread
#define V	182.5	    //  182.5         - Non-dimensional model parameter, reflecting water flow

#define dX	0.25
#define dY	0.25

#define Time      0             // 0      - Start time of the simulation
#define dT        0.001         // 0.0001 - The timestep of the simulation
#define EndTime	  20            // 60     - The time at which the simulation ends
#define NumFrames 300           // Number of times during the simulation that the data is stored
#define	MAX_STORE (NumFrames+1) //

// Name definitions
#define PLANTS	101
#define WATER	102


