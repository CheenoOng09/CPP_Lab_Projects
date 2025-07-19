#include <iostream>

using namespace std;

int insertionSort(int[], int, int&, int&);
int ThirdLargestInt(int [], int, int&);

int main()
{
    int testCase;
    int counter = 0;

    cin >> testCase;
    while (counter < testCase){
        int ThirdLargeInt;
        int numMoves = 0;
        int n;
        int indeX;
        cin >> n;

        int Numbers[99];

        for (int i = 0; i < n; i++){
            cin >> Numbers[i];
        }
        ThirdLargestInt(Numbers, n, ThirdLargeInt);
        insertionSort(Numbers, n, indeX, numMoves);


        cout << "# " << ThirdLargeInt << " " << indeX << " " << numMoves << endl;
        cout << "# ";
        for (int i = 0; i < n; i++){
            cout << Numbers[i] << " ";
        }
        cout << endl;
    counter++;
    }
}

int insertionSort(int Numbers[], int n, int& indeX, int& numMoves){
    int CopyNumbers[99];
    int temporaryNum;
    int ThirdLargeInt;
    bool found = false;

    for (int i = 0; i < n; i++){
        CopyNumbers[i] = Numbers[i];
    }


    for (int i = 0; i < n && !found; i++){
        if (n == 1){
            ThirdLargeInt = Numbers[i];
            indeX = i;
            found = true;
            break;
        }
        else if (n == 2){
            if (Numbers[i] > Numbers[i + 1]){
                ThirdLargeInt = Numbers[i + 1];
                indeX = i;
                found = true;
                break;
            }
            else if (Numbers[i] < Numbers[i + 1]){
                ThirdLargeInt = Numbers[i];
                indeX = i;
                found = true;
                break;
            }
            else if (Numbers[i] == Numbers[i + 1]){
                ThirdLargeInt = Numbers[i + 1];
                indeX = i + 1;
                found = true;
                break;
            }
        }
        else if (n > 2){
            // SORT THE ARRAY FROM HIGHEST TO LOWEST
            int index;
            int value;
            int k;
            int trigger = 1;
            for (k = 1; k < n; k++){
                value = Numbers[k];
                index = k;
                while (index > 0 && Numbers[index - 1] < value){
                    Numbers[index] = Numbers[index - 1]; //SHIFT TO THE RIGHT
                    index = index - 1; // MOVE TO THE NEXT INDEX TO THE LEFT and ACTS AS A COUNTER FOR THE WHILE LOOP CONDITION
                    ++numMoves;
                    trigger = 0; // THIS MEANS THE WHILE LOOP HAS BEEN TRIGGERED
                }
                if (trigger == 0){
                    Numbers[index] = value;
                    ++numMoves;
                }
                trigger = 1;
            }

            // FINDING THE LARGEST NUMBER IN THE ARRAY
            int largestInt = Numbers[0];
            for (int j = 0; j < n; j++){
                if (largestInt < Numbers[j]){
                    largestInt = Numbers[j];
                }
            }
            ThirdLargeInt = Numbers[0];
            temporaryNum = Numbers[0];
            for (int j = 0, counterInt = 2, b = 0; j < n && !found; j++){
                if (counterInt == 0){
                    found = true;
                    break;
                }
                else if ( (b == 0) && (Numbers[j] != largestInt) ){
                    ThirdLargeInt = Numbers[j];
                    temporaryNum = Numbers[j];
                    counterInt = counterInt - 1;
                    b = 1;
                }
                else if ( (b == 1) && (Numbers[j] != temporaryNum) && (Numbers[j] != largestInt) ){
                    ThirdLargeInt = Numbers[j];
                    counterInt = counterInt - 1;
                    b = 0;
                }
            }
            found = false;

            //Printing out the index in the array.
            for (int j = n; j > 0 && !found; j--){
                if (ThirdLargeInt == CopyNumbers[j]){
                    indeX = j;
                    found = true;
                    break;
                }
            }
            found = false;
        }
    }
    return 0;
}

int ThirdLargestInt(int Numbers[], int n, int& ThirdLargeInt){
    int CopyNumbers[99];

    bool found = false;

    for (int i = 0; i < n; i ++){
        CopyNumbers[i] = Numbers[i];
    }
    for (int i = 0; i < n && !found; i++){
        if (n == 1){
            ThirdLargeInt = Numbers[i];
            found = true;
            break;
        }
        else if (n == 2){
            if (Numbers[i] > Numbers[i + 1]){
                ThirdLargeInt = Numbers[i + 1];
                found = true;
                break;
            }
            else if (Numbers[i] < Numbers[i + 1]){
                ThirdLargeInt = Numbers[i];
                found = true;
                break;
            }
            else if (Numbers[i] == Numbers[i + 1]){
                ThirdLargeInt = Numbers[i + 1];
                found = true;
                break;
            }
        }
        else if (n > 2){
            // SORT THE ARRAY FROM LOWEST TO HIGHEST
            int tempNum;
            for (int j = 0; j < n - 1; j++){
                if (Numbers[j] < Numbers[j + 1]){
                    tempNum = Numbers[j + 1];
                    Numbers[j + 1] = Numbers[j];
                    Numbers[j] = tempNum;
                }
            }
            // FINDING THE LARGEST NUMBER IN THE ARRAY
            int largestInt = Numbers[0];
            for (int j = 0; j < n; j++){
                if (largestInt < Numbers[j]){
                    largestInt = Numbers[j];
                }
            }
            ThirdLargeInt = Numbers[0];
            int temporaryNum = Numbers[0];
            for (int j = 0, counterInt = 2, b = 0; j < n && !found; j++){
                if (counterInt == 0){
                    found = true;
                    break;
                }
                else if ( (b == 0) && (Numbers[j] != largestInt) ){
                    ThirdLargeInt = Numbers[j];
                    temporaryNum = Numbers[j];
                    counterInt = counterInt - 1;
                    b = 1;
                }
                else if ( (b == 1) && (Numbers[j] != temporaryNum) && (Numbers[j] != largestInt) ){
                    ThirdLargeInt = Numbers[j];
                    counterInt = counterInt - 1;
                    b = 0;
                }
            }
            found = false;
        }
    }
    for (int i = 0; i < n; i ++){
        Numbers[i] = CopyNumbers[i];
    }
    return 0;
}
