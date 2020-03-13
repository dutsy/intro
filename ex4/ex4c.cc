/*
 * modprog1, 2018a
 * Ex #4c a program that finds a bounded array inside of giving array via
 * indexes numbers
 * Written by: qussay firon
 * id: 327601779
 * login: kuchipe
 * usage example
 * input: 5 4 6 7 3 8 9 2 1 0
 * output: 0 5 8 1 4 3 7 2 6 9 0
 */
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

//----------------------------------Constants----------------------------------
const int SIZE = 10; //Numbers array size

//------------------------------------Main-------------------------------------
int main()
{
    int numbers[SIZE];//Numbers array
    int tempValue,//Holds the value of numbers array index
        solution,//Holds the index of numbers array "Solution index"
        solSize;//Solution array size
    bool isArrayFound = false;

    for (int i = 0; i < SIZE; i++) {
        cin >> numbers[i];
    }

    //Iterates through the array
    for (int index = 0; index < SIZE && !isArrayFound; index++) {
        tempValue = numbers[index]; //Holds the index value
        for (int j = 0; j < SIZE; j++) {//Looking for solution
            if (tempValue > SIZE - 1) {//Stop if the tempValue is bigger than
                    //the biggest index in array numbers.
                break;
            }

            //Stop if the index equals the tempValue "solution is found"
            if (index == tempValue) {
                solution = index;//Set solution to index
                solSize = j+1;//Solution array size
                isArrayFound = true;//Solution is found
                break;
            } else {
                tempValue = numbers[tempValue];//Numbers index value
            }
        }
    }

    if (isArrayFound) {//If there is solution print it
        cout << solution;//First element of the array
        tempValue = numbers[solution];//Holds the index value
        for (int i = 0; i < solSize; i++) {//Iterate solution array times
            cout << " " << tempValue;//Print the array
            tempValue = numbers[tempValue];
        }
        cout << endl;
    }

    return EXIT_SUCCESS;
}
