/*
 * modprog1, 2018a
 * Ex #3a a program that counts how many numbers are enters and their average
 *  how many of them was positive and how many of them was negative, the
 *  program stops when 0 is entered.
 * Written by: qussay firon
 * id: 327601779
 * login: kuchipe
 * usage example
 * input: 5 12 -3 23 12 0
 * output: 5 9 4 1
 */
#include <iostream>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;

/*                          Main                              */

int main() {
    int number,
        sum = 0, // sum of all numbers
        counter = 0, // How many numbers where entered
        positives = 0, // How many positives numbers were entered
        negatives = 0; //How many negative numbers were entered
    do {
        cin >> number; // Taking numbers from user
        sum += number; // adding numbers to sum

        if (number > 0)//Counting positive numbers
            positives++;
        else if (number < 0)//Counting negative numbers
            negatives++;

        counter++;
    } while (number);//While number does not equal zero
    counter--; //substring 1 from counter because zero was counted
    cout << counter << " " << sum/counter << " " //Printing values
         << positives << " " << negatives << endl;

    return EXIT_SUCCESS;
}
