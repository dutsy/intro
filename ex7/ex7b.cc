/*
 * modprog1, 2018a
 * Ex #7b a program that finds the longest matching words from text with a
 * dictionary and return the matching start location and length
 * in string2
 * Written by: qussay firon
 * id: 327601779
 * login: kuchipe
 * usage example
 * input :
 * aa bb cc dd ee ff gg hh ii .
 * tt Aa eE s hh Ii gg‬‬‬‬
 * output: 11 8‫‪
 */
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;
using std::setw;
//------------------------------------Global------------------------------------
//----------------------------------Constants-----------------------------------
const int MAX_STRS = 10;//Dictionary length
const int MAX_STR_LEN = 8;//Maximum word length in dictionary
const int MAX_TEXT_LEN = 100;//Maximum text length
//------------------------------------------------------------------------------
int dictSize;
//----------------------------------Functions-----------------------------------
//This function fills dictionary with words till it is full or find a dot
unsigned fillDict(char[MAX_STRS][MAX_STR_LEN]);
//------------------------------------------------------------------------------
//This function finds the longest matching string words from text into dict
void longestSubMatch(const char dict[MAX_STRS][MAX_STR_LEN],
					 const char text[MAX_TEXT_LEN] ,unsigned &loc, unsigned &len);
//------------------------------------------------------------------------------
unsigned findWord(const char charArray[], char word[], int startFrom);
//------------------------------------------------------------------------------
//This function converts char array to lower case
void strToLower(char str[]);
//------------------------------------Main--------------------------------------
int main() {
	char dict[MAX_STRS][MAX_STR_LEN];
	char text[MAX_TEXT_LEN];

	dictSize = fillDict(dict);
	//Flushing input buffer for getline
	cin.clear();
	cin.ignore();
	//Filling text array with data from user
	cin.getline(text, MAX_TEXT_LEN);
	//Converting text array to lower case
	strToLower(text);

	unsigned loc = 0;
	unsigned len = 0;
	longestSubMatch(dict, text, loc, len);
	cout << loc << " " << len << endl;
	return EXIT_SUCCESS;
}

unsigned fillDict(char dict[MAX_STRS][MAX_STR_LEN]) {
	unsigned i;

	//Fills dictionary with words, each word per row
	for (i = 0; i < MAX_STRS; i++) {
		char str[MAX_STR_LEN];
		cin >> setw(MAX_STR_LEN) >> str;
		if (strcmp(str, ".") == 0) {
			return i;
		}
		strToLower(str);
		strcpy(dict[i], str);
	}
	return i;
}
//------------------------------------------------------------------------------
unsigned findWord(const char charArray[], char word[], int startFrom) {
	unsigned wordLen = 0;
	bool isWord = false;

	//Finds a single word from starting index in char array
	for (unsigned i = startFrom; i < strlen(charArray); i++) {
		if (isspace(charArray[i])) {
			if (isWord) {
				word[wordLen] = '\0';
				return wordLen;
			}
			continue;
		} else {
			isWord = true;
			word[wordLen] = charArray[i];
			wordLen++;
		}
	}
	return wordLen;
}
//------------------------------------------------------------------------------
void strToLower(char str[]) {
	//Converts each letter to lower case
	for (unsigned i = 0; i < strlen(str); i++) {
		str[i] = tolower(str[i]);
	}
}
//------------------------------------------------------------------------------
void longestSubMatch(const char dict[MAX_STRS][MAX_STR_LEN],
					const char text[MAX_TEXT_LEN] ,unsigned &loc, unsigned &len)
{
	char word[MAX_TEXT_LEN];
	unsigned i = 0;
	// for finding local longest string
	int currentMatch=-1;
	int currentMatchLen=-1;
	// to store the longest string
	int maxMatchIndex = -1;
	int maxMatchLen= -1;
	// flag to tell if substring do match
	bool isMatching = false;
	// to store how many spaces
	int spaceCount = 0;

	//Iterates thought text words and matches them with dictionary words
	while(i < strlen(text)) {
		isMatching = false;
		if (isspace(text[i])) {
			spaceCount++;
			if(currentMatchLen > -1) {
				currentMatchLen ++;
			}
			i++;
			continue;
		}

		int len = findWord(text, word, i);//Length of the found word

		//If word is equal or smaller to dictionary maximum word length
		if(len <= MAX_STR_LEN) {
			//Find the matching word in the dictionary
			for(int j = 0 ;j < dictSize; j++) {
				if(strcmp(word,dict[j]) == 0) {
					spaceCount = 0;
					isMatching = true;
					if(currentMatch == -1) {
						currentMatch = i;
						currentMatchLen = len;
					} else {
						currentMatchLen+=len;
					}
					break;
				}
			}
		}
		//If we find a match we want to check if it is the longest
		if(!isMatching) {
			currentMatchLen -=spaceCount;
			if(currentMatchLen > maxMatchLen) {
				maxMatchLen = currentMatchLen;
				maxMatchIndex = currentMatch;
			}
			currentMatchLen = -1;
			currentMatch = -1;
		}
		//Step to the next word index
		i += len;
	}

	//We will check if the local maximum is longest than the current maximum
	if(currentMatchLen > maxMatchLen) {
		maxMatchLen = currentMatchLen;
		maxMatchIndex = currentMatch;
	}
	//Saves starting index of match and its length
	loc = maxMatchIndex;
	len = maxMatchLen;
}

