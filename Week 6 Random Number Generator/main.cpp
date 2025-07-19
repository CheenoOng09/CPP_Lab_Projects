#include <iostream>
#include <string>
#include <cmath>

using namespace std;

unsigned long long RandomNumber[10000000];

int main()
{
    int counter = 0;
    int testCases;

    cout << "Number of test cases: ";
    cin >> testCases;
    while (counter < testCases){

        int numOfbits;
        int numOfPRN;
        string seedLSFR;
        int MaxCombinations;
        int ListOfUniqueRandNums = 1;
        int NumOfNoOccurence;
        bool found = false;
        double MaxNumOccurence = 1;
        int MinNumOccurence = 0;
        double AverageNumOccurence;

        cout << "Length of LFSR: ";
        cin >> numOfbits;

        int tapBits[numOfbits];
        for (int i = 0; i < numOfbits; i++){
            tapBits[i] = {0};
        }
        int tapBitsCount = 0;
        cout << "Tap bits: ";
        for (int i = 0; ; i++){
            cin >> tapBits[i];
            if (tapBits[i] != 0){
                ++tapBitsCount;
            }
            else if (tapBits[i] == 0){
                break;
            }
        }
        cout << "Seed for LFSR: ";
        cin >> seedLSFR;

        cout << "Number of pseudo random numbers needed to be generated: ";
        cin >> numOfPRN;

        for (int o = 0; o < numOfPRN; o++){
            RandomNumber[o] = {0};
        }


        // FINDING THE XOR VALUE:
        char XORvalue;
        for (int j = 0; j < numOfPRN; j++){ //START OF FOR LOOP
            for (int i = tapBitsCount - 1; i > 0; i--){
                if (i == tapBitsCount - 1 && seedLSFR[tapBits[i] - 1] != seedLSFR[tapBits[i - 1] - 1]){
                    XORvalue = '1';
                }
                else if (i == tapBitsCount - 1 && seedLSFR[tapBits[i] - 1] == seedLSFR[tapBits[i - 1] - 1]){
                    XORvalue = '0';
                }
                else if (i != tapBitsCount - 1 && XORvalue != seedLSFR[tapBits[i - 1] - 1]){
                    XORvalue = '1';
                }
                else if (i != tapBitsCount - 1 && XORvalue == seedLSFR[tapBits[i - 1] - 1]){
                    XORvalue = '0';
                }
            }

            // SHIFTING THE STRING TO THE RIGHT:
	        for (int i = numOfbits - 1; i > 0; i--){
		        seedLSFR[i] = seedLSFR[i - 1];
	        }

            // INSERTING THE XOR VALUE TO INDEX 0:
	        seedLSFR[0] = XORvalue;

	        // CONVERTING THE BINARY STRING INTO AN INTEGER AND THEN STORING IT IN A LARGE SIZE INTEGER ARRAY:
	        RandomNumber[j] = stoull(string(seedLSFR));

        } // END OF FOR LOOP

        // FINDING THE AMOUNT OF ORIGINAL BIT PATTERNS THAT SHOWED UP IN THE PSEUDO RANDOM GENERATOR DEPENDING ON THE SEED LFSR:
        for (int m = 0; m < numOfPRN - 1 && !found; m++ ){
            for (int n = 1; n < numOfPRN && !found; n++){
                if (RandomNumber[m] != RandomNumber[m + n]){
                    ++ListOfUniqueRandNums;
                }
                else if (RandomNumber[m] == RandomNumber[m + n]){
                    found = true;
                    break;
                }
            }
        }

        // FINDING THE MAXIMUM NUMBER OF OCCURENCE:
        for (int m = 1; m < numOfPRN - 1; m++){
            if (RandomNumber[0] == RandomNumber[m]){
                ++MaxNumOccurence;
            }
        }

        // FINDING THE MINIMUM NUMBER OF OCCURENCE:
        int MinNumOccurenceArray[ListOfUniqueRandNums];

        for (int i = 0; i < ListOfUniqueRandNums; i++){
            MinNumOccurenceArray[i] = {0};
        }
        for (int i = 0; i < ListOfUniqueRandNums; i++){
            for (int m = 0; m < numOfPRN; m++){
                if (RandomNumber[i] == RandomNumber[m]){
                    MinNumOccurenceArray[i] += 1;
                }
            }
        }
        MinNumOccurence = MinNumOccurenceArray[0];
        for (int i = 0; i < ListOfUniqueRandNums; i++){
            if (MinNumOccurence > MinNumOccurenceArray[i]){
                MinNumOccurence = MinNumOccurenceArray[i];
            }
        }

        // FORMULA FOR FINDING THE MAXIMUM NUMBER OF POSSIBLE RANDOM BINARY COMBINATIONS DEPENDING ON THE BIT LENGTH:
        MaxCombinations = (pow(2, numOfbits));

        // CALCULATING THE AVERAGE NUMBER OF OCCURENCE:
        AverageNumOccurence = ((ListOfUniqueRandNums * MaxNumOccurence)/ MaxCombinations);

        // CALCULATION FOR FINDING THE NUMBER OF NO OCCURENCE:
        NumOfNoOccurence = MaxCombinations - ListOfUniqueRandNums;

        cout << "# Average number of occurences per pseudo random number: " << AverageNumOccurence << endl;
        cout << "# Maximum number of occurences: " << MaxNumOccurence << endl;
        cout << "# Minimum number of occurences: " << MinNumOccurence << endl;
        cout << "# Number of no occurences: " << NumOfNoOccurence << endl;

        ++counter;
    }
}
