#define CATCH_CONFIG_MAIN 

#include "test/catch.hpp"
#include "sender/sender.h"

TEST_CASE("Check whether reading and passing of the data is successful") 
{
  float Temperature[TotalSamples] = {0};
  float StateOfCharge[TotalSamples] = {0};
  float ExpectedOutput[3][2] = {{2,5}, {5,5}, {10,5}};
  
  ReadBMSParametersFromInputFile(Temperature,StateOfCharge);
  int j= 0, i= 0;
  for(i=0;i<2;i++)
  {
    REQUIRE(Temperature[j] == ExpectedOutput[i][0]);
    REQUIRE(StateOfCharge[j] == ExpectedOutput[i][1]);
    j++;
  }
    SendBMSParameters();
}
