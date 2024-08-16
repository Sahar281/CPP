/*
Sahar Pilo 316558790
Yarden Rimon 315792713
*/

#include <iostream>
using namespace std;

const int SIZE = 8;
void printChessBoard(int Arr[][SIZE]);
bool isChessBoard(int Arr[][SIZE]);

int main()
{
	int i, j, input;
	int Arr1[SIZE][SIZE];

	cout << "please write values to building an 8X8 board \n";

	/*
	A loop that takes values ​​from the user
	*/

	for (i = 0; i < SIZE; i++) // row
	{
		for (j = 0; j < SIZE; j++) // column 
		{
			cin >> input;
			while (input != 0 && input != 1) /// if input !=0 or !=1 == invaild input
			{
				cout << "invaild input, please try again. \n";
				cin >> input; //user write again until he will write 1 or 0
			}

			Arr1[i][j] = input;	// correct input = 1 or 0
		}
	}

	cout << endl;

	printChessBoard(Arr1); 

	return 0;
}

bool isChessBoard(int Arr[][SIZE])
{
	int i, j; 

	for (i = 0; i < SIZE; i++) //A loop that check the values if it is a chessboard - row
	{
		for (j = 0; j < SIZE-1; j++) // column
		{
			if (Arr[i][j] != Arr[i][j + 1] && Arr[i][j] != Arr[i + 1][j]) // 01010101 + 01010101
				true;                                                    //             10101010 - diffrenet number down and next to-
			else
				return (false);
		}
	}

	return true;
}

void printChessBoard(int Arr[][SIZE])
/*
A loop that print the board if ischessboard == true
*/
{
	int i, j;

	if (isChessBoard(Arr))
	{

		for (i = 0; i < SIZE; i++) // row
		{
			for (j = 0; j < SIZE; j++) // column
			{
				cout << Arr[i][j];
			}
			cout << endl;
		}
		cout << "\nThis is a chess board!\n";
	}
	else
	{
		cout << "This is not a chess board! \n";
	}

}
