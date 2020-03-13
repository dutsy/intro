/*
 * modprog1, 2018a
 * Ex #2b a program calculates the maximum result of sum and multiplication
 * of three numbers.
 * Written by: qussay fiorn
 * id: 327601779
 * login: kuchipe
 *
 * usage example
 * input: 2 2 2
 * output: (2+2)*2=8
 *
 */
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main()
{
	int num1, num2, num3, //The number the user will enter
        result1, result2, result3, result4, result5, result6; //Results

	cin >> num1 >> num2 >> num3; // taking vales from user

    /*   Calculating results     */
    result1 = (num1 * num2) + num3;
    result2 = (num1 * num3) + num2;
    result3 = (num2 * num3) + num1;
    result4 = (num1 + num2) * num3;
    result5 = (num1 + num3) * num2;
    result6 = (num2 + num3) * num1;
    /*****************************/

    int max = result1, // greatest value will be in the variable,
                       // by default its 1
        resultNumber = 1; // greatest value number will be in this variable 1-6

    /* looking for the greatest value */
    if (result2 > max) {// result 2 is the greatest
        resultNumber = 2;
        max = result2;
    }
    if (result3 > max) {// result 3 is the greatest
        resultNumber = 3;
        max = result3;
    }
    if (result4 > max) {// result 4 is the greatest
        max = result4;
        resultNumber = 4;
    }
    if (result5 > max) {// result 5 is the greatest
        max = result5;
        resultNumber = 5;
    }
    if (result6 > max) {// result 6 is the greatest
        resultNumber = 6;
        max = result6;
    }
    /**********************************/


    /*                   displaying results to user                   */
    switch (resultNumber) {
        case 1:
            cout << num1 << "*" << num2 << "+" << num3 << "=" << result1;
            break;
        case 2:
            cout << num1 << "*" << num3 << "+" << num2 << "=" << result2;
            break;
        case 3:
            cout << num2 << "*" << num3 << "+" << num1 << "=" << result3;
            break;
        case 4:
            cout << "(" << num1 << "+" << num2 << ")*" << num3 << "="
                 << result4;
            break;
        case 5:
            cout << "(" << num1 << "+" << num3 << ")*" << num2 << "="
                 << result5;
            break;
        case 6:
            cout << "(" << num2 << "+" << num3 << ")*" << num1 << "="
                 << result6;
            break;
    }
    /******************************************************************/

	return 0;
}
