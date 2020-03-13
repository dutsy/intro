/*
 * modprog1, 2018a
 * Ex #3b a program that finds gcd of two numbers, the program stops when
 * zero is entered
 * Written by: qussay firon 
 * id: 327601779
 * login: kuchipe
 *
 * usage example
 * input: 32 5
 * output: 1
 */
#include <iostream>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;

int main() {

    unsigned int num1, //Number 1
                 num2, //Number 2
                 temp, //Holds a value
                 divider, //diving number
                 remainder; // reminder of division

    do {
        cin >> num1;
        if (!num1)
            continue;
        cin >> num2;
        remainder = 1;

        //Puts the biggest value on num1 and the smallest on num2
        if (num2 > num1) {
            temp = num1;
            num1 = num2;
            num2 = temp;
        }

        while (remainder) {//While reminder not equal to 0
            //Euclidean algorithm
            remainder = num1%num2;
            num1 = num2;
            divider = num2;
            num2 = remainder;
        }
        cout << divider << endl; //Printing value
    }
    while (num1); //While number one not equal to zero
return EXIT_SUCCESS;
}
