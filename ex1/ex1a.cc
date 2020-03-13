/*#############################################################################
 * modprog1, 2018a
 * Written by: qussay firon
 * ID: 327601779
 * Login: kuchipe
 * Ex #1a
 * Description: This program takes 3 integers from the user, then it subtracts
 * them.
 * input: 3 integers
 * output:
 * first-first first-second first-third
 * second-first second-second second-third
 * third-first third-second third-third
 *#############################################################################
 */
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main() {
    //Defining the needed variables
    int num1, num2, num3;
    //Taking values from the user
    cin >> num1 >> num2 >> num3;
    //-----------
    //Calculating
    cout << num1 - num1 << " " << num1 - num2 << " " << num1 - num3 << endl;
    cout << num2 - num1 << " " << num2 - num2 << " " << num2 - num3 << endl;
    cout << num3 - num1 << " " << num3 - num2 << " " << num3 - num3 << endl;
    //-----------
    //End of calculating
    return 0;
}
