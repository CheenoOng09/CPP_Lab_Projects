#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    double userWeight;      // Variable of the weight from the user input
    double userHeight;      // Variable of the height from the user input
    double userBMI;         // Variable of the calculated BMI value of weight and height from the user
    int headCount = 0;      // Variable of the Total Headcount for each data sets that has been successfully processed
    int disBMI[10] = {0};   // Declared an integer array for distribution of BMI levels of 0 - 9
    string userBMIlevel[10] = {"USL","HSUW","SUW","UW","NW","OW","OB","SOB","HSOB","ULL"};


    while ((userWeight > 0) || (userHeight > 0)){                           //The beginning of while loop that will terminate if the user input is smaller than 0
    start:
    cin >> userWeight >> userHeight;
    if ((userWeight > 0 && userWeight <= 20) || (userWeight >= 200))            // This is how we determine if the weight from the user input is invalid
        goto start;                                                                 // We use goto statement to ignore invalid user input
    else if ((userHeight > 0 && userHeight < 0.9) || (userHeight > 2.5))        // This is how we determine if the height from the user input is invalid
        goto start;                                                                 // We use goto statement to ignore invalid user input
    userBMI = round(userWeight / (userHeight * userHeight) * 10) / 10.0;    // The calculation for the BMI value

    int switchName;

    if (userBMI < 10)
        switchName = 1;
    else if(userBMI >= 10 && userBMI <= 15)
        switchName = 2;
    else if(userBMI > 15 && userBMI <= 16)
        switchName = 3;
    else if(userBMI > 16 && userBMI < 18.5)
        switchName = 4;
    else if(userBMI >= 18.5 && userBMI <= 25)
        switchName = 5;
    else if(userBMI > 25 && userBMI <= 40)
        switchName = 6;
    else if(userBMI > 40 && userBMI <= 50)
        switchName = 7;
    else if(userBMI > 50 && userBMI <= 60)
        switchName = 8;
    else if(userBMI > 60 && userBMI <= 70)
        switchName = 9;
    else if(userBMI > 70)
        switchName = 10;

    switch (switchName){
        case 1:
            disBMI[0] = disBMI[0] + 1;
            headCount = headCount + 1;
            break;
        case 2:
            disBMI[1] = disBMI[1] + 1;
            headCount = headCount + 1;
            break;
        case 3:
            disBMI[2] = disBMI[2] + 1;
            headCount = headCount + 1;
            break;
        case 4:
            disBMI[3] = disBMI[3] + 1;
            headCount = headCount + 1;
            break;
        case 5:
            disBMI[4] = disBMI[4] + 1;
            headCount = headCount + 1;
            break;
        case 6:
            disBMI[5] = disBMI[5] + 1;
            headCount = headCount + 1;
            break;
        case 7:
            disBMI[6] = disBMI[6] + 1;
            headCount = headCount + 1;
            break;
        case 8:
            disBMI[7] = disBMI[7] + 1;
            headCount = headCount + 1;
            break;
        case 9:
            disBMI[8] = disBMI[8] + 1;
            headCount = headCount + 1;
            break;
        case 10:
            disBMI[9] = disBMI[9] + 1;
            headCount = headCount + 1;
            break;
    }
    switchName = -1;
    } // End of WHILE loop





    int max = disBMI[0];                                                         // Declared a variable of int max which i can use to find the highest number in the array
    for (int i = 0; i < 10; i++){                                                // Beginning 1st For loop for finding the highest number
        if (disBMI[i] > max){
            max = disBMI[i];
        }
    }                                                                           // End of 1st FOR Loop
    string disLevel = userBMIlevel[0];
    int maxB = disBMI[0];                                                       // Beginning of 2nd For Loop for finding the highest BMI level name
    for (int i = 0; i < 10; i++){
        if (disBMI[i] > maxB){
            disLevel = userBMIlevel[i];
        }
    }                                                                           // End of 2nd For Loop




    cout << "#  USL  HSUW  SUW  UW  NW  OW  OB  SOB  HSOB  ULL" << endl;
    cout << "#  " << setw(3) << disBMI[0] << setw(6) << disBMI[1] << setw(5) << disBMI[2] << setw(4) << disBMI[3] << setw(4) << disBMI[4] << setw(4) << disBMI[5] << setw(4) << disBMI[6] << setw(5) << disBMI[7] << setw(6) << disBMI[8] << setw(5) << disBMI[9] << endl;
    cout << "# Levels with maximum count: " << max << endl;
    cout << "# Level = " << disLevel <<endl;
    cout << "# Head Count = " << headCount << endl;

    return 0;
}






