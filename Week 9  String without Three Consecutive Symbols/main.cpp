#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    int counter = 0;
    int testcase;

    cin >> testcase;
    while (counter < testcase){

        string str;
        string newStr;
        int charCounter;
        int runCount;
        int strLen;

        cin >> str;

        strLen = str.length();

        // Taking the first two letters in a string
        newStr.append(str.substr(0,2));


        if ( toupper(str[0]) == toupper(str[1]) ){
            runCount = 2;
            charCounter = 2;
        }
        else if ( toupper(str[0]) != toupper(str[1]) ){
            runCount = 1;
            charCounter = 2;
        }
        for (int i = 2, j = 2; i < strLen; i++){
            if ((runCount != 2) && ( toupper(str[i]) == toupper(str[i - 1])) ) {
                newStr[j] = str[i];
                ++j;
                ++runCount;
                ++charCounter;
            }
            else if ( toupper(str[i]) != toupper(str[i - 1]) ){
                newStr[j] = str[i];
                ++j;
                runCount = 1;
                ++charCounter;
            }
        }
        for (int i = 0; i < charCounter; i++){
            cout << newStr[i];
        }
        cout << endl;
    ++counter;
    }
}
