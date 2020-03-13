/*
 * modprog1, 2018a
 * Ex #6b a program that finds two kind of containers for array:
 * 1-Container that contains all other rows numbers.
 * 2-Container that contains all the rows numbers with equal or more occurrences
 * zero is counted as a empty cell.
 * Complexity time: ROWS^2*COLS^2 while ROWS are the rows of the matrix, and
 * COLS are the columns of the matrix.
 * Written by: qussay firon
 * id: 327601779
 * login: kuchipe
 * usage example
 * input :
 * 1 1 1 1 1
 * 1 1 1 1 1
 * 1 1 1 1 1
 * 1 1 1 1 1
 * output:
 * 0
 * 0
 */
#include <iostream>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;
//------------------------------------Global------------------------------------
//----------------------------------Constants-----------------------------------
const int ROWS = 4;//Matrix rows
const int COLS = 5;//Matrix columns

//----------------------------------Functions-----------------------------------
//Fills user data into matrix
void readData(int matrix[ROWS][COLS]);
//------------------------------------------------------------------------------
//Checks if row2 is subset of row1, return true if yes otherwise false
bool isSubRow(const int row1[COLS], const int row2[COLS]);
//------------------------------------------------------------------------------
/*
Checks if rowNum contains all the other rows,return true if yes otherwise false
*/
bool isContainer(const int rowNum, const int matrix[ROWS][COLS]);
//------------------------------------------------------------------------------
//Returns the number of row which contains all others, if none return -1
int getContainerRow(const int matrix[ROWS][COLS]);
//------------------------------------------------------------------------------
/*
* Checks if row2 is subset of row1 with ignoring zeros and matching occurrences
* of row1 with row2 if row1 occurrences are bigger or equal return true if yes
* otherwise false
*/
bool isSubRowZero (const int row1[COLS], const int row2[COLS]);
//------------------------------------------------------------------------------
/*
* Return the occurrences of numbers in array to a new array with occurrences
* Example {1,1,2,2,2} returns {2, 2, 3, 3, 3}
*/
void occurrences (const int matrix[ROWS][COLS], int occ[COLS]);
//------------------------------------------------------------------------------
/*
* Checks if rowNum contains all the other rows with ignoring zeros,
* return true if yes otherwise false
*/
bool isContainerZero(int rowNum, const int matrix[ROWS][COLS]);
//------------------------------------------------------------------------------
/*
 * Returns the number of row which contains all others with ignoring zero, if
 * none return -1
*/
int getContainerRowZero(const int matrix[ROWS][COLS]);
//------------------------------------------------------------------------------
//Prints two integer results
void printResult(int result1, int result2);
//------------------------------------Main--------------------------------------
int main () {
    int matrix[ROWS][COLS];
    readData(matrix);
    int containerRow = getContainerRow(matrix);
    int containerRowZero = getContainerRowZero(matrix);
    printResult(containerRow, containerRowZero);
    return EXIT_SUCCESS;
}
//------------------------------------------------------------------------------
void readData (int matrix[ROWS][COLS]) {
    //Fill matrix with data
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cin >> matrix[i][j];
        }
    }
}
//------------------------------------------------------------------------------
bool isSubRow(const int row1[COLS], const int row2[COLS]) {
    bool isSubSet;//Holds true if row2 is subset of row1 otherwise false

    //Checks if row2 is subset of row1
    for (int i = 0; i < COLS; i++) {
        isSubSet = false;
        for (int j = 0; j < COLS; j++) {
            if (row2[i] == row1[j]) {
                isSubSet = true;
                break;
            }
        }
        if (!isSubSet) {
            return false;
        }
    }
    return true;
}
//------------------------------------------------------------------------------
bool isContainer (int rowNum, const int matrix[ROWS][COLS]) {
    //Checks if rowNum is inside of matrix
    if (rowNum >= ROWS) {
        exit(EXIT_FAILURE);
    }
    //Checks if rowNum contains all other rows
    for (int i = 0; i < ROWS; i++) {
        if (rowNum == i) {//If it 100% subset if it is the same row
            continue;
        }
        if (!isSubRow(matrix[rowNum], matrix[i])) {
            return false;
        }
    }
    return true;
}
//------------------------------------------------------------------------------
int getContainerRow (const int matrix[ROWS][COLS]) {
    //Iterating though all rows of matrix
    for (int i = 0; i < ROWS; i++) {
        if (isContainer(i, matrix)) {
            return i;
        }
    }
    return -1;
}
//------------------------------------------------------------------------------
void occurrences (const int row[COLS], int occ[COLS]) {
    int temp;//Temporally variable

    //Saving numbers occurrences
    for (int i = 0; i < COLS; i++) {
        temp = 0;
        for (int j = 0; j < COLS; j++) {
            if (row[i] == row[j]) {
                temp++;
            }
        }
        occ[i] = temp;
    }
}
//------------------------------------------------------------------------------
bool isSubRowZero (const int row1[COLS], const int row2[COLS]) {
    int rowOccur1[COLS];
    int rowOccur2[COLS];
    occurrences(row1, rowOccur1);//Getting occurrences of numbers
    occurrences(row2, rowOccur2);//Getting occurrences of numbers
    bool isSubSet;//Holds true if row2 is subset of row1 otherwise false

    //Checks if row2 is subset of row1
    for (int i = 0; i < COLS; i++) {
        isSubSet = false;
        //Ignore zeros
        if (row2[i] == 0) {
            continue;
        }
        for (int j = 0; j < COLS; j++) {
            if (row2[i] == row1[j] && rowOccur1[j] >= rowOccur2[i]) {
                isSubSet = true;
                break;
            }
        }
        if (!isSubSet) {
            return false;
        }
    }
    return true;
}
//------------------------------------------------------------------------------
bool isContainerRowZero (int rowNum, const int matrix[ROWS][COLS]) {
    //Checks if rowNum is inside of matrix
    if (rowNum >= ROWS) {
        exit(EXIT_FAILURE);
    }
    //Checks if rowNum contains all other rows
    for (int i = 0; i < ROWS; i++) {
        if (rowNum == i) {//If it 100% subset if it is the same row
            continue;
        }
        if (!isSubRowZero(matrix[rowNum], matrix[i])) {
            return false;
        }
    }
    return true;
}
//------------------------------------------------------------------------------
int getContainerRowZero (const int matrix[ROWS][COLS]) {
    //Iterating though all rows of matrix
    for (int i = 0; i < ROWS; i++) {
        if (isContainerRowZero(i, matrix)) {
            return i;
        }
    }
    return -1;
}
//------------------------------------------------------------------------------
void printResult(int result1, int result2) {
    cout << result1 << endl;
    cout << result2 << endl;
}

