#include <iostream>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <string>
#include <cstdlib>
#include <limits>


using namespace std;

void createRecord(fstream&, string, string, double);
bool findCopy(fstream &fptr, string, string);

void displayFile(fstream &fptr){
    string str1;
    string str2;
    double balance;
    int numAct = 0;
    time_t transTime;
    fptr.clear();
    fptr.seekg(0);
    while(fptr >> str1 >> str2 >> balance >> transTime){
        cout << setw(15) << str1 << " " << setw(15) << str2 << " " << setw(7) << balance << "    " << ctime(&transTime);
        numAct++;
    }
    cout << "Number of records in the file: " << numAct << endl;
}

int main()
{
    fstream clientFile;
    fstream tempFile;
    string firstName;
    string lastName;
    double actBalance;
    // const char *fileName = "clientFile.txt";
    const string fileN = "clientFile.txt";
    // exit program if unable to create file
    clientFile.open(fileN, ios::in);

    if (clientFile){
        cout << "Existing file content" << endl;
        displayFile(clientFile); // Created function
    }
    else{
        cout << "Creating a new file:" << endl;
        clientFile.open(fileN, ios::out);
    }
    clientFile.close();
    clientFile.open(fileN, ios::in | ios::out);
    cout << "Enter first name, last name and balance" << endl;
    while (cin >> firstName >> lastName >> actBalance){
        createRecord(clientFile, firstName, lastName, actBalance);
    }
    displayFile(clientFile);
    clientFile.close();
}

void createRecord (fstream &fptr, string firstN, string lastN, double actBal){

    if (findCopy(fptr, firstN, lastN)){
        return;
    }
    time_t transTime;
    time(&transTime);
    fptr.clear();
    fptr.seekp(0, ios::end);
    fptr << firstN << ' ' << lastN << ' ' << actBal << ' ' << transTime << endl;
}

bool findCopy(fstream &fptr, string firstN, string lastN){
    string str1;
    string str2;
    fptr.clear();
    fptr.seekg(0);
    while (fptr >> str1 >> str2){
        if (firstN == str1 && lastN == str2){
            return true;
        }
        fptr.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return false;
}
