/*
 * modprog1, 2018a
 * Ex #5c a program that finds the biggest diagonal in array
 * Complexity time: ROWS*COLS while ROWS are the rows of the matrix, and
 * COLS are the columns of the matrix.
 * Written by: qussay firon
 * id: 327601779
 * login: kuchipe
 * usage example
 * input :
 * 1 1 1 1
 * -5 -6 -7 -8
 * 1 1 3 4
 * -19 -3 -1 0
 * 50 40 60 70
 * output:
 * 1
 */
#include <iostream>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;
//------------------------------------Global------------------------------------
//----------------------------------Constants-----------------------------------
const int ROWS = 5;//Holds the matrix rows size
const int COLS = 4;//Holds the matrix columns size

//----------------------------------Functions-----------------------------------
//Finds the smallest number between two
int minNum(int num1, int num2);

//Fills a matrix with "ROWS" rows and "COLS" columns
void fillMatrix(int matrix[ROWS][COLS]);

//------------------------------------Main--------------------------------------
int main() {
    int matrix[ROWS][COLS];

    //Diagonal numbers equals to the smallest number.
    int diagonals = minNum(ROWS, COLS);
    bool isBigger = true;//Checks if the diagonal is bigger
    /*
        Holds the answer for which diagonal is the biggest.
        First one is the biggest by default.
    */
    int diaNum = 1;
    //Reading value from the user
    fillMatrix(matrix);

    int temp;//Holds a temporally number
    int maxDianum = temp = matrix[0][0];//Holds the maximum number in diagonal

    //Looking for the biggest diagonal
    for (int d = 1; d < diagonals && isBigger; d++) {
        for (int i = 0, j = d; j >= 0; i++, j--) {
            //Looks for the biggest number in diagonal
            if (matrix[i][j] >= maxDianum) {
                if (matrix[i][j] > temp) {
                    temp = matrix[i][j];
                }
            } else {//If we reached a smaller diagonal stop
                isBigger = false;
            }
        }

        maxDianum = temp;//Updates the biggest number

        if (isBigger) {//If diagonal is bigger increase diaNum
            diaNum++;
        }

    }

    cout << diaNum << endl;//Prints the answer to user

    return EXIT_SUCCESS;
}


//------------------------------------------------------------------------------

int minNum(int num1, int num2) {
    if (num1 < num2) {
        return num1;
    }
    return num2;
}

//------------------------------------------------------------------------------

void fillMatrix(int matrix[ROWS][COLS]) {
    //Fills rows and columns
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cin >> matrix[i][j];
        }
    }
}

