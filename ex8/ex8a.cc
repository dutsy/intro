/*
 * modprog1, 2018a
 * Ex #8a a program that tests some properties of number array
 * Written by: qussay firon
 * id: 327601779
 * login: kuchipe
 * usage example:
 * 1- fill array
 * 2- linear search
 * 3- bubble sort
 * 4- binary search
 * 5- occurrences
 * 6- print
 * 7- reverse print
 * 8- is not decreasing
 * 9- is palindrome
 * 10- left sum numbers
 * 11- unique numbers
 * 12- prime numbers
 * 13- end
 */
#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstdlib>
#include <cmath>

using std::cout;
using std::endl;
using std::cin;
using std::cerr;

//------------------------------------Global------------------------------------
//----------------------------------Constants-----------------------------------
const int N = 10;//Array size

enum FUNCTIONS {//Function names
	E_FILL_ARRAY,
	E_LINEAR_SEARCH,
	E_BUBBLE_SORT,
	E_BINARY_SEARCH,
	E_OCCURRENCES,
	E_PRINT,
	E_REVERSE_PRINT,
	E_IS_NOT_DECREASING,
	E_IS_PALINDROME,
	E_LEFT_SUM_NUMS,
	E_UNIQUE_NUMS,
	E_PRIME_NUMS,
	E_END
};
bool isSorted = false;

//----------------------------------Functions-----------------------------------
//------------------------------------------------------------------------------
//1
//Fills array with numbers taken from user
void fillArray(int arr[N], int i);
void fillArray(int arr[N]);

//------------------------------------------------------------------------------
//2
//Linear search on array
bool linearSearch(int n, const int arr[N], int i);
bool linearSearch(int n, const int arr[N]);

//------------------------------------------------------------------------------
//Swaps to integers
void swap(int &i, int &j);

//------------------------------------------------------------------------------
//3
//Bubble sorting on array
void bubbleSort(int arr[N], int i, int j);
void bubbleSort(int arr[N]);

//------------------------------------------------------------------------------
//4
//Binary search on array, it should be sorted!
bool binarySearch(const int arr[N], int num);
bool binarySearch(const int arr[N], int num, int low, int high);

//------------------------------------------------------------------------------
//5
//Prints the number of occurrences of a number
int occurrences(const int arr[N], int num);
int occurrences(const int arr[N], int num, int i, int occ);

//------------------------------------------------------------------------------
//Prints array from start to end
void print(const int arr[N],int size);
void print(const int arr[N], int size, int i);

//------------------------------------------------------------------------------
//7
//Prints array from end to start
void reversePrint(const int arr[N]);
void reversePrint(const int arr[N], int i);

//------------------------------------------------------------------------------
//8
//Checks if array values are increasing and not decreasing
bool isNotDecreasing(const int arr[N]);
bool isNotDecreasing(const int arr[N], int i);

//------------------------------------------------------------------------------
//9
//Checks if array is a palindrome
bool isPalindrome(const int arr[N]);
bool isPalindrome(const int arr[N], int i);

//------------------------------------------------------------------------------
//10
//Shows the total amount of numbers that they equal to their left right numbers
//sum
int leftSumNums(const int arr[N]);
int leftSumNums(const int arr[N], int i, int j, int sum, int total);

//------------------------------------------------------------------------------
//11
//Prints all unique numbers in array
void uniqueNums (const int arr[N]);
void uniqueNums (const int arr[N] , int unique[N],int i , int j , int w , int &k
		,int occurences,bool isSkip);
//------------------------------------------------------------------------------
//12
//Prints all prime numbers in array
void primeNums (const int arr[N]);
void primeNums (const int arr[N] , int primes[N],int i, int j, int k, bool isPrime);
//------------------------------------------------------------------------------
//F13
//Calling this function ends the program
void end();
//------------------------------------------------------------------------------
//Runs the program, number 13 is end
void run(int arr[N]);
//------------------------------------Main--------------------------------------
int main () {
	int arr[N] = {0};//Fill array with zeros
	run(arr);//Run the program
}

//------------------------------------------------------------------------------
void fillArray(int arr[N], int i) {
	if (i < N) {
		cin >> arr[i];//Taking values from user
		fillArray(arr, i+1);
	}
}

