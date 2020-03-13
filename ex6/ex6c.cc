/*
 * modprog1, 2018a
 * Ex #6c a program that checks if Sudoku is valid,
 * if output is one this mean it is valid else if it is 0 this means its invalid
  * Complexity time: N^6 or N_SQUARE^3 while N_SQUARE is the Sudoku size.
 * Written by: qussay firon
 * id: 327601779
 * login: kuchipe
 * usage example
 * input :
 * 1 2 3 4 5 6 7 8 9
 * 2 3 4 5 6 7 8 9 1
 * 3 4 5 6 7 8 9 1 2
 * 4 5 6 7 8 9 1 2 3
 * 5 6 7 8 9 1 2 3 4
 * 6 7 8 9 1 2 3 4 5
 * 7 8 9 1 2 3 4 5 6
 * 8 9 1 2 3 4 5 6 7
 * 9 1 2 3 4 5 6 7 8
 * output: 0
 */
#include <iostream>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;
//------------------------------------Global------------------------------------
//----------------------------------Constants-----------------------------------

const int N = 3;//Sudoku sub-square size
const int N_SQUARE = N*N;//Sudoku size

//----------------------------------Functions-----------------------------------
//Reads data into the matrix between 0 and N_SQUARE
void readData(int matrix[N_SQUARE][N_SQUARE]);
//------------------------------------------------------------------------------
//Checks if each number in row appeared once
bool isRowOk (const int row[N_SQUARE]);
//------------------------------------------------------------------------------
//Checks if each number in column appeared once
bool isColumnOk (const int matrix[][N_SQUARE], int colNum);
//------------------------------------------------------------------------------
//Checks if each number in square appeared once
bool isSquareOk (const int matrix[][N_SQUARE], int r, int c);
//------------------------------------------------------------------------------
//Prints 1 if Sudoku is valid 0 otherwise
void printIsSudokuVaild (const int matrix[][N_SQUARE]);
//------------------------------------Main--------------------------------------
int main () {
    int matrix[N_SQUARE][N_SQUARE];
    readData(matrix);
    printIsSudokuVaild(matrix);
    return EXIT_SUCCESS;
}

//------------------------------------------------------------------------------
void readData(int matrix[N_SQUARE][N_SQUARE]) {
    int col = 0;//Counter for rows and columns
    int value;//Holds the input value

    for (int row = 0; row < N_SQUARE; row++) {
        col = 0;
        while (col < N_SQUARE) {
            cin >> value;
            //Taking values between 0 and N_SQUARE
            if (value >= 0 && value <= N_SQUARE) {
                matrix[row][col] = value;
                col++;
            }
        }
    }
}
//------------------------------------------------------------------------------
bool isRowOk(const int row[]) {
    int temp;
    int appearances;//Holds the appearances
    bool isValid = true;
    //Checks if each number has appeared once
    for (int i = 0; i < N_SQUARE; i++) {
        appearances = 0;
        temp = row[i];
        //Ignore zeros
        if (temp == 0) {
            continue;
        }
        for (int j = 0; j < N_SQUARE; j++) {
            if (appearances == 2) {
                isValid = false;
                break;
            }
            if (temp == row[j]) {
                appearances++;
            }
        }
    }
    return isValid;
}
//------------------------------------------------------------------------------
bool isColumnOk(const int matrix[][N_SQUARE], int colNum) {
    int temp;
    int appearances;//Holds the appearances
    bool isValid = true;
    //Checks if each number has appeared once
    for (int i = 0; i < N_SQUARE; i++) {
        appearances = 0;
        temp = matrix[i][colNum];
        //Ignore zeros
        if (temp == 0) {
            continue;
        }
        for (int j = 0; j < N_SQUARE; j++) {
            if (appearances == 2) {
                isValid = false;
                break;
            }
            if (temp == matrix[j][colNum]) {
                appearances++;
            }
        }
    }
    return isValid;
}
//------------------------------------------------------------------------------
bool isSquareOk(const int matrix[][N_SQUARE], int r, int c) {
    /******************** Finds from which square to start ********************/
    int rowStartingIndex = ((r / N) * N);
    int colStartingIndex = ((c / N) * N);
    /**************************************************************************/
    int squareNumbers[N_SQUARE];//Will Contain all the square numbers
    int squareNumbersIndex = 0;//Holds the squareNumbers index

    //Fills squareNumbers array
    for (int i = rowStartingIndex; i < rowStartingIndex + 3; i++) {
        for (int j = colStartingIndex; j < colStartingIndex + 3; j++) {
            squareNumbers[squareNumbersIndex] = matrix[i][j];
            squareNumbersIndex++;
        }
    }
    return isRowOk(squareNumbers);//Checks if square is ok
}
//------------------------------------------------------------------------------
void printIsSudokuVaild(const int matrix[][N_SQUARE]) {
    bool isSudokuValid = true;
    //Checks if Sudoku rows, columns and squares are ok
    for (int i = 0; i < N_SQUARE; i++) {
        if (!isRowOk(matrix[i])) {
            isSudokuValid = false;
            break;
        }
        if (!isColumnOk(matrix, i)) {
            isSudokuValid = false;
            break;
        }
        if (i % N == 0) {
            if (!isSquareOk(matrix, i, i)) {
                isSudokuValid = false;
                break;
            }
        }
    }

    //Prints if Sudoku is valid or not
    cout << isSudokuValid << endl;
}

