
#include <iostream>
using namespace std;

void printMenu();

int func1(int x, int y);

int Sum(int num1, int num2);

int func3(int holeNum);

int func4(int holeNum);

void func5(int holeNum);

void func6(int holeNum, int prev);

void func7();

void allDigitsSmallToBig(int num);

void allDigitsBigToSmall(int num);

void gaps(int holeNum, int prev);


int main()
{
	printMenu();

	return 0;
}

void printMenu() {

	cout << "please choose your program enter number between  1-7 " << endl;

	int Func = 0, x = 0, y = 0, num1 = 0, num2 = 0, holeNum = 0, prev = 0;
	cin >> Func;

	//first dunc call
	if (Func == 1) {
		cout << "please enter 2 numbers :" << endl << "first num : ";
		cin >> x;
		cout << "second num : ";
		cin >> y;
		cout << func1(x, y);
		cout << endl << endl;
		printMenu();

	}
	//second func call
	else if (Func == 2) {
		cout << "please enter 2 numbers :" << endl << "first num : ";
		cin >> num1;
		cout << "second num : ";
		cin >> num2;
		cout << Sum(num1, num2);
		cout << endl << endl;
		printMenu();
	}
	//third func call
	else if (Func == 3) {
		cout << "please enter a hole positive number :";
		cin >> holeNum;
		cout << func3(holeNum);
		cout << endl << endl;
		printMenu();
	}
	//forth func call
	else if (Func == 4) {
		cout << "please enter a hole positive number :";
		cin >> holeNum;
		cout << func4(holeNum);
		cout << endl << endl;
		printMenu();
	}
	//fifth func call
	else if (Func == 5) {
		cout << "please enter a hole positive number :";
		cin >> holeNum;
		func5(holeNum);
		cout << endl << endl;
		printMenu();
	}
	//sixth func call
	else if (Func == 6) {
		cout << "please enter a hole positive number :";
		cin >> holeNum;
		prev = holeNum;
		func6(holeNum, prev);
		cout << endl << endl;
		printMenu();;
	}
	//seventh func call
	else
		func7();
}

int func1(int x, int y) {
	//stoping condition 
	if (x != 0 && y == 0)
		return 1;
	if (y == 1)
		return x;
	else
		//recursia call
	{
		return x * func1(x, y - 1);
	}
	cout << x;
}

int Sum(int num1, int num2) {
	//stoping condition 
	if (num1 == num2)
	{
		return num2;
	}
	else
	{
		//recursia call
		return num2 + Sum(num1, num2 - 1);
	}
}

int func3(int holeNum) {
	//stoping condition
	if (holeNum / 10 <= 0)
		return 1;
	else
		//call recursive func 
		return 1 + func3(holeNum / 10);
}

int func4(int holeNum) {
	//stoping condition
	if (holeNum / 10 == 0)
		return holeNum;
	else
		cout << holeNum % 10;
	//call recursive func 
	return func4(holeNum / 10);
}

void func5(int holeNum) {
	//stoping condition
	if (holeNum > 1)
		func5(holeNum - 1);
	allDigitsSmallToBig(holeNum);
	allDigitsBigToSmall(holeNum);
	cout << endl;
}

void func6(int holeNum, int prev) {
	//stoping condition
	if (holeNum > 1) {
		func6(holeNum - 1, prev);
	}
	gaps(holeNum, prev);
	allDigitsSmallToBig(holeNum);
	allDigitsBigToSmall(holeNum);
	cout << endl;
}

void func7() {
	cout << "GoodBye !";
	return;
}
///
void allDigitsSmallToBig(int holeNum) //going up
{
	if (holeNum == 1)
		cout << holeNum;
	else
	{
		allDigitsSmallToBig(holeNum - 1);
		cout << holeNum;
	}
}

void allDigitsBigToSmall(int holeNum) // going down
{
	if (holeNum == 1)
		cout << "";
	else
	{
		cout << holeNum - 1;
		allDigitsBigToSmall(holeNum - 1);
	}
}
void gaps(int holeNum, int prev)
{
	if (holeNum != prev) {
		cout << " ";
		gaps(holeNum + 1, prev);
	}
}