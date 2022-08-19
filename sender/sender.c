
#include <stdio.h>
#include "sender.h"

void ReadBMSParametersFromInputFile(float* Temp, float* SOC)
{
    float Temperature, StateOfCharge;
    FILE * Inputfile= fopen("./sender/sender.txt","r");  
    if (Inputfile!=NULL) 
    {
        for(int i=0;fscanf(Inputfile, "%f\t%f\n", &Temperature,&StateOfCharge)!=EOF ;i++)
        {
            *(Temp+i) = Temperature;
            *(SOC+i)  = StateOfCharge;
           
        }
    }
    fclose(Inputfile);  
}

void PrintBMSParametersOnConsole(float* Temp, float* SOC)
{
   printf("Temperature\t   StateOfCharge\n");
  for (int i=0; i<TotalSamples; i++)
  {
    printf("%.2f deg C \t    %.2f",  *(Temp+i),*(SOC+i));
  }
}

void SendBMSParameters()
{
  float Temperature[TotalSamples] = {0};
  float StateOfCharge[TotalSamples]= {0};
  ReadBMSParametersFromInputFile(Temperature, StateOfCharge);
  PrintBMSParametersOnConsole(Temperature, StateOfCharge);
}
