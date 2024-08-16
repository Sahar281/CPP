

#include<iostream>
using namespace std;
void check(char str[], int size);

int main() {
	const int size = 100;
	char sentence[size] = { NULL };
	cout << "please enter sentence " << endl;

	cin.getline(sentence, size);
	check(sentence, size);

	return 0;
}

void check(char str[], int size) {
	int numOfNumbers = 0, i = 0, prev = 0, numofWords = 0, seq = 0, maxSeq = 0;
	while (str[i] != NULL) {
		if (i == 0)
			//////////////////// 1st iteraction ////////////////////
		{
			//numbers check
			if (str[i] >= '0' && str[i] <= '9')
			{
				bool isValid = true;
				while ((str[++i] != ' ') && (str[i] != NULL))
				{
					if (str[i] < '0' || str[i] > '9')
						isValid = false;
				}
				if (isValid == false) {
					seq++;
					maxSeq++;
				}
				else
					numOfNumbers++;
			}
			//words check
			else if (str[i] >= 'A' && str[i] <= 'Z')
			{
				bool isValid = true;
				while ((str[++i] != ' ') && (str[i] != NULL))
				{
					if (str[i] < 'a' || str[i] > 'z')
					{
						isValid = false;
					}
				}
				if (isValid == false) {
					seq++;
					maxSeq++;
				}
				if (isValid)
					numofWords++;
			}
			// not number & not word
			else
			{
				while ((str[++i] != ' ') && (str[i] != NULL));
				seq++;
				if (seq > maxSeq)
				{
					maxSeq = seq;
				}
			}
			if (str[i] == NULL)  break;
		}
		//////////////////// 2nd iteraction -> end of arrey ////////////////////
		else {
			prev = i - 1;
			if (str[i] >= '0' && str[i] <= '9' && str[prev] == ' ') {
				bool isValid = true;
				while ((str[++i] != ' ') && (str[i] != NULL))
				{
					//numbers check
					if (str[i] < '0' || str[i] > '9')
						isValid = false;
				}
				if (isValid == false) {
					seq++;
				}
				if (isValid)
				{
					numOfNumbers++;
					seq = 0;
				}
			}
			//words check 
			else if (str[i] >= 'A' && str[i] <= 'Z' && str[prev] == ' ') {
				bool isValid = true;
				while ((str[++i] != ' ') && (str[i] != NULL))
				{
					if (str[i] < 'a' || str[i] > 'z')
						isValid = false;
				}
				if (isValid == false)
					seq++;
				if (isValid)
				{
					numofWords++;
					seq = 0;
				}
			}
			//not number & not word
			else {
				if ((str[i] != ' ') && (str[i] != NULL))
				{
					while ((str[i] != ' ') && (str[i++] != NULL));
					seq++;
				}
			}
			if (seq > maxSeq)
			{
				maxSeq = seq;
			}
			if (str[i] == NULL)  break;
			prev = i;
			i++;
		}
	}
	// print 
	cout << "\nnum of words is : " << numofWords << endl << "num of numbers is : " << numOfNumbers << endl << "max sequence of ilegal words/numbers is: " << maxSeq;
}