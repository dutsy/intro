/*
* modprog1, 2018a
* Ex #9b a program that counts shortest steps needed to reach n1 (number) from
* n2 (another number) with only two actions, sum by , multiplication by 2.
* Written by: qussay firon
* id: 327601779
* login: kuchipe
* usage example
* input: 1 22
* output: 6
*/
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <limits.h>
//Using section
//------------------------------------------------------------------------------
using std::cin;
using std::cout;
using std::endl;
using std::min;
//Functions
//------------------------------------------------------------------------------
//Takes two values from the user
void values(unsigned &x1, unsigned &x2);
//------------------------------------------------------------------------------
//Counts the moves from n1 to n2
int num_of_ops(unsigned n1, unsigned n2);
//------------------------------------------------------------------------------
//Main
int main() {
	unsigned n1, n2;
	values(n1, n2);
	int x = num_of_ops(n1, n2);
	cout << x << endl;
	return EXIT_SUCCESS;
}
//------------------------------------------------------------------------------
void values(unsigned &x1, unsigned &x2) {
	cin >> x1;
	cin >> x2;
}
//------------------------------------------------------------------------------
int num_of_ops(unsigned n1, unsigned n2) {
	if (n1 == n2) {
		return 0;
	} else if (n1 > n2) {
		return INT32_MAX;//Return big number
	} else {
		unsigned x1 = num_of_ops(n1 + 1, n2);//Add 1 to n1
		unsigned x2 = num_of_ops(n1 * 2, n2);//Multiply n2
		return min(x1, x2) + 1;//Steps +1
	}
}
