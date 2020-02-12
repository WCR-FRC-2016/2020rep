/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "VisionerCornerFinder.h"
#include "Robot.h"

VisionerCornerFinder::VisionerCornerFinder() {

}
double VisionerCornerFinder::LostandFound(std::vector<double>  xArray, std::vector<double> yArray){
    std::vector<double> copyYArray = yArray;
    int maxIndex = 0;
    int maxIndexi[4];
    for(int i = 0; i < 4; i++){
        maxIndex = 0;
        for(int j = 0; j < copyYArray.size(); j++){
            if (copyYArray[j] < copyYArray[maxIndex])
            {
                maxIndex = j;
            }
        }
        maxIndexi[i] = maxIndex;
        copyYArray[maxIndex] = 5492;
    }
    int maxXIndex = 0;
    int minXIndex = 0;
    for(int k = 0; k < 4; k++){
        if(xArray[maxIndexi[k]] > xArray[maxXIndex])
        {
            maxXIndex = k;
        }
        else if(xArray[maxIndexi[k]] < xArray[minXIndex])
        {
            minXIndex = k;
        }
    }
    printf("Rightval=%f\n",yArray[maxXIndex]);
    printf("Leftval=%f\n",yArray[minXIndex]);
    return (yArray[maxXIndex] - yArray[minXIndex]);
}


