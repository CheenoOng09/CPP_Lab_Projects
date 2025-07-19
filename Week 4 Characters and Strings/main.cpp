#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    string userString;
    int userInputLength;
    int runLength = 1;
    int numOfruns;
    int longestRunLength;
    int highestRun;
    int k;
    int testCases;
    int counter = 0;

    cin >> testCases;

    while (counter < testCases){

        cin >> userString;

        userInputLength = userString.length();

        numOfruns = 1;    // Whatever the string input will be, the run will always have a default value of 1

        for (int i = 0; i < userInputLength - 1; i++){  // This is the first step. Finding the number of runs.
            if (((userString[i] - userString[i + 1]) != 0) && ((abs(userString[i] - userString[i + 1]) != 32))){
                numOfruns = numOfruns + 1;
            }
        }

        int disRunLength[numOfruns];            // Pre-initialize the default value of run length by 1 per run.
        for (int i = 0; i < numOfruns; ++i){
            disRunLength[i] = 1;
        }

        k = 0;                                              // For finding the value of length of run for each whole run
        for (int i = 0; i < userInputLength - 1; ++i){
            if ((abs(userString[i] - userString[i + 1]) == 32) || (userString[i] - userString[i + 1] == 0)){
                disRunLength[k] = disRunLength[k] + 1;
            }
            else if ((abs(userString[i] - userString[i + 1]) != 32) || (userString[i] - userString[i + 1] != 0)){
                k = k + 1;
            }
        }

        longestRunLength = disRunLength[0];                 //Find the highest run length
        for (int i = 0; i < numOfruns; ++i){
            if (disRunLength[i] >= longestRunLength){
                longestRunLength = disRunLength[i];
            }
        }

        highestRun = 0;                                     //For counting the number of longest run
        for (int i = 0; i < numOfruns; ++i){
            if (longestRunLength != disRunLength[i]){
            }
            else if (longestRunLength == disRunLength[i]){
                highestRun = highestRun + 1;
            }
        }

        cout << "# Number of runs= " << numOfruns << endl;
        cout << "# Longest run lenght= " << longestRunLength << endl;
        cout << "# Number of longest runs= " << highestRun << endl;

        counter = counter + 1;
    }
}
