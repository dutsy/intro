/*
* modprog1, 2018a
* Ex #9a a program that solves Sudoku,
* Written by: qussay firon
* id: 327604779
* login: kuchipe
* usage example
* input:
* 0 0 1
* 0 1 2
* 0 2 3
* 1 0 4
* 2 1 4
* 1 3 1
* 3 0 2
* 3 3 3
* -1
* output:
* 1 2 3 4
* 4 3 2 1
* 3 4 1 2
* 2 1 4 3
*/
#include <iostream>
#include <cstdlib>
//Using section
//------------------------------------------------------------------------------
using std::cin;
using std::cout;
using std::endl;
//Constants
//------------------------------------------------------------------------------
const int N = 2;
const int N_SQ = N*N;
const int MIN_VAL = 1;
const int EXIT_VAL = -1;
const int EMPTY = 0;
//Functions
//------------------------------------------------------------------------------
//Fills the Sudoku with numbers from 1 to N_SQ
void fill(int sudoku[][N_SQ]);
//------------------------------------------------------------------------------
//Checks if each number in row appeared once
bool isRowOk (const int row[N_SQ]);
//------------------------------------------------------------------------------
//Checks if each number in column appeared once
bool isColumnOk (const int matrix[][N_SQ], int colNum);
//------------------------------------------------------------------------------
//Checks if each number in square appeared once
bool isSquareOk (const int matrix[][N_SQ], int r, int c);
//------------------------------------------------------------------------------
//Returns true if Sudoku is valid otherwise false
bool isSudokuVaild (const int matrix[][N_SQ]);
//------------------------------------------------------------------------------
//Solve Soduku
bool solve(int sudoku[][N_SQ],int i,int j);
bool solve(int sudoku[][N_SQ]);
//------------------------------------------------------------------------------
//Prints the Sudoku board
void printSudoku(const int sudoku[][N_SQ]);
//------------------------------------------------------------------------------
//Main
int main() {
    int sudoku[N_SQ][N_SQ] = {0};//Fill array with zeros
    fill(sudoku);
    solve(sudoku);
    printSudoku(sudoku);
    return EXIT_SUCCESS;
}
//------------------------------------------------------------------------------
void fill(int sudoku[][N_SQ]) {
    int row;//Sudoku row
    int col;//Sudoku column
    int value;//Entered value
    while (true) {
    cin >> row;
    if (row == EXIT_VAL)
    break;
    cin >> col >> value;
    if (row < 0 || row > N_SQ-1 || col < 0 || col > N_SQ-1 ||
    value > N_SQ || value < MIN_VAL
    ) {
    continue;
    } else {
    sudoku[row][col] = value;
    }
    }
}
bool isRowOk(const int row[]) {
    int temp;
    int appearances;//Holds the appearances
    bool isValid = true;
    //Checks if each number has appeared once
    for (int i = 0; i < N_SQ; i++) {
        appearances = 0;
        temp = row[i];
        //Ignore zeros
        if (temp == 0) {
            continue;
        }
        for (int j = 0; j < N_SQ; j++) {
            if (temp == row[j]) {
                appearances++;
            }
            if (appearances == 2) {
                isValid = false;
                break;
            }
        }
    }
    return isValid;
}
//------------------------------------------------------------------------------
bool isColumnOk(const int matrix[][N_SQ], int colNum) {
    int temp;
    int appearances;//Holds the appearances
    bool isValid = true;
    //Checks if each number has appeared once
    for (int i = 0; i < N_SQ; i++) {
        appearances = 0;
        temp = matrix[i][colNum];
        //Ignore zeros
        if (temp == 0) {
            continue;
        }
        for (int j = 0; j < N_SQ; j++) {
            if (temp == matrix[j][colNum]) {
                appearances++;
            }
            if (appearances == 2) {
                isValid = false;
                break;
            }
        }
    }
    return isValid;
}
//------------------------------------------------------------------------------
bool isSquareOk(const int matrix[][N_SQ], int r, int c) {
    /******************** Finds from which square to start ********************/
    int rowStartingIndex = ((r / N) * N);
    int colStartingIndex = ((c / N) * N);
    /**************************************************************************/
    int squareNumbers[N_SQ];//Will Contain all the square numbers
    int squareNumbersIndex = 0;//Holds the squareNumbers index
    //Fills squareNumbers array
    for (int i = rowStartingIndex; i < rowStartingIndex + N; i++) {
        for (int j = colStartingIndex; j < colStartingIndex + N; j++) {
            squareNumbers[squareNumbersIndex] = matrix[i][j];
            squareNumbersIndex++;
        }
    }
    return isRowOk(squareNumbers);//Checks if square is ok
}
//------------------------------------------------------------------------------
bool isSudokuVaild(const int matrix[][N_SQ]) {
    bool isSudokuValid = true;
    //Checks if Sudoku rows, columns and squares are ok
    for (int i = 0; i < N_SQ; i++) {
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
    return isSudokuValid ;
}
//------------------------------------------------------------------------------
bool solve(int sudoku[][N_SQ],int i,int j) {
if(i == N_SQ) {
//CHECK IF VALID
return isSudokuVaild(sudoku);
} else {
if(j == N_SQ) {
return solve(sudoku, i + 1, 0);
} else {
if(sudoku[i][j] == EMPTY) {//Fill empty slots
bool result = false;
for(int k = 1; k <= 4; k++) {//Try all possibilities
sudoku[i][j] = k;
result = solve(sudoku, i, j+1) || result;
if(result == true)
return true;
sudoku[i][j] = EMPTY;//Reset if fail
}
return result;
} else {
return solve(sudoku, i, j+1);
}
}
}
}
//------------------------------------------------------------------------------
bool solve(int sudoku[][N_SQ]) {
return solve(sudoku, 0, 0);
}
//------------------------------------------------------------------------------
void printSudoku(const int sudoku[][N_SQ]) {
    for (int i = 0; i < N_SQ; i++) {
        for (int j = 0; j < N_SQ; j++) {
            cout << sudoku[i][j] << " ";
        }
        cout << endl;
    }
}
