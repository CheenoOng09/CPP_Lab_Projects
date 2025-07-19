#include <iostream>

using namespace std;

void sortFunc(int[], int); // Descending
void sortFunc(double[], int); // Descending
void sortFunc(string[], int); // Descending

template <class T>
void sortFuncTempt(T anAry[], int numElm){  // Ascending and print array
    T tempD;
    for (int i = 0; i < numElm; i++){
        for (int j = 0; j < numElm - 1; j++){
            if (anAry[j] > anAry[j + 1]){
                tempD = anAry[j + 1];
                anAry[j + 1] = anAry[j];
                anAry[j] = tempD;
            }
        }
    }
}
template <class T>
void printArray(T anAry[], int numElm){
    for (int i = 0; i < numElm; i++){
        if(i % 10 == 0)
            cout << "#";
        cout << " " << anAry[i];
        if ( (i + 1) % 10 == 0 )
            cout << endl;
    }
    if (numElm % 10 != 0)
        cout << endl;
}

int main()
{
    int numTest;
    int intList[100];
    double doubleList[100];
    string strList[100];
    int numElm;
    string dataType;
    cin >> numTest;

    for (int k = 0; k < numTest; k++){
        cin >> dataType;
        cin >> numElm;

        if (dataType == "int"){
            for (int m = 0; m < numElm; m++){
                cin >> intList[m];
            }
                sortFunc(intList, numElm);
                printArray(intList, numElm);
                sortFuncTempt(intList, numElm);
                printArray(intList, numElm);

        }
        else if (dataType == "double"){
            for (int m = 0; m < numElm; m++){
                cin >> doubleList[m];
            }
                sortFunc(doubleList, numElm);
                printArray(doubleList, numElm);
                sortFuncTempt(doubleList, numElm);
                printArray(doubleList, numElm);

        }
        else {
            for (int m = 0; m < numElm; m++){
                cin >> strList[m];
            }
                sortFunc(strList, numElm);
                printArray(strList, numElm);
                sortFuncTempt(strList, numElm);
                printArray(strList, numElm);
        }
    }
    return 0;
}

void sortFunc(int intList[], int numElm){
    int tempA;
    for (int i = 0; i < numElm; i++){
        for (int j = 0; j < numElm - 1; j++){
            if (intList[j] < intList[j + 1]){
                tempA = intList[j + 1];
                intList[j + 1] = intList[j];
                intList[j] = tempA;
            }

        }
    }
}
void sortFunc(double doubleList[], int numElm){
    double tempB;
    for (int i = 0; i < numElm; i++){
        for (int j = 0; j < numElm - 1; j++){
            if (doubleList[j] < doubleList[j + 1]){
                tempB = doubleList[j + 1];
                doubleList[j + 1] = doubleList[j];
                doubleList[j] = tempB;
            }

        }
    }
}

void sortFunc(string strList[], int numElm){
    for (int i = 0; i < numElm; i++){
        for (int j = 0; j < numElm - 1; j++){
            if (strList[j] < strList[j + 1]){
                strList[j].swap(strList[j+1]);
            }
        }
    }

}
