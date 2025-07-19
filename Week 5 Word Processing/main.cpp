#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    string sentence = "cout << \"Total number of words: \" << initVowelNum + nonVowelNum + firstCharNum[26] + firstCharNum[27] << endl; This is a java program to implement monoalphabetic cypher. In cryptography, a substitution of cipher is a method of encoding by which units of plaintext are replaced with ciphertext, according to a regular system; the \"units\" may be single letters (the most common), pairs of letters, triplets of letters, mixtures of the above, and so forth. The receiver deciphers the text by performing an inverse substitution. 134Abc, 7sdjk, wekjf0, 23i5, Ab AB ab aB cD Ef gH IJ KL Mn op Qr St UV wx YZ Y Za ZA za zA Ab bc cd dE ef Fg Gh hi IJ kl LM mN No Op pq Qr Rs St TU uV vw Wx Xy YZ Za For example, eve, ada, Noun, rear, Sears, pop, kick, Sos, etc. are words whose first letter and last letter are the same.";
    int length;
    int wordCount;
    int WordsWithVowelFirst;

    length = sentence.length();
    wordCount = 1;

    int arrayL[16];
    for (int i = 0; i < 16; i++){
        arrayL[i] = {0};
    }

    for (int i = 0; i < length; i++){
        if (sentence[i] == ' ' )
            wordCount = wordCount + 1;
    }
    cout << "Word Count: " << wordCount << endl;
    cout << "Sentence Length: " << length << endl;


    int wordsArr[wordCount];
    for (int i = 0; i < wordCount; i++){
        wordsArr[i] = {0};
    }

    for (int i = 0, k = 0; i < length; i++){
        if (sentence[i] != ' '){
            wordsArr[k] = wordsArr[k] + 1;
        }
        else if (sentence[i] == ' '){
            k = k + 1;
        }
    }
    for(int i = 0; i < wordCount; i++){
        switch(wordsArr[i]){
        case 0:
            arrayL[0] = arrayL[0] + 1;
            break;
        case 1:
            arrayL[1] = arrayL[1] + 1;
            break;
        case 2:
            arrayL[2] = arrayL[2] + 1;
            break;
        case 3:
            arrayL[3] = arrayL[3] + 1;
            break;
        case 4:
            arrayL[4] = arrayL[4] + 1;
            break;
        case 5:
             arrayL[5] = arrayL[5] + 1;
            break;
        case 6:
            arrayL[6] = arrayL[6] + 1;
            break;
        case 7:
            arrayL[7] = arrayL[7] + 1;
            break;
        case 8:
            arrayL[8] = arrayL[8] + 1;
            break;
        case 9:
            arrayL[9] = arrayL[9] + 1;
            break;
        case 10:
            arrayL[10] = arrayL[10] + 1;
            break;
        case 11:
            arrayL[11] = arrayL[11] + 1;
            break;
        case 12:
            arrayL[12] = arrayL[12] + 1;
            break;
        case 13:
            arrayL[13] = arrayL[13] + 1;
            break;
        case 14:
            arrayL[14] = arrayL[14] + 1;
            break;
        default:
            arrayL[15] = arrayL[15] + 1;
            break;
        }
    }
//-------------------------------------------------------------------//
    int upperCase[26] = {0};// = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    int lowerCase[26] = {0};// = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    for (int i = 0, j = 65, k = 97; i <= 26, j <= 90, k <= 122; i++, j++, k++){
        lowerCase[i] = lowerCase[i] + k;
        upperCase[i] = upperCase[i] + j;
    }

    int DisWordsWithLetter[wordCount];
    for (int i = 0; i < wordCount; i++){
        DisWordsWithLetter[i] = {0};
    }

    bool oneTime = false;
    for (int i = 0; i < length; i++){
        for (int j = 0, l; j < 26 && !oneTime; j++){
            if ((sentence[i] == upperCase[j]) || (sentence[i] == lowerCase[j])){
                DisWordsWithLetter[l] = 1;
                oneTime = true;
            }
            else if (sentence[i] == ' '){
                l = l + 1;
                oneTime = true;
            }
        }
    oneTime = false;
    }
    int wordsWithletter;
    for (int i = 0; i < wordCount; i++){
        wordsWithletter = wordsWithletter + DisWordsWithLetter[i];
    }
