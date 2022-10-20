#include <iostream>
#include <string>
#include <math.h>

using namespace std;

//bools
bool active = true;

//strings
string firstName[100], lastName[100], input;

//ints
int TP1[100], TP2[100], TP3[100], finalGrade[100], classSize, inputNum, TP1Total, TP2Total, TP3Total, TP1Average, TP2Average, TP3Average, birthyear[100];


//floats
float totalGrade = 0, classAverage = 0;
double SD = 0, answer = 0;


int main() {
	for (int i = 0; i < 5; i++) {

		cout << "Name: ";
		cin >> input;
		if (input == "nomore")break;
		firstName[i] = input;
		cout << "Last name: ";
		cin >> lastName[i];
		cout << "Birthyear: ";
		cin >> birthyear[i];
		cout << "TP1: ";
		cin >> TP1[i];
		cout << "TP2: ";
		cin >> TP2[i];
		cout << "TP3: ";
		cin >> TP3[i];
		classSize++;
	}

	while (active)
	{
		cout << "Main Menu \n\n Please select one of the following options:\n\n";
		cout << "1: Final grades equivalent to the respective students\n";
		cout << "2: Average calculations for the students grades\n";
		cout << "3: Ecart-type of the class is calculated for the tp of choice\n";
		cout << "4: Best grade vs worst grade for the tp of choice or final grade\n";
		cout << "5: Students grades\n";
		cout << "6: Display the amount of students, the names and the grades\n";
		cout << "7: Exit the terminal\n";
		cin >> inputNum;

		cout << inputNum;

		switch (inputNum) {

		case 1: cout << "\n\nyou've chosen: 1\n";
			// input code
			for (int i = 0; i < classSize; i++) {
				finalGrade[i] = ((TP1[i] + TP2[i] + TP3[i]) / 3);
				cout << firstName[i] << ": " << finalGrade[i] << "\n";
				return finalGrade[i];
			}
			//Grades( finalGrade, TP1, TP2, TP3, firstName);
			break;

		case 2: cout << "\n\nyou've chosen: 2\n";
			// case2: set up the average calculations for the students grades
			while (true) {
				cout << "Input TP: ";
				cin >> input;
				if (input == "Quit") break;

				if (input == "TP1") {
					for (int i = 0; i < classSize; i++) {
						TP1Total += TP1[i];
					}
					TP1Average = TP1Total / classSize;
					cout << TP1Average;
					return TP1Average;
				}
				else if (input == "TP2") {
					for (int i = 0; i < classSize; i++) {
						TP2Total += TP2[i];
					}
					TP2Average = TP2Total / classSize;
					cout << TP2Average;
					return TP2Average;
				}
				else if (input == "TP3") {
					for (int i = 0; i < classSize; i++) {
						TP3Total += TP3[i];
					}
					TP3Average = TP3Total / classSize;
					cout << TP3Average;
					//return TP3Average;
				}

				//Average( TP1, TP2, TP3, input, classSize,TP1Total,TP2Total,TP3Total, TP1Average, TP2Average, TP3Average);
			}
			break;

		case 3: cout << "\n\nyou've chosen: 3\n";
			// case3:ecart-type of the class is calculated for the tp of choice


			for (int i = 0; i < classSize; i++) {
				finalGrade[i] = ((TP1[i] + TP2[i] + TP3[i]) / 3);
				totalGrade += finalGrade[i];
			}
				classAverage = totalGrade / classSize;
				SD += pow(totalGrade - classAverage, 2);
			answer = sqrt(SD / classSize);
			cout << "The Standard Deviation is: " << answer << "\n";

			break;

		case 4: cout << "\n\nyou've chosen: 4\n";
			// case4:best grade vs worst grade for the tp of choice or final grade
			cout << "Enter the TP you would like to see the top v worst grade of: ";
			cin >> input;
			if (input == "TP1") {
				int Best = TP1[0];
				int Worst = TP1[0];
				for (int i = 0; i < classSize; i++) {
					if (TP1[i] > Best) {
						Best = TP1[i];
					}
					else if (TP1[i] < Worst) {
						Worst = TP1[i];
					}
				}
				cout << "Worst grade: " << Worst << " " << "Best grade: " << Best;
			}
			else if (input == "TP2") {
				int Best = TP2[0];
				int Worst = TP2[0];
				for (int i = 0; i < classSize; i++) {
					if (TP2[i] > Best) {
						Best = TP2[i];
					}
					else if (TP2[i] < Worst) {
						Worst = TP2[i];
					}
				}
				cout << "Worst grade: " << Worst << " " << "Best grade: " << Best;
			}
			else if (input == "TP3") {
				int Best = TP3[0];
				int Worst = TP3[0];
				for (int i = 0; i < classSize; i++) {
					if (TP3[i] > Best) {
						Best = TP3[i];
					}
					else if (TP3[i] < Worst) {
						Worst = TP3[i];
					}
				}
				cout << "Worst grade: " << Worst << " " << "Best grade: " << Best;
			}
			else if (input == "Final") {

				for (int i = 0; i < classSize; i++) {
					finalGrade[i] = ((TP1[i] + TP2[i] + TP3[i]) / 3);
				}
				int Best = finalGrade[0];
				int Worst = finalGrade[0];
				for (int i = 0; i < classSize; i++) {
					if (finalGrade[i] > Best) {
						Best = finalGrade[i];
					}
					else if (finalGrade[i] < Worst) {
						Worst = finalGrade[i];
					}
				}

				cout << "Worst grade: " << Worst << " " << "Best grade: " << Best;

			}
			break;

		case 5: cout << "\n\nyou've chosen: 5\n\n";
			while (true) {

				cout << "Enter a name: ";
				cin >> input;
				if (input == "Quit") break;
				for (int i = 0; i < classSize; i++) {
					if (input == firstName[i]) {
						cout << "\n\n" << firstName[i] << " " << lastName[i] << ": " << birthyear[i] << " " << TP1[i] << " " << TP2[i] << " " << TP3[i] << "\n\n";
					}
				}
			}
			break;

		case 6: cout << "\n\nyou've chosen: 6\n\n";
			// case6:display the amount of students, the names and the grades
			cout << "There are " << classSize << " students: \n";
			for (int i = 0; i < classSize; i++) {
				cout << "\n" << firstName[i] << " " << lastName[i] << ": " << birthyear[i] << " " << TP1[i] << " " << TP2[i] << " " << TP3[i] << "\n";
			}
			break;

		case 7: active = false;
			// case7: user can input something to exit the terminal
			break;
		}
	}
}