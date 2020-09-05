#include <iostream>
#include <string>
#include "Department.h"
#include "Staff.h"
#include "Patient.h"


using namespace std;

// Function prototypes
void menu();
void subM();
void subS();
void subP();

//Menu Display functions.
void menu() {
	cout << "\nMain Menu:";
	cout << "\n1. Department menu" << endl;
	cout << "\n2. Staff menu" << endl;
	cout << "\n3. Patient menu" << endl;
	cout << "\n4. Exit" << endl;

	cout << "\nEnter a choice (1 - 4): ";
}

//Department Menu
void subM() {
	cout << "\nDepartment Menu:";
	cout << "\n1. List all" << endl;
	cout << "\n2. Add one" << endl;
	cout << "\n3. Search one" << endl;
	cout << "\n4. Edit one" << endl;
	cout << "\n5. Delete one" << endl;
	cout << "\n6. Return to main menu" << endl;

	cout << "\nEnter a choice (1 - 4): ";
}
//Staff Menu
void subS() {
	cout << "\nStaff Menu:";
	cout << "\n1. List all" << endl;
	cout << "\n2. Add one" << endl;
	cout << "\n3. Search one" << endl;
	cout << "\n4. Edit one" << endl;
	cout << "\n5. Delete one" << endl;
	cout << "\n6. Return to main menu" << endl;

	cout << "\nEnter a choice (1 - 4): ";
}
//Patient Menu
void subP() {
	cout << "\nPatient Menu:";
	cout << "\n1. List all" << endl;
	cout << "\n2. Add one" << endl;
	cout << "\n3. Search one" << endl;
	cout << "\n4. Edit one" << endl;
	cout << "\n5. Delete one" << endl;
	cout << "\n6. Return to main menu" << endl;

	cout << "\nEnter a choice (1 - 4): ";
}


int main()
{
	// bool for loops
	bool start = true;
	bool subStart = true;
	// input option
	int option;
	int subOpt;



	//Gets Information from the txt files.

	department dep;
	staff st;
	patient pat;

	department depArray[100];
	staff staffArray[100];
	patient patientArray[100];


	dep.populate(depArray);
	st.populateS(staffArray);
	pat.populateP(patientArray);



	while (start) {
		subStart = true; //reset to true.
		menu();
		cin >> option;

		//If input is invalid for main menu
		if (option != 4 && option != 3 && option != 2 && option != 1) {

			cout << "\n" << option << " is not a valid choice. Try again..." << endl;

		}
		//Exit program
		if (option == 4) {
			start = false;
			dep.outputD(depArray);
			st.outputS(staffArray);
			pat.outputP(patientArray);
			cout << "Thank you for using my program\n";
			system("pause");
		}

		//3rd choice
		if (option == 3) {

			while (subStart) {
				subP();
				cin >> subOpt;
				if (subOpt == 1) {
					pat.populateP(patientArray);
					pat.printP(patientArray);
					system("pause");
				}
				else if (subOpt == 2) {
					pat.addPatient();
					pat.populateP(patientArray);
					system("pause");
				}
				else if (subOpt == 3) {
					pat.searchP(patientArray);
					system("pause");
				}
				else if (subOpt == 4) {
					cout << "This  menu item is not implemented" << endl;
					system("pause");
				}
				else if (subOpt == 5) {
					cout << "This  menu item is not implemented" << endl;
					system("pause");
				}
				//Exit Loop
				else if (subOpt == 6) {
					subStart = false;
					cout << "Returning to Main Menu" << endl;
					system("pause");
					system("CLS");
				}

				else {
					cout << "\n" << subOpt << " is not a valid choice. Try again..." << endl;


				}
			}

		}

		if (option == 2) {
			while (subStart) {
				subS();
				cin >> subOpt;
				if (subOpt == 1) {
					st.printS(staffArray);
					system("pause");
				}
				else if (subOpt == 2) {
					st.addStaff();
					st.populateS(staffArray);
					system("pause");
				}
				else if (subOpt == 3) {
					st.searchS(staffArray);
					system("pause");
				}
				else if (subOpt == 4) {
					cout << "This  menu item is not implemented" << endl;
					system("pause");
				}
				else if (subOpt == 5) {
					cout << "This  menu item is not implemented" << endl;
					system("pause");
				}
				else if (subOpt == 6) {
					//Exit loop
					subStart = false;
					cout << "Returning to Main Menu" << endl;
					system("pause");
					system("CLS");
				}

				else {
					cout << "\n" << subOpt << " is not a valid choice. Try again..." << endl;
				}
			}

		}


		if (option == 1) {
			while (subStart) {
				subM();
				cin >> subOpt;

				if (subOpt == 1) {
					dep.print(depArray);
					system("pause");
				}
				else if (subOpt == 2) {
					dep.add();
					dep.populate(depArray);
					system("pause");
				}
				else if (subOpt == 3) {
					dep.search(depArray);
					system("pause");
				}
				else if (subOpt == 4) {
					cout << "This  menu item is not implemented" << endl;
					system("pause");
				}
				else if (subOpt == 5) {
					cout << "This  menu item is not implemented" << endl;
					system("pause");
				}
				else if (subOpt == 6) {
					//Exit loop
					subStart = false;
					cout << "Returning to Main Menu" << endl;
					system("pause");
					system("CLS");
				}

				else {
					cout << "\n" << subOpt << " is not a valid choice. Try again..." << endl;
				}
			}

		}


	}

}