//-------------------------------------------------------------------//
    WordsWithVowelFirst = 0;
    int listOfnumbers[10] = {'0','1','2','3','4','5','6','7','8','9'};
    for (int i = 0; i < length; i ++){
        switch(sentence[i]){
        case 'a':
        case 'A':
            //cout << "Index " << i << " Case A" << endl;
            if (i == 0){
                //cout << "This is probably a single letter vowel that started in the string so variable \"WordsWithVowelFirst\" has been successfully incremented" << endl;
                WordsWithVowelFirst += 1;
                break;
            }
            else if ((i != 0) && (sentence[i + 1] == ' ') && (sentence[i - 1] == ' ')){
                //cout << "There are two spaces around index " << i << " so variable \"WordsWithVowelFirst\" has been successfully incremented" << endl;
                WordsWithVowelFirst += 1;
                break;
            }
            else if ((i != 0) && (sentence [i - 1] == ' ') && (sentence[i + 1] != ' ')){
                //cout << "There is a space before a vowel in index " << i << " and there is a letter after a vowel in index " << i << " so variable \"WordsWithVowelFirst\" has been successfully incremented" << endl;
                WordsWithVowelFirst += 1;
                break;
            }
            else if ((i != 0) && (sentence[i + 1] != ' ') && (sentence[i - 1] != ' ')){
                for (int j = 0, k = 1; j < 10 && !oneTime;j++){
                    //cout << "Iteration j = " << j << " and k = i - " << k << ". " << endl;
                    if (sentence[i - k] == listOfnumbers[j]){
                        //cout << "Case I is in index[" << i << "] is surrounded by numbers.. will keep checking if there's any letters before I can find a space" << endl;
                        k = k + 1;
                        j = 0 - 1;
                    }
                    else if (sentence [i - k] == ' '){
                        //cout << "Case I: This vowel in this index (index [" << i << "]) is the the first vowel in this word. So variable \"WordsWithVowelFirst\" has been successfully incremented." << endl;
                        WordsWithVowelFirst += 1;
                        oneTime = true;
                        break;
                    }
                    else if ((sentence [i - k] != ' ') || (sentence[i - k] != listOfnumbers[j])){
                    }
                    else{
                        k = k + 1;
                    }
                oneTime = false;
                }
            oneTime = false;
            }
            else if ((i != 0) && (sentence [i + 1] == ' ') && (sentence [i - 1] != ' ')){
                //cout << "This vowel in the index " << i << " is not the first letter of this word. so variable \"WordsWithVowelFirst\" has failed to increment." << endl;
                break;
            }
            break;
        case 'e':
        case 'E':
            //cout << "Index " << i << " Case E" << endl;
            if (i == 0){
                //cout << "This is probably a single letter vowel that started in the string so variable \"WordsWithVowelFirst\" has been successfully incremented" << endl;
                WordsWithVowelFirst += 1;
                break;
            }
            else if ((i != 0) && (sentence[i + 1] == ' ') && (sentence[i - 1] == ' ')){
                //cout << "There are two spaces around index " << i << " so variable \"WordsWithVowelFirst\" has been successfully incremented" << endl;
                WordsWithVowelFirst += 1;
                break;
            }
            else if ((i != 0) && (sentence [i - 1] == ' ') && (sentence[i + 1] != ' ')){
                //cout << "There is a space before a vowel in index " << i << " and there is a letter after a vowel in index " << i << " so variable \"WordsWithVowelFirst\" has been successfully incremented" << endl;
                WordsWithVowelFirst += 1;
                break;
            }
            else if ((i != 0) && (sentence[i + 1] != ' ') && (sentence[i - 1] != ' ')){
                for (int j = 0, k = 1; j < 10 && !oneTime;j++){
                    //cout << "Iteration j = " << j << " and k = i - " << k << ". " << endl;
                    if (sentence[i - k] == listOfnumbers[j]){
                        //cout << "Case I is in index[" << i << "] is surrounded by numbers.. will keep checking if there's any letters before I can find a space" << endl;
                        k = k + 1;
                        j = 0 - 1;
                    }
                    else if (sentence [i - k] == ' '){
                        //cout << "Case I: This vowel in this index (index [" << i << "]) is the the first vowel in this word. So variable \"WordsWithVowelFirst\" has been successfully incremented." << endl;
                        WordsWithVowelFirst += 1;
                        oneTime = true;
                        break;
                    }
                    else if ((sentence [i - k] != ' ') || (sentence[i - k] != listOfnumbers[j])){
                    }
                    else{
                        k = k + 1;
                    }
                oneTime = false;
                }
            oneTime = false;
            }
            else if ((i != 0) && (sentence [i + 1] == ' ') && (sentence [i - 1] != ' ')){
                //cout << "This vowel in the index " << i << " is not the first letter of this word. so variable \"WordsWithVowelFirst\" has failed to increment." << endl;
                break;
            }
            break;
        case 'i':
        case 'I':
            //cout << "Index " << i << " Case I" << endl;
            if (i == 0){
                //cout << "This is probably a single letter vowel that started in the string so variable \"WordsWithVowelFirst\" has been successfully incremented" << endl;
                WordsWithVowelFirst += 1;
                break;
            }
            else if ((i != 0) && (sentence[i + 1] == ' ') && (sentence[i - 1] == ' ')){
                //cout << "There are two spaces around index " << i << " so variable \"WordsWithVowelFirst\" has been successfully incremented" << endl;
                WordsWithVowelFirst += 1;
                break;
            }
            else if ((i != 0) && (sentence [i - 1] == ' ') && (sentence[i + 1] != ' ')){
                //cout << "There is a space before a vowel in index " << i << " and there is a letter after a vowel in index " << i << " so variable \"WordsWithVowelFirst\" has been successfully incremented" << endl;
                WordsWithVowelFirst += 1;
                break;
            }
            else if ((i != 0) && (sentence[i + 1] != ' ') && (sentence[i - 1] != ' ')){
                for (int j = 0, k = 1; j < 10 && !oneTime;j++){
                    //cout << "Iteration j = " << j << " and k = i - " << k << ". " << endl;
                    if (sentence[i - k] == listOfnumbers[j]){
                        //cout << "Case I is in index[" << i << "] is surrounded by numbers.. will keep checking if there's any letters before I can find a space" << endl;
                        k = k + 1;
                        j = 0 - 1;
                    }
                    else if (sentence [i - k] == ' '){
                        //cout << "Case I: This vowel in this index (index [" << i << "]) is the the first vowel in this word. So variable \"WordsWithVowelFirst\" has been successfully incremented." << endl;
                        WordsWithVowelFirst += 1;
                        oneTime = true;
                        break;
                    }
                    else if ((sentence [i - k] != ' ') || (sentence[i - k] != listOfnumbers[j])){
                    }
                    else{
                        k = k + 1;
                    }
                oneTime = false;
                }
            oneTime = false;
            }
            else if ((i != 0) && (sentence [i + 1] == ' ') && (sentence [i - 1] != ' ')){
                //cout << "This vowel in the index " << i << " is not the first letter of this word. so variable \"WordsWithVowelFirst\" has failed to increment." << endl;
                break;
            }
            break;
        case 'o':
        case 'O':
            //cout << "Index " << i << " Case O" << endl;
            if (i == 0){
                //cout << "This is probably a single letter vowel that started in the string so variable \"WordsWithVowelFirst\" has been successfully incremented" << endl;
                WordsWithVowelFirst += 1;
                break;
            }
            else if ((i != 0) && (sentence[i + 1] == ' ') && (sentence[i - 1] == ' ')){
                //cout << "There are two spaces around index " << i << " so variable \"WordsWithVowelFirst\" has been successfully incremented" << endl;
                WordsWithVowelFirst += 1;
                break;
            }
            else if ((i != 0) && (sentence [i - 1] == ' ') && (sentence[i + 1] != ' ')){
                //cout << "There is a space before a vowel in index " << i << " and there is a letter after a vowel in index " << i << " so variable \"WordsWithVowelFirst\" has been successfully incremented" << endl;
                WordsWithVowelFirst += 1;
                break;
            }
            else if ((i != 0) && (sentence[i + 1] != ' ') && (sentence[i - 1] != ' ')){
                for (int j = 0, k = 1; j < 10 && !oneTime;j++){
                    //cout << "Iteration j = " << j << " and k = i - " << k << ". " << endl;
                    if (sentence[i - k] == listOfnumbers[j]){
                        //cout << "Case I is in index[" << i << "] is surrounded by numbers.. will keep checking if there's any letters before I can find a space" << endl;
                        k = k + 1;
                        j = 0 - 1;
                    }
                    else if (sentence [i - k] == ' '){
                        //cout << "Case I: This vowel in this index (index [" << i << "]) is the the first vowel in this word. So variable \"WordsWithVowelFirst\" has been successfully incremented." << endl;
                        WordsWithVowelFirst += 1;
                        oneTime = true;
                        break;
                    }
                    else if ((sentence [i - k] != ' ') || (sentence[i - k] != listOfnumbers[j])){
                    }
                    else{
                        k = k + 1;
                    }
                oneTime = false;
                }
            oneTime = false;
            }
            else if ((i != 0) && (sentence [i + 1] == ' ') && (sentence [i - 1] != ' ')){
                //cout << "This vowel in the index " << i << " is not the first letter of this word. so variable \"WordsWithVowelFirst\" has failed to increment." << endl;
                break;
            }
            break;
        case 'u':
        case 'U':
            //cout << "Index " << i << " Case U" << endl;
            if (i == 0){
                //cout << "This is probably a single letter vowel that started in the string so variable \"WordsWithVowelFirst\" has been successfully incremented" << endl;
                WordsWithVowelFirst += 1;
                break;
            }
            else if ((i != 0) && (sentence[i + 1] == ' ') && (sentence[i - 1] == ' ')){
                //cout << "There are two spaces around index " << i << " so variable \"WordsWithVowelFirst\" has been successfully incremented" << endl;
                WordsWithVowelFirst += 1;
                break;
            }
            else if ((i != 0) && (sentence [i - 1] == ' ') && (sentence[i + 1] != ' ')){
                //cout << "There is a space before a vowel in index " << i << " and there is a letter after a vowel in index " << i << " so variable \"WordsWithVowelFirst\" has been successfully incremented" << endl;
                WordsWithVowelFirst += 1;
                break;
            }
            else if ((i != 0) && (sentence[i + 1] != ' ') && (sentence[i - 1] != ' ')){
                for (int j = 0, k = 1; j < 10 && !oneTime;j++){
                    //cout << "Iteration j = " << j << " and k = i - " << k << ". " << endl;
                    if (sentence[i - k] == listOfnumbers[j]){
                        //cout << "Case I is in index[" << i << "] is surrounded by numbers.. will keep checking if there's any letters before I can find a space" << endl;
                        k = k + 1;
                        j = 0 - 1;
                    }
                    else if (sentence [i - k] == ' '){
                        //cout << "Case I: This vowel in this index (index [" << i << "]) is the the first vowel in this word. So variable \"WordsWithVowelFirst\" has been successfully incremented." << endl;
                        WordsWithVowelFirst += 1;
                        oneTime = true;
                        break;
                    }
                    else if ((sentence [i - k] != ' ') || (sentence[i - k] != listOfnumbers[j])){
                    }
                    else{
                        k = k + 1;
                    }
                oneTime = false;
                }
            oneTime = false;
            }
            else if ((i != 0) && (sentence [i + 1] == ' ') && (sentence [i - 1] != ' ')){
                //cout << "This vowel in the index " << i << " is not the first letter of this word. so variable \"WordsWithVowelFirst\" has failed to increment." << endl;
                break;
            }
            break;
        }
    }
