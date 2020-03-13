/*
 * modprog1, 2018a
 * Ex #5a a program that finds the row that contains the greatest sum of numbers
 * and the column that contains the the greatest sum of numbers
 * Complexity time: ROWS*COLS while ROWS are the rows of the matrix, and
 * COLS are the columns of the matrix.
 * Written by: qussay firon
 * id: 327601779
 * login: kuchipe
 * usage example
 * input :
 * 9 30 42 11 21
 * 34 22 13 21 11
 * 8 7 5 3 2
 * 2 2 3 -9 1
 * output: 0 2
 */
#include <iostream>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;

//------------------------------------Global------------------------------------
//----------------------------------Constants-----------------------------------
const int ROWS = 4;//Holds the matrix rows size
const int COLS = 5;//Holds the matrix columns size

//------------------------------------Main--------------------------------------
int main() {
    int matrix[ROWS][COLS];

    int sumOfRow, //Holds sum of row
        sumOfCol,//Holds sum of column
        numOfMaxSumRow,//Holds the highest sum row number
        numOfMaxSumCol,//Holds the highest sum column number
        temp = 0;//Temporally variable

    for (int i = 0; i < ROWS; i++) {//Takes input from the user
        for (int j = 0; j < COLS; j++) {
            cin >> matrix[i][j];
        }
    }

    //Finds the highest sum row number
    for (int i = 0; i < ROWS; i++) {
        temp = 0;
        for (int j = 0; j < COLS; j++) {
            temp += matrix[i][j];
        }
        if (temp > sumOfRow) {
            sumOfRow = temp;
            numOfMaxSumRow = i;
        }
    }

    //Finds the highest sum column number
    for (int i = 0; i < COLS; i++) {
        temp = 0;
        for (int j = 0; j < ROWS; j++) {
            temp += matrix[j][i];
        }
        if (temp > sumOfCol) {
            sumOfCol = temp;
            numOfMaxSumCol = i;
        }
    }

    //Prints the results to user
    cout << numOfMaxSumRow << " " << numOfMaxSumCol << endl;

    return EXIT_SUCCESS;
}