//------------------------------------------------------------------------------
void fillArray(int arr[N]) {
	fillArray(arr, 0);
}

//------------------------------------------------------------------------------
bool linearSearch(int n, const int arr[N], int i) {
	if (i == N)
		return false;
	if (n == arr[i])
		return true;
	else
		return linearSearch(n, arr, i+1);
}

//------------------------------------------------------------------------------
bool linearSearch(int n, const int arr[N]) {
	return linearSearch(n, arr, 0);
}

//------------------------------------------------------------------------------
void swap(int &i, int &j) {
	int temp;
	temp = i;
	i = j;
	j = temp;
}

//------------------------------------------------------------------------------
void bubbleSort(int arr[N], int i, int j) {
	//1st for
	if (i == N - 1) {//1st for finished
		return;
	} else {//1st for iteration
		if (j == N - 1 - i) {//2nd for finished
			bubbleSort(arr, i+1, 0);
		} else {//2nd iterating
			if (arr[j] > arr[j+1]) {
				swap(arr[j], arr[j+1]);
			}
			//Next iteration of 2nd for
			bubbleSort(arr, i, j+1);
		}
	}
}

//------------------------------------------------------------------------------
void bubbleSort(int arr[N]) {
	bubbleSort(arr, 0, 0);
	isSorted = true;
}

//------------------------------------------------------------------------------
bool binarySearch(const int arr[N], int num, int low, int high) {
	//Binary search algorithm
	if (low > high) {
		return false;
	} else {
		int mid = (low + high)/2;
		if (num == arr[mid]) {
			return true;
		} else if (arr[mid] < num) {
			low = (mid + 1);
		} else {
			high = (mid - 1);
		}
		return binarySearch(arr, num, low, high);
	}

}

//------------------------------------------------------------------------------
bool binarySearch(const int arr[N], int num) {
	if (!isSorted) {//If array is not sorted show error message.
		cerr << "Error" << endl;
		return false;
	} else {
		int low = 0;
		int high = N - 1;
		return binarySearch(arr, num, low, high);
	}
}

//------------------------------------------------------------------------------
int occurrences(const int arr[N], int num) {
	return occurrences(arr, num, 0, 0);
}

//------------------------------------------------------------------------------
int occurrences(const int arr[N], int num, int i, int occ) {
	if (i == N) {
		return occ;
	} else {
		if (arr[i] == num) {
			occ += 1;
		}
		return occurrences(arr, num, i+1, occ);
	}
}

//------------------------------------------------------------------------------
void print(const int arr[N], int size) {
	print(arr, size, 0);
}

//------------------------------------------------------------------------------
void print(const int arr[N], int size, int i) {
	if (i == size) {
		cout << endl;
	} else {
		cout << arr[i] << " ";
		print(arr, size,i+1);
	}
}

//------------------------------------------------------------------------------
void reversePrint(const int arr[N]) {
	reversePrint(arr, N - 1);
}
//------------------------------------------------------------------------------
void reversePrint(const int arr[N], int i) {
	if (i < 0) {
		cout << endl;
		return;
	} else {
		cout << arr[i] << " ";
		return reversePrint(arr, i-1);
	}
}
//------------------------------------------------------------------------------
bool isNotDecreasing(const int arr[N]) {
	bool notDecreasing = isNotDecreasing(arr, 0);
	if (notDecreasing) {
		isSorted = true;
	}
	return notDecreasing;
}
//------------------------------------------------------------------------------
bool isNotDecreasing(const int arr[N], int i) {
	if (i == N - 1) {
		return true;
	} else {
		if (arr[i] > arr[i+1]) {
			return false;
		}
		return isNotDecreasing(arr, i+1);
	}
}