//-------------------------------------------------------------------//
    //"It is a java program to implement 23i5 monoalphabetic cypher. 123 456"
    // A = 1
    // C = 1
    // I = 4
    // J = 1
    // M = 1
    // P = 1
    // T = 1
    int firstLetterDis[26];
    for (int i = 0; i < 26; i++){
        firstLetterDis[i] = {0};
    }

    for (int i = 0; i < length; i++){
    switch(sentence[i]){
        case 'a':
        case 'A':
            if (i == 0){
                firstLetterDis[0] += 1;
                break;
            }
            else if ((i != 0) && (sentence[i + 1] == ' ') && (sentence[i - 1] == ' ')){
                //cout << "There are two spaces around index " << i << " so variable \"firstLetterDis\" has been successfully incremented" << endl;
                firstLetterDis[0] += 1;
                break;
            }
            else if ((i != 0) && (sentence [i - 1] == ' ') && (sentence[i + 1] != ' ')){
                //cout << "There is a space before a letter in index " << i << " and there is another letter after a vowel in index " << i << " so variable \"firstLetterDis\" has been successfully incremented" << endl;
                firstLetterDis[0] += 1;
                break;
            }
            else if ((i != 0) && (sentence[i + 1] != ' ') && (sentence[i - 1] != ' ')){
                for (int j = 0, k = 1; j < 10 && !oneTime;j++){
                    //cout << "Iteration j = " << j << " and k = i - " << k << ". " << endl;
                    if (sentence[i - k] == listOfnumbers[j]){
                        //cout << "Case I is in index[" << i << "] is surrounded by numbers.. will keep checking if there's any letters before I can find a space" << endl;
                        k = k + 1;
                        j = 0 - 1;
                    }
                    else if (sentence [i - k] == ' '){
                        //cout << "Case I: This vowel in this index (index [" << i << "]) is the the first vowel in this word. So variable \"firstLetterDis\" has been successfully incremented." << endl;
                        firstLetterDis[0] += 1;
                        oneTime = true;
                        break;
                    }
                    else if ((sentence [i - k] != ' ') || (sentence[i - k] != listOfnumbers[j])){
                    }
                    else{
                        k = k + 1;
                    }
                oneTime = false;
                }
            oneTime = false;
            }
            else if ((i != 0) && (sentence [i + 1] == ' ') && (sentence [i - 1] != ' ')){
                //cout << "This vowel in the index " << i << " is not the first letter of this word. so variable \"firstLetterDis\" has failed to increment." << endl;
                break;
            }
            break;
        case 'b':
        case 'B':
            if (i == 0){
                firstLetterDis[1] += 1;
                break;
            }
            else if ((i != 0) && (sentence[i + 1] == ' ') && (sentence[i - 1] == ' ')){
                //cout << "There are two spaces around index " << i << " so variable \"firstLetterDis\" has been successfully incremented" << endl;
                firstLetterDis[1] += 1;
                break;
            }
            else if ((i != 0) && (sentence [i - 1] == ' ') && (sentence[i + 1] != ' ')){
                //cout << "There is a space before a letter in index " << i << " and there is another letter after a vowel in index " << i << " so variable \"firstLetterDis\" has been successfully incremented" << endl;
                firstLetterDis[1] += 1;
                break;
            }
            else if ((i != 0) && (sentence[i + 1] != ' ') && (sentence[i - 1] != ' ')){
                for (int j = 0, k = 1; j < 10 && !oneTime;j++){
                    //cout << "Iteration j = " << j << " and k = i - " << k << ". " << endl;
                    if (sentence[i - k] == listOfnumbers[j]){
                        //cout << "Case I is in index[" << i << "] is surrounded by numbers.. will keep checking if there's any letters before I can find a space" << endl;
                        k = k + 1;
                        j = 0 - 1;
                    }
                    else if (sentence [i - k] == ' '){
                        //cout << "Case I: This vowel in this index (index [" << i << "]) is the the first vowel in this word. So variable \"firstLetterDis\" has been successfully incremented." << endl;
                        firstLetterDis[1] += 1;
                        oneTime = true;
                        break;
                    }
                    else if ((sentence [i - k] != ' ') || (sentence[i - k] != listOfnumbers[j])){
                    }
                    else{
                        k = k + 1;
                    }
                oneTime = false;
                }
            oneTime = false;
            }
            else if ((i != 0) && (sentence [i + 1] == ' ') && (sentence [i - 1] != ' ')){
                //cout << "This vowel in the index " << i << " is not the first letter of this word. so variable \"firstLetterDis\" has failed to increment." << endl;
                break;
            }
            break;
        case 'c':
        case 'C':
            if (i == 0){
                firstLetterDis[2] += 1;
                break;
            }
            else if ((i != 0) && (sentence[i + 1] == ' ') && (sentence[i - 1] == ' ')){
                //cout << "There are two spaces around index " << i << " so variable \"firstLetterDis\" has been successfully incremented" << endl;
                firstLetterDis[2] += 1;
                break;
            }
            else if ((i != 0) && (sentence [i - 1] == ' ') && (sentence[i + 1] != ' ')){
                //cout << "There is a space before a letter in index " << i << " and there is another letter after a vowel in index " << i << " so variable \"firstLetterDis\" has been successfully incremented" << endl;
                firstLetterDis[2] += 1;
                break;
            }
            else if ((i != 0) && (sentence[i + 1] != ' ') && (sentence[i - 1] != ' ')){
                for (int j = 0, k = 1; j < 10 && !oneTime;j++){
                    //cout << "Iteration j = " << j << " and k = i - " << k << ". " << endl;
                    if (sentence[i - k] == listOfnumbers[j]){
                        //cout << "Case I is in index[" << i << "] is surrounded by numbers.. will keep checking if there's any letters before I can find a space" << endl;
                        k = k + 1;
                        j = 0 - 1;
                    }
                    else if (sentence [i - k] == ' '){
                        //cout << "Case I: This vowel in this index (index [" << i << "]) is the the first vowel in this word. So variable \"firstLetterDis\" has been successfully incremented." << endl;
                        firstLetterDis[2] += 1;
                        oneTime = true;
                        break;
                    }
                    else if ((sentence [i - k] != ' ') || (sentence[i - k] != listOfnumbers[j])){
                    }
                    else{
                        k = k + 1;
                    }
                oneTime = false;
                }
            oneTime = false;
            }
            else if ((i != 0) && (sentence [i + 1] == ' ') && (sentence [i - 1] != ' ')){
                //cout << "This vowel in the index " << i << " is not the first letter of this word. so variable \"firstLetterDis\" has failed to increment." << endl;
                break;
            }
            break;
        case 'd':
        case 'D':
            if (i == 0){
                firstLetterDis[3] += 1;
                break;
            }
            else if ((i != 0) && (sentence[i + 1] == ' ') && (sentence[i - 1] == ' ')){
                //cout << "There are two spaces around index " << i << " so variable \"firstLetterDis\" has been successfully incremented" << endl;
                firstLetterDis[3] += 1;
                break;
            }
            else if ((i != 0) && (sentence [i - 1] == ' ') && (sentence[i + 1] != ' ')){
                //cout << "There is a space before a letter in index " << i << " and there is another letter after a vowel in index " << i << " so variable \"firstLetterDis\" has been successfully incremented" << endl;
                firstLetterDis[3] += 1;
                break;
            }
            else if ((i != 0) && (sentence[i + 1] != ' ') && (sentence[i - 1] != ' ')){
                for (int j = 0, k = 1; j < 10 && !oneTime;j++){
                    //cout << "Iteration j = " << j << " and k = i - " << k << ". " << endl;
                    if (sentence[i - k] == listOfnumbers[j]){
                        //cout << "Case I is in index[" << i << "] is surrounded by numbers.. will keep checking if there's any letters before I can find a space" << endl;
                        k = k + 1;
                        j = 0 - 1;
                    }
                    else if (sentence [i - k] == ' '){
                        //cout << "Case I: This vowel in this index (index [" << i << "]) is the the first vowel in this word. So variable \"firstLetterDis\" has been successfully incremented." << endl;
                        firstLetterDis[3] += 1;
                        oneTime = true;
                        break;
                    }
                    else if ((sentence [i - k] != ' ') || (sentence[i - k] != listOfnumbers[j])){
                    }
                    else{
                        k = k + 1;
                    }
                oneTime = false;
                }
            oneTime = false;
            }
            else if ((i != 0) && (sentence [i + 1] == ' ') && (sentence [i - 1] != ' ')){
                //cout << "This vowel in the index " << i << " is not the first letter of this word. so variable \"firstLetterDis\" has failed to increment." << endl;
                break;
            }
            break;
        case 'e':
        case 'E':
            if (i == 0){
                firstLetterDis[4] += 1;
                break;
            }
            else if ((i != 0) && (sentence[i + 1] == ' ') && (sentence[i - 1] == ' ')){
                //cout << "There are two spaces around index " << i << " so variable \"firstLetterDis\" has been successfully incremented" << endl;
                firstLetterDis[4] += 1;
                break;
            }
            else if ((i != 0) && (sentence [i - 1] == ' ') && (sentence[i + 1] != ' ')){
                //cout << "There is a space before a letter in index " << i << " and there is another letter after a vowel in index " << i << " so variable \"firstLetterDis\" has been successfully incremented" << endl;
                firstLetterDis[4] += 1;
                break;
            }
            else if ((i != 0) && (sentence[i + 1] != ' ') && (sentence[i - 1] != ' ')){
                for (int j = 0, k = 1; j < 10 && !oneTime;j++){
                    //cout << "Iteration j = " << j << " and k = i - " << k << ". " << endl;
                    if (sentence[i - k] == listOfnumbers[j]){
                        //cout << "Case I is in index[" << i << "] is surrounded by numbers.. will keep checking if there's any letters before I can find a space" << endl;
                        k = k + 1;
                        j = 0 - 1;
                    }
                    else if (sentence [i - k] == ' '){
                        //cout << "Case I: This vowel in this index (index [" << i << "]) is the the first vowel in this word. So variable \"firstLetterDis\" has been successfully incremented." << endl;
                        firstLetterDis[4] += 1;
                        oneTime = true;
                        break;
                    }
                    else if ((sentence [i - k] != ' ') || (sentence[i - k] != listOfnumbers[j])){
                    }
                    else{
                        k = k + 1;
                    }
                oneTime = false;
                }
            oneTime = false;
            }
            else if ((i != 0) && (sentence [i + 1] == ' ') && (sentence [i - 1] != ' ')){
                //cout << "This vowel in the index " << i << " is not the first letter of this word. so variable \"firstLetterDis\" has failed to increment." << endl;
                break;
            }
            break;
        case 'f':
        case 'F':
            if (i == 0){
                firstLetterDis[5] += 1;
                break;
            }
            else if ((i != 0) && (sentence[i + 1] == ' ') && (sentence[i - 1] == ' ')){
                //cout << "There are two spaces around index " << i << " so variable \"firstLetterDis\" has been successfully incremented" << endl;
                firstLetterDis[5] += 1;
                break;
            }
            else if ((i != 0) && (sentence [i - 1] == ' ') && (sentence[i + 1] != ' ')){
                //cout << "There is a space before a letter in index " << i << " and there is another letter after a vowel in index " << i << " so variable \"firstLetterDis\" has been successfully incremented" << endl;
                firstLetterDis[5] += 1;
                break;
            }
            else if ((i != 0) && (sentence[i + 1] != ' ') && (sentence[i - 1] != ' ')){
                for (int j = 0, k = 1; j < 10 && !oneTime;j++){
                    //cout << "Iteration j = " << j << " and k = i - " << k << ". " << endl;
                    if (sentence[i - k] == listOfnumbers[j]){
                        //cout << "Case I is in index[" << i << "] is surrounded by numbers.. will keep checking if there's any letters before I can find a space" << endl;
                        k = k + 1;
                        j = 0 - 1;
                    }
                    else if (sentence [i - k] == ' '){
                        //cout << "Case I: This vowel in this index (index [" << i << "]) is the the first vowel in this word. So variable \"firstLetterDis\" has been successfully incremented." << endl;
                        firstLetterDis[5] += 1;
                        oneTime = true;
                        break;
                    }
                    else if ((sentence [i - k] != ' ') || (sentence[i - k] != listOfnumbers[j])){
                    }
                    else{
                        k = k + 1;
                    }
                oneTime = false;
                }
            oneTime = false;
            }
            else if ((i != 0) && (sentence [i + 1] == ' ') && (sentence [i - 1] != ' ')){
                //cout << "This vowel in the index " << i << " is not the first letter of this word. so variable \"firstLetterDis\" has failed to increment." << endl;
                break;
            }
            break;
        case 'g':
        case 'G':
            if (i == 0){
                firstLetterDis[6] += 1;
                break;
            }
            else if ((i != 0) && (sentence[i + 1] == ' ') && (sentence[i - 1] == ' ')){
                //cout << "There are two spaces around index " << i << " so variable \"firstLetterDis\" has been successfully incremented" << endl;
                firstLetterDis[6] += 1;
                break;
            }
            else if ((i != 0) && (sentence [i - 1] == ' ') && (sentence[i + 1] != ' ')){
                //cout << "There is a space before a letter in index " << i << " and there is another letter after a vowel in index " << i << " so variable \"firstLetterDis\" has been successfully incremented" << endl;
                firstLetterDis[6] += 1;
                break;
            }
            else if ((i != 0) && (sentence[i + 1] != ' ') && (sentence[i - 1] != ' ')){
                for (int j = 0, k = 1; j < 10 && !oneTime;j++){
                    //cout << "Iteration j = " << j << " and k = i - " << k << ". " << endl;
                    if (sentence[i - k] == listOfnumbers[j]){
                        //cout << "Case I is in index[" << i << "] is surrounded by numbers.. will keep checking if there's any letters before I can find a space" << endl;
                        k = k + 1;
                        j = 0 - 1;
                    }
                    else if (sentence [i - k] == ' '){
                        //cout << "Case I: This vowel in this index (index [" << i << "]) is the the first vowel in this word. So variable \"firstLetterDis\" has been successfully incremented." << endl;
                        firstLetterDis[6] += 1;
                        oneTime = true;
                        break;
                    }
                    else if ((sentence [i - k] != ' ') || (sentence[i - k] != listOfnumbers[j])){
                    }
                    else{
                        k = k + 1;
                    }
                oneTime = false;
                }
            oneTime = false;
            }
            else if ((i != 0) && (sentence [i + 1] == ' ') && (sentence [i - 1] != ' ')){
                //cout << "This vowel in the index " << i << " is not the first letter of this word. so variable \"firstLetterDis\" has failed to increment." << endl;
                break;
            }
            break;
        case 'h':
        case 'H':
            if (i == 0){
                firstLetterDis[7] += 1;
                break;
            }
            else if ((i != 0) && (sentence[i + 1] == ' ') && (sentence[i - 1] == ' ')){
                //cout << "There are two spaces around index " << i << " so variable \"firstLetterDis\" has been successfully incremented" << endl;
                firstLetterDis[7] += 1;
                break;
            }
            else if ((i != 0) && (sentence [i - 1] == ' ') && (sentence[i + 1] != ' ')){
                //cout << "There is a space before a letter in index " << i << " and there is another letter after a vowel in index " << i << " so variable \"firstLetterDis\" has been successfully incremented" << endl;
                firstLetterDis[7] += 1;
                break;
            }
            else if ((i != 0) && (sentence[i + 1] != ' ') && (sentence[i - 1] != ' ')){
                for (int j = 0, k = 1; j < 10 && !oneTime;j++){
                    //cout << "Iteration j = " << j << " and k = i - " << k << ". " << endl;
                    if (sentence[i - k] == listOfnumbers[j]){
                        //cout << "Case I is in index[" << i << "] is surrounded by numbers.. will keep checking if there's any letters before I can find a space" << endl;
                        k = k + 1;
                        j = 0 - 1;
                    }
                    else if (sentence [i - k] == ' '){
                        //cout << "Case I: This vowel in this index (index [" << i << "]) is the the first vowel in this word. So variable \"firstLetterDis\" has been successfully incremented." << endl;
                        firstLetterDis[7] += 1;
                        oneTime = true;
                        break;
                    }
                    else if ((sentence [i - k] != ' ') || (sentence[i - k] != listOfnumbers[j])){
                    }
                    else{
                        k = k + 1;
                    }
                oneTime = false;
                }
            oneTime = false;
            }
            else if ((i != 0) && (sentence [i + 1] == ' ') && (sentence [i - 1] != ' ')){
                //cout << "This vowel in the index " << i << " is not the first letter of this word. so variable \"firstLetterDis\" has failed to increment." << endl;
                break;
            }
            break;
        case 'i':
        case 'I':
            //"It is a java program to implement 23i5 monoalphabetic cypher. 123 456"
            if (i == 0){
                firstLetterDis[8] += 1;
                break;
            }
            else if ((i != 0) && (sentence[i + 1] == ' ') && (sentence[i - 1] == ' ')){
                //cout << "There are two spaces around index " << i << " so variable \"firstLetterDis\" has been successfully incremented" << endl;
                firstLetterDis[8] += 1;
                break;
            }
            else if ((i != 0) && (sentence [i - 1] == ' ') && (sentence[i + 1] != ' ')){
                //cout << "There is a space before a letter in index " << i << " and there is another letter after a vowel in index " << i << " so variable \"firstLetterDis\" has been successfully incremented" << endl;
                firstLetterDis[8] += 1;
                break;
            }
            else if ((i != 0) && (sentence[i + 1] != ' ') && (sentence[i - 1] != ' ')){
                for (int j = 0, k = 1; j < 10 && !oneTime;j++){
                    //cout << "Iteration j = " << j << " and k = i - " << k << ". " << endl;
                    if (sentence[i - k] == listOfnumbers[j]){
                        //cout << "Case I is in index[" << i << "] is surrounded by numbers.. will keep checking if there's any letters before I can find a space" << endl;
                        k = k + 1;
                        j = 0 - 1;
                    }
                    else if (sentence [i - k] == ' '){
                        //cout << "Case I: This vowel in this index (index [" << i << "]) is the the first vowel in this word. So variable \"firstLetterDis\" has been successfully incremented." << endl;
                        firstLetterDis[8] += 1;
                        oneTime = true;
                        break;
                    }
                    else if ((sentence [i - k] != ' ') || (sentence[i - k] != listOfnumbers[j])){
                    }
                    else{
                        k = k + 1;
                    }
                oneTime = false;
                }
            oneTime = false;
            }
            else if ((i != 0) && (sentence [i + 1] == ' ') && (sentence [i - 1] != ' ')){
                //cout << "This vowel in the index " << i << " is not the first letter of this word. so variable \"firstLetterDis\" has failed to increment." << endl;
                break;
            }
            break;
        case 'j':
        case 'J':
            if (i == 0){
                firstLetterDis[9] += 1;
                break;
            }
            else if ((i != 0) && (sentence[i + 1] == ' ') && (sentence[i - 1] == ' ')){
                //cout << "There are two spaces around index " << i << " so variable \"firstLetterDis\" has been successfully incremented" << endl;
                firstLetterDis[9] += 1;
                break;
            }
            else if ((i != 0) && (sentence [i - 1] == ' ') && (sentence[i + 1] != ' ')){
                //cout << "There is a space before a letter in index " << i << " and there is another letter after a vowel in index " << i << " so variable \"firstLetterDis\" has been successfully incremented" << endl;
                firstLetterDis[9] += 1;
                break;
            }
            else if ((i != 0) && (sentence[i + 1] != ' ') && (sentence[i - 1] != ' ')){
                for (int j = 0, k = 1; j < 10 && !oneTime;j++){
                    //cout << "Iteration j = " << j << " and k = i - " << k << ". " << endl;
                    if (sentence[i - k] == listOfnumbers[j]){
                        //cout << "Case I is in index[" << i << "] is surrounded by numbers.. will keep checking if there's any letters before I can find a space" << endl;
                        k = k + 1;
                        j = 0 - 1;
                    }
                    else if (sentence [i - k] == ' '){
                        //cout << "Case I: This vowel in this index (index [" << i << "]) is the the first vowel in this word. So variable \"firstLetterDis\" has been successfully incremented." << endl;
                        firstLetterDis[9] += 1;
                        oneTime = true;
                        break;
                    }
                    else if ((sentence [i - k] != ' ') || (sentence[i - k] != listOfnumbers[j])){
                    }
                    else{
                        k = k + 1;
                    }
                oneTime = false;
                }
            oneTime = false;
            }
            else if ((i != 0) && (sentence [i + 1] == ' ') && (sentence [i - 1] != ' ')){
                //cout << "This vowel in the index " << i << " is not the first letter of this word. so variable \"firstLetterDis\" has failed to increment." << endl;
                break;
            }
            break;
        case 'k':
        case 'K':
            if (i == 0){
                firstLetterDis[10] += 1;
                break;
            }
            else if ((i != 0) && (sentence[i + 1] == ' ') && (sentence[i - 1] == ' ')){
                //cout << "There are two spaces around index " << i << " so variable \"firstLetterDis\" has been successfully incremented" << endl;
                firstLetterDis[10] += 1;
                break;
            }
            else if ((i != 0) && (sentence [i - 1] == ' ') && (sentence[i + 1] != ' ')){
                //cout << "There is a space before a letter in index " << i << " and there is another letter after a vowel in index " << i << " so variable \"firstLetterDis\" has been successfully incremented" << endl;
                firstLetterDis[10] += 1;
                break;
            }
            else if ((i != 0) && (sentence[i + 1] != ' ') && (sentence[i - 1] != ' ')){
                for (int j = 0, k = 1; j < 10 && !oneTime;j++){
                    //cout << "Iteration j = " << j << " and k = i - " << k << ". " << endl;
                    if (sentence[i - k] == listOfnumbers[j]){
                        //cout << "Case I is in index[" << i << "] is surrounded by numbers.. will keep checking if there's any letters before I can find a space" << endl;
                        k = k + 1;
                        j = 0 - 1;
                    }
                    else if (sentence [i - k] == ' '){
                        //cout << "Case I: This vowel in this index (index [" << i << "]) is the the first vowel in this word. So variable \"firstLetterDis\" has been successfully incremented." << endl;
                        firstLetterDis[10] += 1;
                        oneTime = true;
                        break;
                    }
                    else if ((sentence [i - k] != ' ') || (sentence[i - k] != listOfnumbers[j])){
                    }
                    else{
                        k = k + 1;
                    }
                oneTime = false;
                }
            oneTime = false;
            }
            else if ((i != 0) && (sentence [i + 1] == ' ') && (sentence [i - 1] != ' ')){
                //cout << "This vowel in the index " << i << " is not the first letter of this word. so variable \"firstLetterDis\" has failed to increment." << endl;
                break;
            }
            break;
        case 'l':
        case 'L':
            if (i == 0){
                firstLetterDis[11] += 1;
                break;
            }
            else if ((i != 0) && (sentence[i + 1] == ' ') && (sentence[i - 1] == ' ')){
                //cout << "There are two spaces around index " << i << " so variable \"firstLetterDis\" has been successfully incremented" << endl;
                firstLetterDis[11] += 1;
                break;
            }
            else if ((i != 0) && (sentence [i - 1] == ' ') && (sentence[i + 1] != ' ')){
                //cout << "There is a space before a letter in index " << i << " and there is another letter after a vowel in index " << i << " so variable \"firstLetterDis\" has been successfully incremented" << endl;
                firstLetterDis[11] += 1;
                break;
            }
            else if ((i != 0) && (sentence[i + 1] != ' ') && (sentence[i - 1] != ' ')){
                for (int j = 0, k = 1; j < 10 && !oneTime;j++){
                    //cout << "Iteration j = " << j << " and k = i - " << k << ". " << endl;
                    if (sentence[i - k] == listOfnumbers[j]){
                        //cout << "Case I is in index[" << i << "] is surrounded by numbers.. will keep checking if there's any letters before I can find a space" << endl;
                        k = k + 1;
                        j = 0 - 1;
                    }
                    else if (sentence [i - k] == ' '){
                        //cout << "Case I: This vowel in this index (index [" << i << "]) is the the first vowel in this word. So variable \"firstLetterDis\" has been successfully incremented." << endl;
                        firstLetterDis[11] += 1;
                        oneTime = true;
                        break;
                    }
                    else if ((sentence [i - k] != ' ') || (sentence[i - k] != listOfnumbers[j])){
                    }
                    else{
                        k = k + 1;
                    }
                oneTime = false;
                }
            oneTime = false;
            }
            else if ((i != 0) && (sentence [i + 1] == ' ') && (sentence [i - 1] != ' ')){
                //cout << "This vowel in the index " << i << " is not the first letter of this word. so variable \"firstLetterDis\" has failed to increment." << endl;
                break;
            }
            break;
        case 'm':
        case 'M':
            if (i == 0){
                firstLetterDis[12] += 1;
                break;
            }
            else if ((i != 0) && (sentence[i + 1] == ' ') && (sentence[i - 1] == ' ')){
                //cout << "There are two spaces around index " << i << " so variable \"firstLetterDis\" has been successfully incremented" << endl;
                firstLetterDis[12] += 1;
                break;
            }
            else if ((i != 0) && (sentence [i - 1] == ' ') && (sentence[i + 1] != ' ')){
                //cout << "There is a space before a letter in index " << i << " and there is another letter after a vowel in index " << i << " so variable \"firstLetterDis\" has been successfully incremented" << endl;
                firstLetterDis[12] += 1;
                break;
            }
            else if ((i != 0) && (sentence[i + 1] != ' ') && (sentence[i - 1] != ' ')){
                for (int j = 0, k = 1; j < 10 && !oneTime;j++){
                    //cout << "Iteration j = " << j << " and k = i - " << k << ". " << endl;
                    if (sentence[i - k] == listOfnumbers[j]){
                        //cout << "Case I is in index[" << i << "] is surrounded by numbers.. will keep checking if there's any letters before I can find a space" << endl;
                        k = k + 1;
                        j = 0 - 1;
                    }
                    else if (sentence [i - k] == ' '){
                        //cout << "Case I: This vowel in this index (index [" << i << "]) is the the first vowel in this word. So variable \"firstLetterDis\" has been successfully incremented." << endl;
                        firstLetterDis[12] += 1;
                        oneTime = true;
                        break;
                    }
                    else if ((sentence [i - k] != ' ') || (sentence[i - k] != listOfnumbers[j])){
                    }
                    else{
                        k = k + 1;
                    }
                oneTime = false;
                }
            oneTime = false;
            }
            else if ((i != 0) && (sentence [i + 1] == ' ') && (sentence [i - 1] != ' ')){
                //cout << "This vowel in the index " << i << " is not the first letter of this word. so variable \"firstLetterDis\" has failed to increment." << endl;
                break;
            }
            break;
        case 'n':
        case 'N':
            if (i == 0){
                firstLetterDis[13] += 1;
                break;
            }
            else if ((i != 0) && (sentence[i + 1] == ' ') && (sentence[i - 1] == ' ')){
                //cout << "There are two spaces around index " << i << " so variable \"firstLetterDis\" has been successfully incremented" << endl;
                firstLetterDis[13] += 1;
                break;
            }
            else if ((i != 0) && (sentence [i - 1] == ' ') && (sentence[i + 1] != ' ')){
                //cout << "There is a space before a letter in index " << i << " and there is another letter after a vowel in index " << i << " so variable \"firstLetterDis\" has been successfully incremented" << endl;
                firstLetterDis[13] += 1;
                break;
            }
            else if ((i != 0) && (sentence[i + 1] != ' ') && (sentence[i - 1] != ' ')){
                for (int j = 0, k = 1; j < 10 && !oneTime;j++){
                    //cout << "Iteration j = " << j << " and k = i - " << k << ". " << endl;
                    if (sentence[i - k] == listOfnumbers[j]){
                        //cout << "Case I is in index[" << i << "] is surrounded by numbers.. will keep checking if there's any letters before I can find a space" << endl;
                        k = k + 1;
                        j = 0 - 1;
                    }
                    else if (sentence [i - k] == ' '){
                        //cout << "Case I: This vowel in this index (index [" << i << "]) is the the first vowel in this word. So variable \"firstLetterDis\" has been successfully incremented." << endl;
                        firstLetterDis[13] += 1;
                        oneTime = true;
                        break;
                    }
                    else if ((sentence [i - k] != ' ') || (sentence[i - k] != listOfnumbers[j])){
                    }
                    else{
                        k = k + 1;
                    }
                oneTime = false;
                }
            oneTime = false;
            }
            else if ((i != 0) && (sentence [i + 1] == ' ') && (sentence [i - 1] != ' ')){
                //cout << "This vowel in the index " << i << " is not the first letter of this word. so variable \"firstLetterDis\" has failed to increment." << endl;
                break;
            }
            break;
        case 'o':
        case 'O':
            if (i == 0){
                firstLetterDis[14] += 1;
                break;
            }
            else if ((i != 0) && (sentence[i + 1] == ' ') && (sentence[i - 1] == ' ')){
                //cout << "There are two spaces around index " << i << " so variable \"firstLetterDis\" has been successfully incremented" << endl;
                firstLetterDis[14] += 1;
                break;
            }
            else if ((i != 0) && (sentence [i - 1] == ' ') && (sentence[i + 1] != ' ')){
                //cout << "There is a space before a letter in index " << i << " and there is another letter after a vowel in index " << i << " so variable \"firstLetterDis\" has been successfully incremented" << endl;
                firstLetterDis[14] += 1;
                break;
            }
            else if ((i != 0) && (sentence[i + 1] != ' ') && (sentence[i - 1] != ' ')){
                for (int j = 0, k = 1; j < 10 && !oneTime;j++){
                    //cout << "Iteration j = " << j << " and k = i - " << k << ". " << endl;
                    if (sentence[i - k] == listOfnumbers[j]){
                        //cout << "Case I is in index[" << i << "] is surrounded by numbers.. will keep checking if there's any letters before I can find a space" << endl;
                        k = k + 1;
                        j = 0 - 1;
                    }
                    else if (sentence [i - k] == ' '){
                        //cout << "Case I: This vowel in this index (index [" << i << "]) is the the first vowel in this word. So variable \"firstLetterDis\" has been successfully incremented." << endl;
                        firstLetterDis[14] += 1;
                        oneTime = true;
                        break;
                    }
                    else if ((sentence [i - k] != ' ') || (sentence[i - k] != listOfnumbers[j])){
                    }
                    else{
                        k = k + 1;
                    }
                oneTime = false;
                }
            oneTime = false;
            }
            else if ((i != 0) && (sentence [i + 1] == ' ') && (sentence [i - 1] != ' ')){
                //cout << "This vowel in the index " << i << " is not the first letter of this word. so variable \"firstLetterDis\" has failed to increment." << endl;
                break;
            }
            break;
        case 'p':
        case 'P':
            if (i == 0){
                firstLetterDis[15] += 1;
                break;
            }
            else if ((i != 0) && (sentence[i + 1] == ' ') && (sentence[i - 1] == ' ')){
                //cout << "There are two spaces around index " << i << " so variable \"firstLetterDis\" has been successfully incremented" << endl;
                firstLetterDis[15] += 1;
                break;
            }
            else if ((i != 0) && (sentence [i - 1] == ' ') && (sentence[i + 1] != ' ')){
                //cout << "There is a space before a letter in index " << i << " and there is another letter after a vowel in index " << i << " so variable \"firstLetterDis\" has been successfully incremented" << endl;
                firstLetterDis[15] += 1;
                break;
            }
            else if ((i != 0) && (sentence[i + 1] != ' ') && (sentence[i - 1] != ' ')){
                for (int j = 0, k = 1; j < 10 && !oneTime;j++){
                    //cout << "Iteration j = " << j << " and k = i - " << k << ". " << endl;
                    if (sentence[i - k] == listOfnumbers[j]){
                        //cout << "Case I is in index[" << i << "] is surrounded by numbers.. will keep checking if there's any letters before I can find a space" << endl;
                        k = k + 1;
                        j = 0 - 1;
                    }
                    else if (sentence [i - k] == ' '){
                        //cout << "Case I: This vowel in this index (index [" << i << "]) is the the first vowel in this word. So variable \"firstLetterDis\" has been successfully incremented." << endl;
                        firstLetterDis[15] += 1;
                        oneTime = true;
                        break;
                    }
                    else if ((sentence [i - k] != ' ') || (sentence[i - k] != listOfnumbers[j])){
                    }
                    else{
                        k = k + 1;
                    }
                oneTime = false;
                }
            oneTime = false;
            }
            else if ((i != 0) && (sentence [i + 1] == ' ') && (sentence [i - 1] != ' ')){
                //cout << "This vowel in the index " << i << " is not the first letter of this word. so variable \"firstLetterDis\" has failed to increment." << endl;
                break;
            }
            break;
        case 'q':
        case 'Q':
            if (i == 0){
                firstLetterDis[16] += 1;
                break;
            }
            else if ((i != 0) && (sentence[i + 1] == ' ') && (sentence[i - 1] == ' ')){
                //cout << "There are two spaces around index " << i << " so variable \"firstLetterDis\" has been successfully incremented" << endl;
                firstLetterDis[16] += 1;
                break;
            }
            else if ((i != 0) && (sentence [i - 1] == ' ') && (sentence[i + 1] != ' ')){
                //cout << "There is a space before a letter in index " << i << " and there is another letter after a vowel in index " << i << " so variable \"firstLetterDis\" has been successfully incremented" << endl;
                firstLetterDis[16] += 1;
                break;
            }
            else if ((i != 0) && (sentence[i + 1] != ' ') && (sentence[i - 1] != ' ')){
                for (int j = 0, k = 1; j < 10 && !oneTime;j++){
                    //cout << "Iteration j = " << j << " and k = i - " << k << ". " << endl;
                    if (sentence[i - k] == listOfnumbers[j]){
                        //cout << "Case I is in index[" << i << "] is surrounded by numbers.. will keep checking if there's any letters before I can find a space" << endl;
                        k = k + 1;
                        j = 0 - 1;
                    }
                    else if (sentence [i - k] == ' '){
                        //cout << "Case I: This vowel in this index (index [" << i << "]) is the the first vowel in this word. So variable \"firstLetterDis\" has been successfully incremented." << endl;
                        firstLetterDis[16] += 1;
                        oneTime = true;
                        break;
                    }
                    else if ((sentence [i - k] != ' ') || (sentence[i - k] != listOfnumbers[j])){
                    }
                    else{
                        k = k + 1;
                    }
                oneTime = false;
                }
            oneTime = false;
            }
            else if ((i != 0) && (sentence [i + 1] == ' ') && (sentence [i - 1] != ' ')){
                //cout << "This vowel in the index " << i << " is not the first letter of this word. so variable \"firstLetterDis\" has failed to increment." << endl;
                break;
            }
            break;
        case 'r':
        case 'R':
            if (i == 0){
                firstLetterDis[17] += 1;
                break;
            }
            else if ((i != 0) && (sentence[i + 1] == ' ') && (sentence[i - 1] == ' ')){
                //cout << "There are two spaces around index " << i << " so variable \"firstLetterDis\" has been successfully incremented" << endl;
                firstLetterDis[17] += 1;
                break;
            }
            else if ((i != 0) && (sentence [i - 1] == ' ') && (sentence[i + 1] != ' ')){
                //cout << "There is a space before a letter in index " << i << " and there is another letter after a vowel in index " << i << " so variable \"firstLetterDis\" has been successfully incremented" << endl;
                firstLetterDis[17] += 1;
                break;
            }
            else if ((i != 0) && (sentence[i + 1] != ' ') && (sentence[i - 1] != ' ')){
                for (int j = 0, k = 1; j < 10 && !oneTime;j++){
                    //cout << "Iteration j = " << j << " and k = i - " << k << ". " << endl;
                    if (sentence[i - k] == listOfnumbers[j]){
                        //cout << "Case I is in index[" << i << "] is surrounded by numbers.. will keep checking if there's any letters before I can find a space" << endl;
                        k = k + 1;
                        j = 0 - 1;
                    }
                    else if (sentence [i - k] == ' '){
                        //cout << "Case I: This vowel in this index (index [" << i << "]) is the the first vowel in this word. So variable \"firstLetterDis\" has been successfully incremented." << endl;
                        firstLetterDis[17] += 1;
                        oneTime = true;
                        break;
                    }
                    else if ((sentence [i - k] != ' ') || (sentence[i - k] != listOfnumbers[j])){
                    }
                    else{
                        k = k + 1;
                    }
                oneTime = false;
                }
            oneTime = false;
            }
            else if ((i != 0) && (sentence [i + 1] == ' ') && (sentence [i - 1] != ' ')){
                //cout << "This vowel in the index " << i << " is not the first letter of this word. so variable \"firstLetterDis\" has failed to increment." << endl;
                break;
            }
            break;
        case 's':
        case 'S':
            if (i == 0){
                firstLetterDis[18] += 1;
                break;
            }
            else if ((i != 0) && (sentence[i + 1] == ' ') && (sentence[i - 1] == ' ')){
                //cout << "There are two spaces around index " << i << " so variable \"firstLetterDis\" has been successfully incremented" << endl;
                firstLetterDis[18] += 1;
                break;
            }
            else if ((i != 0) && (sentence [i - 1] == ' ') && (sentence[i + 1] != ' ')){
                //cout << "There is a space before a letter in index " << i << " and there is another letter after a vowel in index " << i << " so variable \"firstLetterDis\" has been successfully incremented" << endl;
                firstLetterDis[18] += 1;
                break;
            }
            else if ((i != 0) && (sentence[i + 1] != ' ') && (sentence[i - 1] != ' ')){
                for (int j = 0, k = 1; j < 10 && !oneTime;j++){
                    //cout << "Iteration j = " << j << " and k = i - " << k << ". " << endl;
                    if (sentence[i - k] == listOfnumbers[j]){
                        //cout << "Case I is in index[" << i << "] is surrounded by numbers.. will keep checking if there's any letters before I can find a space" << endl;
                        k = k + 1;
                        j = 0 - 1;
                    }
                    else if (sentence [i - k] == ' '){
                        //cout << "Case I: This vowel in this index (index [" << i << "]) is the the first vowel in this word. So variable \"firstLetterDis\" has been successfully incremented." << endl;
                        firstLetterDis[18] += 1;
                        oneTime = true;
                        break;
                    }
                    else if ((sentence [i - k] != ' ') || (sentence[i - k] != listOfnumbers[j])){
                    }
                    else{
                        k = k + 1;
                    }
                oneTime = false;
                }
            oneTime = false;
            }
            else if ((i != 0) && (sentence [i + 1] == ' ') && (sentence [i - 1] != ' ')){
                //cout << "This vowel in the index " << i << " is not the first letter of this word. so variable \"firstLetterDis\" has failed to increment." << endl;
                break;
            }
            break;
        case 't':
        case 'T':
            if (i == 0){
                firstLetterDis[19] += 1;
                break;
            }
            else if ((i != 0) && (sentence[i + 1] == ' ') && (sentence[i - 1] == ' ')){
                //cout << "There are two spaces around index " << i << " so variable \"firstLetterDis\" has been successfully incremented" << endl;
                firstLetterDis[19] += 1;
                break;
            }
            else if ((i != 0) && (sentence [i - 1] == ' ') && (sentence[i + 1] != ' ')){
                //cout << "There is a space before a letter in index " << i << " and there is another letter after a vowel in index " << i << " so variable \"firstLetterDis\" has been successfully incremented" << endl;
                firstLetterDis[19] += 1;
                break;
            }
            else if ((i != 0) && (sentence[i + 1] != ' ') && (sentence[i - 1] != ' ')){
                for (int j = 0, k = 1; j < 10 && !oneTime;j++){
                    //cout << "Iteration j = " << j << " and k = i - " << k << ". " << endl;
                    if (sentence[i - k] == listOfnumbers[j]){
                        //cout << "Case I is in index[" << i << "] is surrounded by numbers.. will keep checking if there's any letters before I can find a space" << endl;
                        k = k + 1;
                        j = 0 - 1;
                    }
                    else if (sentence [i - k] == ' '){
                        //cout << "Case I: This vowel in this index (index [" << i << "]) is the the first vowel in this word. So variable \"firstLetterDis\" has been successfully incremented." << endl;
                        firstLetterDis[19] += 1;
                        oneTime = true;
                        break;
                    }
                    else if ((sentence [i - k] != ' ') || (sentence[i - k] != listOfnumbers[j])){
                    }
                    else{
                        k = k + 1;
                    }
                oneTime = false;
                }
            oneTime = false;
            }
            else if ((i != 0) && (sentence [i + 1] == ' ') && (sentence [i - 1] != ' ')){
                //cout << "This vowel in the index " << i << " is not the first letter of this word. so variable \"firstLetterDis\" has failed to increment." << endl;
                break;
            }
            break;
        case 'u':
        case 'U':
            if (i == 0){
                firstLetterDis[20] += 1;
                break;
            }
            else if ((i != 0) && (sentence[i + 1] == ' ') && (sentence[i - 1] == ' ')){
                //cout << "There are two spaces around index " << i << " so variable \"firstLetterDis\" has been successfully incremented" << endl;
                firstLetterDis[20] += 1;
                break;
            }
            else if ((i != 0) && (sentence [i - 1] == ' ') && (sentence[i + 1] != ' ')){
                //cout << "There is a space before a letter in index " << i << " and there is another letter after a vowel in index " << i << " so variable \"firstLetterDis\" has been successfully incremented" << endl;
                firstLetterDis[20] += 1;
                break;
            }
            else if ((i != 0) && (sentence[i + 1] != ' ') && (sentence[i - 1] != ' ')){
                for (int j = 0, k = 1; j < 10 && !oneTime;j++){
                    //cout << "Iteration j = " << j << " and k = i - " << k << ". " << endl;
                    if (sentence[i - k] == listOfnumbers[j]){
                        //cout << "Case I is in index[" << i << "] is surrounded by numbers.. will keep checking if there's any letters before I can find a space" << endl;
                        k = k + 1;
                        j = 0 - 1;
                    }
                    else if (sentence [i - k] == ' '){
                        //cout << "Case I: This vowel in this index (index [" << i << "]) is the the first vowel in this word. So variable \"firstLetterDis\" has been successfully incremented." << endl;
                        firstLetterDis[20] += 1;
                        oneTime = true;
                        break;
                    }
                    else if ((sentence [i - k] != ' ') || (sentence[i - k] != listOfnumbers[j])){
                    }
                    else{
                        k = k + 1;
                    }
                oneTime = false;
                }
            oneTime = false;
            }
            else if ((i != 0) && (sentence [i + 1] == ' ') && (sentence [i - 1] != ' ')){
                //cout << "This vowel in the index " << i << " is not the first letter of this word. so variable \"firstLetterDis\" has failed to increment." << endl;
                break;
            }
            break;
        case 'v':
        case 'V':
            if (i == 0){
                firstLetterDis[21] += 1;
                break;
            }
            else if ((i != 0) && (sentence[i + 1] == ' ') && (sentence[i - 1] == ' ')){
                //cout << "There are two spaces around index " << i << " so variable \"firstLetterDis\" has been successfully incremented" << endl;
                firstLetterDis[21] += 1;
                break;
            }
            else if ((i != 0) && (sentence [i - 1] == ' ') && (sentence[i + 1] != ' ')){
                //cout << "There is a space before a letter in index " << i << " and there is another letter after a vowel in index " << i << " so variable \"firstLetterDis\" has been successfully incremented" << endl;
                firstLetterDis[21] += 1;
                break;
            }
            else if ((i != 0) && (sentence[i + 1] != ' ') && (sentence[i - 1] != ' ')){
                for (int j = 0, k = 1; j < 10 && !oneTime;j++){
                    //cout << "Iteration j = " << j << " and k = i - " << k << ". " << endl;
                    if (sentence[i - k] == listOfnumbers[j]){
                        //cout << "Case I is in index[" << i << "] is surrounded by numbers.. will keep checking if there's any letters before I can find a space" << endl;
                        k = k + 1;
                        j = 0 - 1;
                    }
                    else if (sentence [i - k] == ' '){
                        //cout << "Case I: This vowel in this index (index [" << i << "]) is the the first vowel in this word. So variable \"firstLetterDis\" has been successfully incremented." << endl;
                        firstLetterDis[21] += 1;
                        oneTime = true;
                        break;
                    }
                    else if ((sentence [i - k] != ' ') || (sentence[i - k] != listOfnumbers[j])){
                    }
                    else{
                        k = k + 1;
                    }
                oneTime = false;
                }
            oneTime = false;
            }
            else if ((i != 0) && (sentence [i + 1] == ' ') && (sentence [i - 1] != ' ')){
                //cout << "This vowel in the index " << i << " is not the first letter of this word. so variable \"firstLetterDis\" has failed to increment." << endl;
                break;
            }
            break;
        case 'w':
        case 'W':
            if (i == 0){
                firstLetterDis[22] += 1;
                break;
            }
            else if ((i != 0) && (sentence[i + 1] == ' ') && (sentence[i - 1] == ' ')){
                //cout << "There are two spaces around index " << i << " so variable \"firstLetterDis\" has been successfully incremented" << endl;
                firstLetterDis[22] += 1;
                break;
            }
            else if ((i != 0) && (sentence [i - 1] == ' ') && (sentence[i + 1] != ' ')){
                //cout << "There is a space before a letter in index " << i << " and there is another letter after a vowel in index " << i << " so variable \"firstLetterDis\" has been successfully incremented" << endl;
                firstLetterDis[22] += 1;
                break;
            }
            else if ((i != 0) && (sentence[i + 1] != ' ') && (sentence[i - 1] != ' ')){
                for (int j = 0, k = 1; j < 10 && !oneTime;j++){
                    //cout << "Iteration j = " << j << " and k = i - " << k << ". " << endl;
                    if (sentence[i - k] == listOfnumbers[j]){
                        //cout << "Case I is in index[" << i << "] is surrounded by numbers.. will keep checking if there's any letters before I can find a space" << endl;
                        k = k + 1;
                        j = 0 - 1;
                    }
                    else if (sentence [i - k] == ' '){
                        //cout << "Case I: This vowel in this index (index [" << i << "]) is the the first vowel in this word. So variable \"firstLetterDis\" has been successfully incremented." << endl;
                        firstLetterDis[22] += 1;
                        oneTime = true;
                        break;
                    }
                    else if ((sentence [i - k] != ' ') || (sentence[i - k] != listOfnumbers[j])){
                    }
                    else{
                        k = k + 1;
                    }
                oneTime = false;
                }
            oneTime = false;
            }
            else if ((i != 0) && (sentence [i + 1] == ' ') && (sentence [i - 1] != ' ')){
                //cout << "This vowel in the index " << i << " is not the first letter of this word. so variable \"firstLetterDis\" has failed to increment." << endl;
                break;
            }
            break;
        case 'x':
        case 'X':
            if (i == 0){
                firstLetterDis[23] += 1;
                break;
            }
            else if ((i != 0) && (sentence[i + 1] == ' ') && (sentence[i - 1] == ' ')){
                //cout << "There are two spaces around index " << i << " so variable \"firstLetterDis\" has been successfully incremented" << endl;
                firstLetterDis[23] += 1;
                break;
            }
            else if ((i != 0) && (sentence [i - 1] == ' ') && (sentence[i + 1] != ' ')){
                //cout << "There is a space before a letter in index " << i << " and there is another letter after a vowel in index " << i << " so variable \"firstLetterDis\" has been successfully incremented" << endl;
                firstLetterDis[23] += 1;
                break;
            }
            else if ((i != 0) && (sentence[i + 1] != ' ') && (sentence[i - 1] != ' ')){
                for (int j = 0, k = 1; j < 10 && !oneTime;j++){
                    //cout << "Iteration j = " << j << " and k = i - " << k << ". " << endl;
                    if (sentence[i - k] == listOfnumbers[j]){
                        //cout << "Case I is in index[" << i << "] is surrounded by numbers.. will keep checking if there's any letters before I can find a space" << endl;
                        k = k + 1;
                        j = 0 - 1;
                    }
                    else if (sentence [i - k] == ' '){
                        //cout << "Case I: This vowel in this index (index [" << i << "]) is the the first vowel in this word. So variable \"firstLetterDis\" has been successfully incremented." << endl;
                        firstLetterDis[23] += 1;
                        oneTime = true;
                        break;
                    }
                    else if ((sentence [i - k] != ' ') || (sentence[i - k] != listOfnumbers[j])){
                    }
                    else{
                        k = k + 1;
                    }
                oneTime = false;
                }
            oneTime = false;
            }
            else if ((i != 0) && (sentence [i + 1] == ' ') && (sentence [i - 1] != ' ')){
                //cout << "This vowel in the index " << i << " is not the first letter of this word. so variable \"firstLetterDis\" has failed to increment." << endl;
                break;
            }
            break;
        case 'y':
        case 'Y':
            if (i == 0){
                firstLetterDis[24] += 1;
                break;
            }
            else if ((i != 0) && (sentence[i + 1] == ' ') && (sentence[i - 1] == ' ')){
                //cout << "There are two spaces around index " << i << " so variable \"firstLetterDis\" has been successfully incremented" << endl;
                firstLetterDis[24] += 1;
                break;
            }
            else if ((i != 0) && (sentence [i - 1] == ' ') && (sentence[i + 1] != ' ')){
                //cout << "There is a space before a letter in index " << i << " and there is another letter after a vowel in index " << i << " so variable \"firstLetterDis\" has been successfully incremented" << endl;
                firstLetterDis[24] += 1;
                break;
            }
            else if ((i != 0) && (sentence[i + 1] != ' ') && (sentence[i - 1] != ' ')){
                for (int j = 0, k = 1; j < 10 && !oneTime;j++){
                    //cout << "Iteration j = " << j << " and k = i - " << k << ". " << endl;
                    if (sentence[i - k] == listOfnumbers[j]){
                        //cout << "Case I is in index[" << i << "] is surrounded by numbers.. will keep checking if there's any letters before I can find a space" << endl;
                        k = k + 1;
                        j = 0 - 1;
                    }
                    else if (sentence [i - k] == ' '){
                        //cout << "Case I: This vowel in this index (index [" << i << "]) is the the first vowel in this word. So variable \"firstLetterDis\" has been successfully incremented." << endl;
                        firstLetterDis[24] += 1;
                        oneTime = true;
                        break;
                    }
                    else if ((sentence [i - k] != ' ') || (sentence[i - k] != listOfnumbers[j])){
                    }
                    else{
                        k = k + 1;
                    }
                oneTime = false;
                }
            oneTime = false;
            }
            else if ((i != 0) && (sentence [i + 1] == ' ') && (sentence [i - 1] != ' ')){
                //cout << "This vowel in the index " << i << " is not the first letter of this word. so variable \"firstLetterDis\" has failed to increment." << endl;
                break;
            }
            break;
        case 'z':
        case 'Z':
            if (i == 0){
                firstLetterDis[25] += 1;
                break;
            }
            else if ((i != 0) && (sentence[i + 1] == ' ') && (sentence[i - 1] == ' ')){
                //cout << "There are two spaces around index " << i << " so variable \"firstLetterDis\" has been successfully incremented" << endl;
                firstLetterDis[25] += 1;
                break;
            }
            else if ((i != 0) && (sentence [i - 1] == ' ') && (sentence[i + 1] != ' ')){
                //cout << "There is a space before a letter in index " << i << " and there is another letter after a vowel in index " << i << " so variable \"firstLetterDis\" has been successfully incremented" << endl;
                firstLetterDis[25] += 1;
                break;
            }
            else if ((i != 0) && (sentence[i + 1] != ' ') && (sentence[i - 1] != ' ')){
                for (int j = 0, k = 1; j < 10 && !oneTime;j++){
                    //cout << "Iteration j = " << j << " and k = i - " << k << ". " << endl;
                    if (sentence[i - k] == listOfnumbers[j]){
                        //cout << "Case I is in index[" << i << "] is surrounded by numbers.. will keep checking if there's any letters before I can find a space" << endl;
                        k = k + 1;
                        j = 0 - 1;
                    }
                    else if (sentence [i - k] == ' '){
                        //cout << "Case I: This vowel in this index (index [" << i << "]) is the the first vowel in this word. So variable \"firstLetterDis\" has been successfully incremented." << endl;
                        firstLetterDis[25] += 1;
                        oneTime = true;
                        break;
                    }
                    else if ((sentence [i - k] != ' ') || (sentence[i - k] != listOfnumbers[j])){
                    }
                    else{
                        k = k + 1;
                    }
                oneTime = false;
                }
            oneTime = false;
            }
            else if ((i != 0) && (sentence [i + 1] == ' ') && (sentence [i - 1] != ' ')){
                //cout << "This vowel in the index " << i << " is not the first letter of this word. so variable \"firstLetterDis\" has failed to increment." << endl;
                break;
            }
            break;
        }
    }
