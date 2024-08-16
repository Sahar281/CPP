/*
Sahar Pilo 316558790
Yarden Rimon 315792713
*/

#include <iostream>
using namespace std;

int allArrayVeryEvenOrOdd(int Arr[], int size), sum = 0;
bool isVeryEven(int arr[]), misparim;

int main()
{
	int Arr1[] = { 11, -22, 33, -64, 231 };
	cout << "Arr1 is - " << allArrayVeryEvenOrOdd(Arr1, 5) << endl; 
	// operate the func on each index
	
	int Arr2[] = { 3, 27, -432, 41 };
	cout << "Arr2 is - " << allArrayVeryEvenOrOdd(Arr2, 4) << endl;
	// operate the func on each index

	int Arr3[] = { 23, 444, -678, 324, 14, 78, -939393 };
	cout << "Arr3 is - " << allArrayVeryEvenOrOdd(Arr3, 7) << endl;
	// operate the func on each index

	return 0;
}

int allArrayVeryEvenOrOdd(int Arr[], int size) {
	int even = 0, noEven = 0;

	for (int i = 0; i < size ; i++) { // loop to check each number in Arr [i][j]

		bool isVeryEven(int Arr [], int size);
		{
			misparim = isVeryEven(Arr, i);
			if (misparim)
				even++;
			else
				noEven++;
		}
	}

	if (noEven == 0) // all are even
		return 1;

	if (even == 0) // all are odd
		return 2;

	else
		return 3; // there are even numbers and odd numbers
}

bool isVeryEven(int arr[], int i) { // loop to check if the number is very even or very odd
	int digit;
	sum = 0;

	while (arr[i] != 0) // number is different then 0
	{
		digit = arr[i] % 10; //modul 10 == right number
		sum += digit; 
		arr[i] = arr[i] / 10; // divide and continue
	}
		{
			if (sum % 2 == 0) // its even
				return true;
			else             // its odd
				return false; 
		}
}



/*
loop that ran on each index and operat prior func
if even print true
if odd print false
*/



/*
4
4\2 = 2
2%2 = 0
even

348
348%10=8
348/10
34%10=4
34/10
3%10 = 3

8+3+4 = 15
15%2 != 0
odd
*/