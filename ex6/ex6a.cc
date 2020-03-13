/*
 * modprog1, 2018a
 * Ex #6a a program that finds the row that contains the greatest sum of numbers
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

using std::cin;
using std::cout;
using std::endl;

//------------------------------------Global------------------------------------
//----------------------------------Constants-----------------------------------

const int ROWS = 4;//Matrix rows number
const int COLS = 5;//Matrix Columns number
//----------------------------------Functions-----------------------------------
//Reads data from the user and fills it in the matrix
void readData(int matrix[ROWS][COLS]);
//------------------------------------------------------------------------------
//Calculates the sum of numbers in a row
int rowSum(const int row[]);
//------------------------------------------------------------------------------
//Calculates the sum of numbers in a column
int colSum(const int matrix[][COLS], int colNum);
//------------------------------------------------------------------------------
//Finds which row of matrix that contains the maximum sum of numbers
int maxSumRow(const int matrix[][COLS]);
//------------------------------------------------------------------------------
//Finds which column of matrix that contains the maximum sum of numbers
int maxSumCol(const int matrix[][COLS]);
//------------------------------------------------------------------------------
//Prints the maximum sum of numbers row and column to user
void printResult(int r1, int r2);
//------------------------------------Main--------------------------------------
int main() {
    int matrix[ROWS][COLS];
    readData(matrix);
    int maxSumRowNum = maxSumRow(matrix);
    int maxSumColNum = maxSumCol(matrix);
    printResult(maxSumRowNum, maxSumColNum);
    return EXIT_SUCCESS;
}
//------------------------------------------------------------------------------
void readData(int matrix[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            cin >> matrix[i][j];
        }
    }
}
//------------------------------------------------------------------------------
int rowSum(const int row[]) {
    int sum = 0;//Holds the sum of row numbers

    for (int i = 0; i < COLS; i++) {
        sum += row[i];
    }
    return sum;
}
//------------------------------------------------------------------------------
int colSum(const int matrix[][COLS], int colNum) {
    int sum = 0;//Holds the sum of column numbers

    if (colNum >= COLS) {//Because it starts from 0
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < ROWS; i++) {
        sum += matrix[i][colNum];
    }
    return sum;
}
//------------------------------------------------------------------------------
int maxSumRow(const int matrix[][COLS]) {
    int maxSum;//Holds the maximum sum
    int temp;//Holds a temporally number
    int row;//Holds row number
    for (int i = 0; i < ROWS; i++) {
        temp = rowSum(matrix[i]);
        if (i == 0 || temp > maxSum) {
            maxSum = temp;
            row = i;
        }
    }
    return row;
}
//------------------------------------------------------------------------------
int maxSumCol(const int matrix[][COLS]) {
    int maxSum;//Holds the maximum sum
    int temp;//Holds a temporally number
    int column;//Holds column number

    for (int i = 0; i < COLS; i++) {
        temp = colSum(matrix, i);
        if (i == 0 || temp > maxSum) {
            maxSum = temp;
            column = i;
        }
    }
    return column;
}
//------------------------------------------------------------------------------
void printResult(int r1, int r2) {
    cout << r1 << " " << r2 << endl;
}

