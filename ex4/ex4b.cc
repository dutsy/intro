/*
 * modprog1, 2018a
 * Ex #4b a program that locates the maximum frequent numbers in array
 * Written by: qussay firon
 * id: 327601779
 * login: kuchipe
 * usage example
 * input: 3 3 6 4 2 4 0 1 1 7
 * output:
 * 3
 * 4
 * 1
 */
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

//----------------------------------Constants----------------------------------
int const SIZE = 10; // Matrix size

//------------------------------------Main-------------------------------------
int main() {
    int matrix[SIZE];
    int maximums[SIZE] = {0};
    int maximum = 0, //Holds the maximum number of appearances
        temp,//Holds maximum appearances temporally
        maximumsCurIndex = 0;//Maximum capacity


    for (int i = 0; i < SIZE; i++) {//Taking values from the user
        cin >> matrix[i];
    }

    for (int i = 0; i < SIZE; i++) {//Finds the most repeated number
        temp = 0;
        for (int j = 0; j < SIZE; j++) {//Checks one array index with the
            //whole array
            if (matrix[i] == matrix[j]) {//If index of array equals other
                //index increase temp
                temp++;
            }
        }
        if (temp > maximum) {//If the temporally maximum is bigger than
            //maximum set it to maximum
            maximum = temp;
        }
    }

    bool isFound;
    for (int i = 0; i < SIZE; i++) {
        temp = 0;
        int currentNumber = matrix[i]; //value of index
        // if the maximum exists , we can skip the number
        isFound = false; // set isFound to false
        for (int k = 0; k < maximumsCurIndex; k++) {//Checks duplicates
            if (currentNumber == maximums[k]) {
                isFound = true;
                break;
            }

        }


        if (isFound)//If duplicate is found skip
            continue;

        for (int j = 0; j < SIZE; j++) {
            if (currentNumber == matrix[j]) {
                temp++;
            }
        }

        if (temp == maximum) {//If the appearances equal maximum
            maximums[maximumsCurIndex++] = currentNumber;//Add the found
            //maximum to maximums array
            cout << currentNumber << endl; //Print the maximums
        }
    }
    return EXIT_SUCCESS;
}

