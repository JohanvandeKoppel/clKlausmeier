//
//  Initial_values.cpp
//  clMussels
//
//  Created by Johan Van de Koppel on 09/09/15.
//  Copyright (c) 2015 Johan Van de Koppel. All rights reserved.
//

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
// Allocates a matrix with random float entries
////////////////////////////////////////////////////////////////////////////////

void randomInit (float* data, int x_siz, int y_siz, int type)
{
    int i,j;
    for(i=0;i<y_siz;i++)
    {
        for(j=0;j<x_siz;j++)
        {
           //for every other element find the correct initial
            //value using the conditions below
            if(type==PLANTS)
            {
                //printf(" %4.5f ",(rand() / (float)RAND_MAX));
                if((rand() / (float)RAND_MAX)<0.10f)
                    data[i*y_siz+j] = (float)10.0f;
                else
                    data[i*y_siz+j] = (float)0.0f;
            }
            else if(type==WATER)
                data[i*y_siz+j]=2.0f;
        }
    }
} // End randomInit

////////////////////////////////////////////////////////////////////////////////
// Prints the model name and additional info
////////////////////////////////////////////////////////////////////////////////

void Print_Label()
{
    //system("clear");
    printf("\n");
    printf(" * * * * * * * * * * * * * * * * * * * * * * * * * * * * * \n");
    printf(" * Arid land Patterns                                    * \n");
    printf(" * OpenCL implementation : Johan van de Koppel, 2014     * \n");
    printf(" * Following a model by Klausmeier, Science 1999         * \n");
    printf(" * * * * * * * * * * * * * * * * * * * * * * * * * * * * * \n\n");
    
} // Print_Label
