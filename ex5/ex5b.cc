/*
 * modprog1, 201a
 * Ex #5b a program that finds two kind of containers for array:
 * 1-Container that contains all other rows numbers.
 * 2-Container that contains all the rows numbers with equal or more occurrences
 * zero is counted as a empty cell.
 * Complexity time: ROWS*COLS^2 while ROWS are the rows of the matrix, and
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

using std::cout;
using std::endl;
using std::cin;

//------------------------------------Global------------------------------------

//----------------------------------Constants-----------------------------------
const int ROWS = 4;//Holds the matrix rows size
const int COLS = 5;//Holds the matrix columns size

//-----------------------------------Functions----------------------------------

//Fills a matrix with "ROWS" rows and "COLS" columns
void fillMatrix(int matrix[ROWS][COLS]);

/*
Finds unique numbers in 2d array, it can hold 5 numbers as maximum, if there
is more -1 will be returned. The maxOcc contains in each cell what is the
maximum occurrences of a number

*/
int arrUniqueNums(int matrix[ROWS][COLS],int uniqueNums[COLS],int maxOcc[COLS]
                  ,bool ignoreZero);
/*
 Checks which row of matrix contains all the other rows if none return -1
 If the parameter ignoreZero is passed as true, the function will ignore zeros
 and it will check if the number of occurrences of all the container row numbers
 are equal or bigger than the contained row numbers

*/
int contRow(int matrix[ROWS][COLS], bool ignoreZero);

//------------------------------------Main--------------------------------------
int main() {
    int matrix[ROWS][COLS]; //Input matrix
    fillMatrix(matrix);
    int row = contRow(matrix, false);//Normal container row
    int rowIZ = contRow(matrix, true); //Container row with ignored zeros
    cout << row << endl << rowIZ << endl;
//    printResult(row, rowNZ);
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

//-----------------------------------------------------------------------------

int arrUniqueNums(int matrix[ROWS][COLS],int uniqueNums[COLS],int maxOcc[COLS]
                  ,bool ignoreZero){
    int uniqueNumIndex = 0; //The unique number index
    int num;//Holds one of the matrix numbers
    bool isUnique;//Holds if the number is unique or not
    bool isZero = ignoreZero;//Check if zero exists or not

    for (int i = 0; i < ROWS; i++) {//Iterates through rows
            // we need a key value arrays
            int keys[COLS] = {0};
            int values[COLS] = {0};
            int keysCurrentIndex = 0;
        for (int j = 0; j < COLS; j++) {//Iterates through columns
            num = matrix[i][j];//Current number

            if (num == 0) {//Checks if zero is unique number.
                if (!isZero) {
                    isZero = true;
                    if (uniqueNumIndex == COLS) {
                        return -1;
                    }
                    uniqueNumIndex++;
                }
                break;
            }

            // we find the index of the number in the keys and update the
            // occurrences
            bool isKeyExist = false;
            for(int k = 0; k < keysCurrentIndex; k++) {
                if(keys[k] ==  num) {
                    values[k]++;
                    keysCurrentIndex++;
                    isKeyExist=true;
                    break;
                }
            }
            if(!isKeyExist) {
              keys[keysCurrentIndex] = num;
              values[keysCurrentIndex]++;
              keysCurrentIndex++;
            }

            isUnique = true;
            //Checks unique numbers
            for (int k = 0; k < COLS; k++) {
                if (num == uniqueNums[k]) {
                    isUnique = false;
                    break;
                }
            }
            //If the number is unique add it to unique numbers
            if (isUnique) {
                if (uniqueNumIndex == COLS) {
                        return -1;
                    }
                uniqueNums[uniqueNumIndex] = num;
                uniqueNumIndex++;
            }
        }
        // we find the max occurrences for this row
        int maxOccurrences = 0;
        for(int j =0; j < keysCurrentIndex; j++) {
            if(values[j] > maxOccurrences) {
                maxOccurrences = values[j];
            }
        }
        // we updated the max occurrences for this row
        maxOcc[i] = maxOccurrences;
    }
    return uniqueNumIndex;
}

//------------------------------------------------------------------------------

int contRow(int matrix[ROWS][COLS], bool ignoreZero) {
    int uniqueNums[COLS] = {0};
    int maxOcc[COLS] = {0};

    int currNum;//Holds one of the unique numbers
    bool isFound;//Holds if the number is found or not

    int uniqueSize = arrUniqueNums(matrix, uniqueNums,maxOcc, ignoreZero);
    //If unique numbers a re bigger than columns there is no container
    if (uniqueSize == -1) {
        return -1;
    }
    //Iterates through matrix rows
    for (int i = 0; i < ROWS; i++) {
        /*
        Iterates through unique numbers and checks if the current row have
        all of them.
        */
        for (int j = 0; j < uniqueSize; j++) {
            isFound = false;
            currNum = uniqueNums[j];
            for (int k = 0; k < COLS; k++) {
                if (currNum == matrix[i][k]) {
                    isFound = true;//Number found
                    break;
                }
            }
            if (!isFound) {//If number not found go to the next row.
                break;
            }
        }
        if (isFound) {//If container row found return its number.
            // if ignoreZero , should check the occurrences
            if(!ignoreZero) {
                return i;
            }
            // we now check if there is max bigger than us then skip it
            int myMax = maxOcc[i];
            //Tells if this line fulfills the condition
            bool isGood = true;
            for(int j = 0; j < COLS; j++) {
                if(j != i && maxOcc[j] > myMax) {
                    isGood=false;
                }

            }
            if(isGood) {
                return i;
            }

        }
    }
    return -1;
}

