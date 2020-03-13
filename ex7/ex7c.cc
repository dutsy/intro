/*
 * modprog1, 2018a
 * Ex #7c a program that finds the longest matching substring  length of string1
 * in string2
 * Written by: qussay firon
 * id: 327601779
 * login: kuchipe
 * usage example
 * input : ‫‪xxabcdyyy fgfgabc1234‬‬‬‬
 * output: 3‫‪
 */
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::setw;
//------------------------------------Global------------------------------------
//----------------------------------Constants-----------------------------------
const int N = 100;
//----------------------------------Functions-----------------------------------
//Finds longest matching substring length from str1 in str2
unsigned subStrLen(const char str1[], const char str2[],
		unsigned index1, unsigned index2);
//------------------------------------------------------------------------------
//Returns the number of consecutive characters in two arrays from a specific
//index
unsigned longestSubMatch(const char str1[], const char str2[]);
//------------------------------------Main--------------------------------------
int main() {
    char str1[N] = "";//String number 1
    char str2[N] = "";//String number 2


    cin >> setw(N) >> str1;//Fill str1 with string
    cin >> setw(N) >> str2;//Fill str2 with string

    cout << longestSubMatch(str1, str2) << endl;

    return EXIT_SUCCESS;
}
//------------------------------------------------------------------------------
unsigned longestSubMatch(const char string1[N], const char string2[N]) {
	unsigned temp;//Holds a temporally value
	unsigned longest = 0;//Holds the longest matching substring length

	//Iterating through each letter in string1 and matching it with string2
	//characters
	for (unsigned i = 0; i < strlen(string1); i++) {
		temp = 0;
		for (unsigned j = 0; j < strlen(string2); j++) {
			//If two characters are matching, check if the characters after
			//them are matching
			if (string1[i] == string2[j]) {
				temp = subStrLen(string1, string2, i, j);
			}
		}
		if (temp > longest) {//Update the longest matching substring length
			longest = temp;
		}
	}

	return longest;
}
//------------------------------------------------------------------------------
unsigned subStrLen(const char str1[], const char str2[],
				   unsigned index1, unsigned index2) {
	unsigned counter = 0;//Counts the consecutive characters

	//Checks the consecutive characters in two arrays
	while (str1[index1] == str2[index2]) {
		index1++;
		index2++;
		counter++;
		//Checks if the indexes are with in the arrays bounds
		if (index1 > strlen(str1) || index2 > strlen(str2)) {
			break;
		}
	}
	return counter;
}

