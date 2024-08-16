#include<iostream>
#include <string.h>

using namespace std;

const int  C = 11;

void calcAndSort(char** Teams, char** Scores, int n, char** sortedTeams, int* sortedScores);

void ScoresInNumbers(char** Scores, int n, int* sortedScores);

void bubble_sort(int n, char** sortedTeams, int* sortedScores);

void checkSpace(char** arr);

void checkSpaceOfSpaces(char* arr);

int main() {

	// number of teames 
	int n = 0;
	cout << "please enter number of teames " << endl;
	cin >> n;

	//ask place for adresses-arr for Teames-arr
	char** Teams = new char* [n];
	//check for place
	checkSpace(Teams);

	//ask place for adresses-arr for Scores-arr
	char** Scores = new char* [n];
	//check for place
	checkSpace(Scores);

	// ask place for adresses-arr of sortedTeams-arr 
	char** sortedTeams = new char* [n];
	//check for place
	checkSpace(sortedTeams);

	// ask place for sortedScores-arr
	int* sortedScores = new int[n];
	//check for place
	if (!sortedScores) {
		cout << "ERROR! Out of memory!\n";
		return  0;
	}

	for (int i = 0; i < n; i++) {

		//ask place for Teames-arr in place i
		Teams[i] = new char[C];
		//check for place
		checkSpaceOfSpaces(Teams[i]);

		//ask place for Scores-arr in place i
		Scores[i] = new char[C];
		//check for place
		checkSpaceOfSpaces(Teams[i]);

		//ask place for sortedTeams-arr in place i
		sortedTeams[i] = new char[C];
		//check for place
		checkSpaceOfSpaces(Teams[i]);
	}
	calcAndSort(Teams, Scores, n, sortedTeams, sortedScores);

	for (int i = 0; i < n; i++) {
		//deleat Teames-arr in place i& enter null value 
		delete[]Teams[i];
		Teams[i] = NULL;
		//deleat Scores-arr in place i & enter null value 
		delete[]Scores[i];
		Scores[i] = NULL;
	}

	//deleat sdress-arr for Teams-arr& enter null value 
	delete[]Teams;
	Teams = NULL;
	//deleat sdress-arr for Scores-arr& enter null value 
	delete[]Scores;
	Scores = NULL;
	//deleat sortedTeams-arr& enter null value 
	delete[]sortedTeams;
	sortedTeams = NULL;
	//deleat sortedScores-arr& enter null value 
	delete[]sortedScores;
	sortedScores = NULL;
	return 0;
}

void calcAndSort(char** Teams, char** Scores, int n, char** sortedTeams, int* sortedScores) {

	//getting teames & scores frome user 
	for (int i = 0; i < n; i++) {
		cout << "please enter team number " << i << " name : " << endl;
		cin >> Teams[i];
		cout << "please enter team number " << i << " Scores : " << endl;
		cin >> Scores[i];
	}

	//change scores into sortedScores 
	ScoresInNumbers(Scores, n, sortedScores);

	//assigning teames into sorted teames 
	for (int i = 0; i < n; i++) {
		strcpy_s(sortedTeams[i], C, Teams[i]);
	}

	// bubble sort sortedScores
	bubble_sort(n, sortedTeams, sortedScores);
	//printing 
	for (int i = 0; i < n; i++) {
		cout << sortedTeams[i] << " " << sortedScores[i] << endl;
	}
}

//change into numbers func 
void ScoresInNumbers(char** Scores, int n, int* sortedScores) {
	int sum = 0;
	// for nested loop to switch & sum scores
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (Scores[i][j] == 'W' || Scores[i][j] == 'w')
				sum += 3;
			if (Scores[i][j] == 'D' || Scores[i][j] == 'd')
				sum += 1;
			if (Scores[i][j] == 'L' || Scores[i][j] == 'l')
				sum += 0;
		}
		//enter new score into sortedscores-arr
		sortedScores[i] = sum;
		sum = 0;
	}
}

//sort func
void bubble_sort(int n, char** sortedTeams, int* sortedScores) {
	int tmp = 0;
	char tempo[C] = { '0' };
	// bubble sort funk to sort teames and scores
	for (int i = n - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (sortedScores[j] < sortedScores[j + 1]) {
				//switch sorted teams scors
				tmp = sortedScores[j + 1];
				sortedScores[j + 1] = sortedScores[j];
				sortedScores[j] = tmp;
				//switch sorted teams 
				strcpy_s(tempo, C, sortedTeams[j + 1]);
				strcpy_s(sortedTeams[j + 1], C, sortedTeams[j]);
				strcpy_s(sortedTeams[j], C, tempo);
			}
		}
	}
}

// check for space func
void checkSpace(char** arr) {
	if (!arr) {
		cout << "ERROR! Out of memory!\n";
		return;
	}
}

// check for space func
void checkSpaceOfSpaces(char* arr) {
	if (!arr) {
		cout << "ERROR! Out of memory!\n";
		return;
	}
}