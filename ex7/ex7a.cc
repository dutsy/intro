/*
 * modprog1, 2018a
 * Ex #7a a program that prints upper case and replaces string of given input
 * Written by: qussay firon
 * id: 327601779
 * login: kuchipe
 * usage example
 * input : abcabc a
 * output:
 * BCABC
 * bcbc
 */
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cctype>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;
using std::setw;
//------------------------------------Global------------------------------------
//----------------------------------Constants-----------------------------------
const int MAX_STR_LEN = 100;
//----------------------------------Functions-----------------------------------
/*
 * Picks only letters from str and converts them to capital then put them into
 * newStr
*/
void getCaps(const char str[], char newStr[MAX_STR_LEN]);
//------------------------------------------------------------------------------
//Removes chars2 characters from char1 characters, the new string is in newStr
void strRemove(const char str1[], const char str2[], char newStr[]);
//------------------------------------Main--------------------------------------
int main() {
    char str1[MAX_STR_LEN];
    char str2[MAX_STR_LEN];
    char str3[MAX_STR_LEN];//Holds capital letters result from str1
    char str4[MAX_STR_LEN];//Holds the new data that will come from strRemove

    cin >> str1;//Fill data into str1
    cin >> str2;//Fill data into str2

    getCaps(str1, str3);
    strRemove(str1, str2, str4);
    cout << str3 << endl;
    cout << str4 << endl;

    return EXIT_SUCCESS;
}
//------------------------------------------------------------------------------
void getCaps(const char str[], char newStr[]) {
    int curIndex = 0;//Holds the newStr last index

    //Fill capital letters to newStr
    for (int i = 0; i < strlen(str); i++) {
        if (isalpha(str[i])) {
            newStr[curIndex] = toupper(str[i]);
            curIndex++;
        }
    }

}
//------------------------------------------------------------------------------
void strRemove(const char str1[], const char str2[], char newStr[]) {
    bool isToFill;//Holds is character should be filled in the newStr or not
    int curIndex = 0;//Holds the newStr last index

    //Deletes characters from str1 that exists in str2
    for (int i = 0; i < strlen(str1); i++) {
        isToFill = true;
        for (int j = 0; j < strlen(str2); j++) {
            if (str1[i] == str2[j]) {
                isToFill = false;
                break;
            }
        }
        if (isToFill) {
            newStr[curIndex] = str1[i];
            curIndex++;
        }
    }
}

