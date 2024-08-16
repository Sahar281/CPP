

#include <iostream> 
#include <string.h>
using namespace std;
void toLowerCase(char str[]);
int const MAXSIZE = 30;
int const NUMSTR = 3;
bool checkIfSameMedicine(char str1[], char str2[][MAXSIZE]);


int main()
{
	char str1[MAXSIZE];
	char str2[NUMSTR][MAXSIZE] = { "Paracetamol", "ENALAPRIL", "ENOXaparin"}; // The prescription medicine

	cout << "hello. please write the name of the medicine you want to add:\n"; // ask fron the user medicine we want to add
	cin >> str1;
	cout << endl;

	cout << checkIfSameMedicine(str1,str2);

	return 0;
}

bool checkIfSameMedicine(char str1[], char str2[][MAXSIZE])
{
	int notTheSame=0;
	toLowerCase(str1);  // single str - make all the leters lower leters

		for (int i = 0; i < NUMSTR; i++) // loop for the Two-dimensional array of str
		{
			toLowerCase(str2[i]); // make all the leters lower leters
			if (strcmp(str1, str2[i]) !=0) // compare between the single str to one of the Two-dimensional array strings
				 notTheSame ++;	 // if its not even = ++
		}

		if (notTheSame == NUMSTR)
		{
			cout << "false. The medicine is not on the list, ";
			return false;
		}

		else
			cout << "true. The medicine is allready on the list, ";
			return true;
}

void toLowerCase(char str[])
{
	int i = 0;

	while (str[i] != '\0') //loop - while the index != \0
	{
		if (str[i] >= 'A' && str[i] <= 'Z') // aski table, if the letter between A-Z (upper leter)
		{
			str[i] = str[i] + ('a' - 'A'); // you will take it 20 spots forward ans make it lower leter
		}

		i++;
	}
}