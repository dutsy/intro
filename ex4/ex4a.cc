/*
 * modprog1, 2018a
 * Ex #4a a program that calculates the variance of progression
 * Written by: qussay fiorn
 * id: 327601779
 * login: kuchipe
 * usage example
 * 1 2 3 4 5 6 7
 * output: 4 4
 */
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

//----------------------------------Constants----------------------------------
const int SIZE = 7; //Numbers array size

//------------------------------------Main-------------------------------------
int main() {
    double numbers[SIZE];
    double sum = 0,//Numbers array sum
        average, //Numbers array average
        variance = 0;

    for (int i = 0; i < SIZE; i++) {//Iterating through numbers array
        cin >> numbers[i]; //Taking values from the user
        sum += numbers[i];//Increase sum
    }

    average = sum/SIZE; //Calculating the average

    //Iterating through numbers array
    for (int i = 0; i < SIZE; i++) {
        //Calculating the variance
        variance += (numbers[i]-average) * (numbers[i]-average);
    }

    variance /= 7; //Dividing variance by 7

    cout << average << " " << variance << endl;//Printing average and variance

    return EXIT_SUCCESS;
}
