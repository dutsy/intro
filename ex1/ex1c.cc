/*#############################################################################
 * modprog1, 2018a
 * Written by: qussay fiorn
 * ID: 327601779
 * Login: kuchipe
 * Ex #1c
 * Description: This program takes 4 doubles from the user, the first 2 doubles
 * present a left top point and the last 2 present a right bottom point of
 * rectangle.
 * input: 4 doubles
 * output: radius, area and perimeter of the circles.
 *#############################################################################
 */
#include <iostream>
#include <cmath>

using std::cout;
using std::endl;
using std::cin;

int main() {
    //Defining the needed variables
    double x1, y1, x2, y2, height_of_triangle, width_of_triangle,
           blocked_circle_radius, blocking_circle_radius, pi,
           blocked_circle_perimeter, blocking_circle_perimeter,
           blocked_circle_area, blocking_circle_area, diagonal_of_rectangle;

    //Taking 4 values from the user
    cin >> x1 >> y1 >> x2 >> y2;
    //Calculating the height of the triangle
    height_of_triangle = y1 - y2;
    //Calculating the width of the triangle
    width_of_triangle = x2 - x1;
    //Calculating the diagonal of the rectangle
    diagonal_of_rectangle = sqrt((height_of_triangle * height_of_triangle) +
                                 (width_of_triangle * width_of_triangle));
    //Setting pi value;
    pi = 3.1415;
    //Calculating the blocked circle radius
    blocked_circle_radius = height_of_triangle/2;
    //Calculating the blocked circle perimeter
    blocked_circle_perimeter = 2 * pi * blocked_circle_radius;
    //Calculating the blocked circle area
    blocked_circle_area = pi * (blocked_circle_radius*blocked_circle_radius);

    //Calculating the blocking circle radius
    blocking_circle_radius = diagonal_of_rectangle/2;
    //Calculating the blocking circle perimeter
    blocking_circle_perimeter = 2 * pi * blocking_circle_radius;
    //Calculating the blocking cricle area
    blocking_circle_area = pi *
                           (blocking_circle_radius * blocking_circle_radius);
    //Printing the data to user
    cout << blocked_circle_radius << " " << blocked_circle_area << " "
         << blocked_circle_perimeter << endl;
    cout << blocking_circle_radius << " " << blocking_circle_area << " "
         << blocking_circle_perimeter << endl;
}
