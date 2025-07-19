#include <iostream>

using namespace std;

int main()
{
    int testcase;
    int counter = 0;

    cin >> testcase;
    while (counter < testcase){

        int n;
        bool found = false;
        int largestInt;
        int ThirdLargeInt;
        int temporaryNum;
        int index;

        cin >> n;

        int number[n];
        int numberCopy[n];

        for (int i = 0; i < n; i++){
            cin >> number[i];
            numberCopy[i] = number[i];
        }

        for (int i = 0; i < n && !found; i++){
            if (n == 1){
                ThirdLargeInt = number[i];
                index = i + 1;
                found = true;
                break;
            }
            else if (n == 2){
                if (number[i] > number[i + 1]){
                    ThirdLargeInt = number[i + 1];
                    index = i + 2;
                    found = true;
                    break;
                }
                else if (number[i] < number[i + 1]){
                    ThirdLargeInt = number[i];
                    index = i + 1;
                    found = true;
                    break;
                }
                else if (number[i] == number[i + 1]){
                    ThirdLargeInt = number[i + 1];
                    index = i + 2;
                    found = true;
                    break;
                }
            }
            else if (n > 2){
                // SORT THE ARRAY FROM LOWEST TO HIGHEST
                int temporary;
                for (int j = 0; j < n - 1; j++){
                    if (number[j] > number[j + 1]){
                        temporary = number[j + 1];
                        number[j + 1] = number[j];
                        number[j] = temporary;
                    }
                }
                // FINDING THE LARGEST NUMBER IN THE ARRAY
                largestInt = number[0];
                for (int j = 0; j < n; j++){
                    if (largestInt < number[j]){
                        largestInt = number[j];
                    }
                }
                // FIND THE SMALLERST NUMBER IN THE ARRAY
                int smallestInt = number[0];
                for (int j = 0; j < n; j++){
                    if (smallestInt > number[j]){
                        smallestInt = number[j];
                    }
                }
                ThirdLargeInt = number[0];
                temporaryNum = number[0];
                for (int j = n - 1, counterInt = 2, b = 0; j >= 0 && !found; j--){
                    if (counterInt == 0){
                        found = true;
                        break;
                    }

                    else if ( (b == 0) && (number[j] != largestInt) ){
                        ThirdLargeInt = number[j];
                        temporaryNum = number[j];
                        counterInt = counterInt - 1;
                        b = 1;
                    }
                    else if ( (b == 1) && (number[j] != temporaryNum) && (number[j] != largestInt) ){
                        ThirdLargeInt = number[j];
                        counterInt = counterInt - 1;
                        b = 0;
                    }
                }
                found = false;
                //Printing out the index in the array.
                for (int j = n; j > 0 && !found; j--){
                    if (ThirdLargeInt == numberCopy[j - 1]){
                        index = j;
                        found = true;
                        break;
                    }
                }
                found = false;

            } // END OF ELSE IF (N > 2)
        } // END OF OUTER FOR LOOP

    cout << ThirdLargeInt << " " << index << endl;
    found = false;
    counter = counter + 1;

    }
}
