/*
 * modprog1, 2018a
 * Ex #2c a program converts date from numeric form to words.
 * Written by: qussay fiorn
 * id: 327601779
 * login: kuchipe
 *
 * usage example
 *
 * input: 2 2 2333
 * output: 2nd February 2333
 *
 */
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main() {
    //d presents day, m presents month, y presents year;
    int d, m ,y;
    //taking values from the user
    cin >> d >> m >> y;

    bool legal = true; // stands for legal year or not

    if (y >= 0 && y <= 3000  && m > 0 && m <= 12 && d > 0 && d <= 31) {// Checks
        //if year between 0 to 3000, months between 1 to 12, day between 0 to 31
        if (m == 4 || m == 6 || m == 9 || m == 11) { // Checks if months 4, 6, 9
            //, 11 have 1 to 30 days
            if (d > 30)
                legal = false;
        } else if (m == 2)// Checks if month 2 have 28 days and 29 days in leap
            if (d > 29 || (!(y%400 == 0 || y%4 == 0) && d > 28))
                legal = false;
    } else
        legal = false;

    if (legal) {// checks if date is legal
        /*    Displaying words to user    */
        cout << d;
        //Displaying names with st,nd,th suffex
        switch (d) {
            case 1:
            case 21:
            case 31:
                cout << "st";
                break;
            case 2:
            case 22:
                cout << "nd";
                break;
            case 3:
                cout << "rd";
            default:
                cout << "th";
        }
        //Displaying months as names January, February....
        switch (m) {
            case 1:
                cout << " January ";
                break;
            case 2:
                cout << " February ";
                break;
            case 3:
                cout << " March ";
                break;
            case 4:
                cout << " April ";
                break;
            case 5:
                cout << " May ";
                break;
            case 6:
                cout << " June";
                break;
            case 7:
                cout << " July ";
                break;
            case 8:
                cout << " August ";
                break;
            case 9:
                cout << " September ";
                break;
            case 10:
                cout << " October ";
                break;
            case 11:
                cout << " November ";
                break;
            case 12:
                cout << " December ";
                break;
        }
        cout << y << endl;
        /**********************************/
    }

    return 0;
}