//-------------------------------------------------------------------//

    cout << "# Total number of words which has at least a letter: " << wordsWithletter << endl;
    cout << "# Total number of words whose first letter is a vowel: " << WordsWithVowelFirst << endl;
    cout << "# Total number of words which contain some letter repeated at least twice: " << endl;

    cout << "# Distribution of words by length: " << endl;
    for (int i = 0; i < 16; i ++){
        cout << "# L"<< i << " = " << arrayL[i] << endl;
    }

    cout << "# Distribution of words by the first letter: " << endl;
    cout << "# a/A:  " << firstLetterDis[0] << endl;
    cout << "# b/B:  " << firstLetterDis[1] << endl;
    cout << "# c/C:  " << firstLetterDis[2] << endl;
    cout << "# d/D:  " << firstLetterDis[3] << endl;
    cout << "# e/E:  " << firstLetterDis[4] << endl;
    cout << "# f/F:  " << firstLetterDis[5] << endl;
    cout << "# g/G:  " << firstLetterDis[6] << endl;
    cout << "# h/H:  " << firstLetterDis[7] << endl;
    cout << "# i/I:  " << firstLetterDis[8] << endl;
    cout << "# j/J:  " << firstLetterDis[9] << endl;
    cout << "# k/K:  " << firstLetterDis[10] << endl;
    cout << "# l/L:  " << firstLetterDis[11] << endl;
    cout << "# m/M:  " << firstLetterDis[12] << endl;
    cout << "# n/N:  " << firstLetterDis[13] << endl;
    cout << "# o/O:  " << firstLetterDis[14] << endl;
    cout << "# p/P:  " << firstLetterDis[15] << endl;
    cout << "# q/Q:  " << firstLetterDis[16] << endl;
    cout << "# r/R:  " << firstLetterDis[17] << endl;
    cout << "# s/S:  " << firstLetterDis[18] << endl;
    cout << "# t/T:  " << firstLetterDis[19] << endl;
    cout << "# u/U:  " << firstLetterDis[20] << endl;
    cout << "# v/V:  " << firstLetterDis[21] << endl;
    cout << "# w/W:  " << firstLetterDis[22] << endl;
    cout << "# x/X:  " << firstLetterDis[23] << endl;
    cout << "# y/Y:  " << firstLetterDis[24] << endl;
    cout << "# z/Z:  " << firstLetterDis[25] << endl;
}