bool isPalindrome(const int arr[N]) {
	return isPalindrome(arr, 0);
}
//------------------------------------------------------------------------------
bool isPalindrome(const int arr[N], int i) {
	if (i >= (N -1 - i)) {
		return true;
	} else {
		if (arr[i] != arr[(N - 1 - i)]) {
			return false;
		}
		return isPalindrome(arr, i+1);
	}
}
//------------------------------------------------------------------------------
int leftSumNums(const int arr[N]) {
	return leftSumNums(arr, 0, 1, 0, 0);
}
int leftSumNums(const int arr[N], int i, int j, int sum, int total) {
	//1st
	if (i == N - 1) {
		return total;
	} else {

		//2nd
		if (j == N) {
			if (arr[i] == sum) {
				total++;
			}
			i = i+1;
			return leftSumNums(arr, i, i+1, 0, total);
		} else {
			sum += arr[j];
			return leftSumNums(arr, i, j+1, sum, total);
		}
	}
}
//------------------------------------------------------------------------------
void uniqueNums (const int arr[N])
{
	int unique[N] = {0};
	int k = 0;
	uniqueNums(arr, unique, 0, 0, 0, k, 0, false);
	print(unique,k);
}
//------------------------------------------------------------------------------
void uniqueNums (const int arr[N] , int unique[N],int i , int j , int w , int &k ,int
		occurences,bool isSkip)
{
	if(i == N) {
		return;
	}

	// the first for stop condition
	if(w == k) {
		if(isSkip == true) {
			uniqueNums(arr, unique, i+1, 0, 0, k, 0, false);
			return;
		}
		else {//we go to the third loop
			if(j == N) {// end of the third loop
				if (occurences == 1) {
					unique[k] = arr[i];
					k++;
				}
				// we jump to the first loop
				uniqueNums(arr, unique, i+1, 0, 0, k, 0, false);
				return;
			}
			// Body of third loop
			if(arr[j] == arr[i]) {
				occurences++;
			}
			uniqueNums(arr, unique, i, j+1, w, k, occurences, isSkip);
			return;
		}

	}
	// in the second loop body
	if(arr[w] == arr[i]) {
		isSkip=true;
	}
	uniqueNums(arr, unique, i, 0, w+1, k, occurences, isSkip);
	return ;

}
//------------------------------------------------------------------------------
void primeNums (const int arr[N]) {
	int primes[N] = {0};
	primeNums(arr, primes, 0,1,0,true);
}
//------------------------------------------------------------------------------
void primeNums (const int arr[N] , int primes[N],int i, int j, int k, bool isPrime) {
	// first loop finished
	if(i == N) {
		print(primes,k);
		return;
	}
	// first loop body

	// second loop finished
	if(j == arr[i]) {
		if(isPrime && arr[i] != 1 ) {
			primes[k] = arr[i];
			k++;
		}
		primeNums(arr, primes, i+1, 1, k, true);
		return;
	}
	// second loop body

	if((arr[i] <= 0 || arr[i] %j == 0) && j != 1) {
		isPrime = false;
		primeNums(arr, primes, i, arr[i], k, isPrime);
		return ;
	}
	primeNums(arr, primes, i, j+1, k, isPrime);
}
//------------------------------------------------------------------------------
void end() {
	exit(EXIT_SUCCESS);
}
//------------------------------------------------------------------------------
void run(int arr[N]) {
	int num, n;
	cin >> n;
	switch (n - 1) {
	case E_FILL_ARRAY:
		fillArray(arr);
		break;
	case E_LINEAR_SEARCH:
		int n;
		cin >> n;
		cout << linearSearch(n, arr) << endl;
			break;
	case E_BUBBLE_SORT:
		bubbleSort(arr);
			break;
	case E_BINARY_SEARCH:
		cin >> num;
		cout << binarySearch(arr, num) << endl;
			break;
	case E_OCCURRENCES:
		cin >> num;
		cout << occurrences(arr, num) << endl;
			break;
	case E_PRINT:
		print(arr, N);
			break;
	case E_REVERSE_PRINT:
		reversePrint(arr);
			break;
	case E_IS_NOT_DECREASING:
		cout << isNotDecreasing(arr) << endl;
			break;
	case E_IS_PALINDROME:
		cout << isPalindrome(arr) << endl;
			break;
	case E_LEFT_SUM_NUMS:
		cout << leftSumNums(arr) << endl;
			break;
	case E_UNIQUE_NUMS:
			uniqueNums(arr);
			break;
	case E_PRIME_NUMS:
		primeNums(arr);
			break;
	case E_END:
		end();
			break;
	}
	run(arr);
}
