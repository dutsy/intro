/*#############################################################################
 * modprog1, 2018a
 * Written by: qussay firon
 * ID: 327601779
 * Login: kuchipe
 * Ex #1b
 * Description: This program takes 3 doubles from the user, the 3 doubles
 * present a triangle.
 * input: 3 doubles
 * output: area and the perimeter of the triangle.
 *#############################################################################
 */
#include <iostream>
#include <cmath>

using std::cout;
using std::endl;
using std::cin;

int main() {
  //Defining the need variables  
  double a, b, c, perimeter, area, half_of_perimeter;
   
    //Taking 3 values from the users
    cin >> a >> b >> c;
    //Calculating the perimeter of the triangle
    perimeter = a + b + c;
    //Dividing the perimeter to 2
    half_of_perimeter = perimeter/2;
    //Using Heron equation to calculate the triangle area
    area = half_of_perimeter * (half_of_perimeter - a) *
                  (half_of_perimeter - b) * (half_of_perimeter - c);
    area = sqrt(area);
    //Printing the data to user
    cout << area << endl << perimeter << endl;
    return 0;
}
