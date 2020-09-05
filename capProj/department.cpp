#include <iostream>
#include "Department.h"
#include <fstream>
#include <array>

using namespace std;

//Reading and Outputing
ifstream dFile;
ofstream oFile;

//constructor
department::department() {
	itemD = 0;
	id = "";
	nameD = "";

}
//constructor
department::department(string i, string d, int it) {
	this->itemD = it;
	this->nameD = d;
	this->id = i;
}
//getters
string department::getID() {
	return id;
}

string department::getname() {
	return nameD;
}


//setters
void department::setName(string e) {
	this->nameD = e;
}

void department::setID(string p) {
	this->id = p;
}

//Prints Array.
void department::print(department depArray[]) {
	system("CLS"); //Clear Screen.

	cout << "List Of Departments\n" << endl;

	//Loops through array and calls accessors
	for (int i = 0; i < itemD; i++) {
		cout << depArray[i].getname() << "," << depArray[i].getID() << "\n";
	}



	cout << endl;
}

void department::populate(department depArray[]) {

	dFile.open("d.txt");

	string dName;
	int counter = 0;
	string dID;

	//Loops through file a
	while (getline(dFile, dName, ',')) {

		dFile >> dID;

		//Sets whats in file to array
		depArray[counter].setName(dName);
		depArray[counter].setID(dID);

		//Incrament.
		counter++;
		itemD++; // amount of stuff in file.


		dFile.ignore();

	}
	dFile.close();


}

//Adds to ile
void department::add() {

	string i;
	string n;
	string format;
	department newD;
	ofstream ofs;

	ofs.open("d.txt", ios::app);

	//user input
	cout << "Department Name: ";
	cin >> n;

	cout << "Department Id: ";
	cin >> i;

	//output
	ofs << "\n" << n << "," << i;

	ofs.close();

}

//Searches array
void department::search(department depArray[]) {

	string theId;
	bool found;
	int count = 5;

	cout << "ID: ";
	cin >> theId;

	found = false; // the ID is not found yet
	for (int i = 0; i < itemD; i++) {
		if (depArray[i].getID() == theId) {
			found = true;
			cout << endl << "Department found!" << endl
				<< "Printing Department information"
				<< endl << "--------------------------" << endl;
			cout << "Department Name: " << depArray[i].getname() << "\n" << "Department Id: " << depArray[i].getID() << endl;
			break;
		}
	}
	if (!found) {
		cout << "Department with ID " << theId << " is NOT found!"
			<< endl << endl;
	}


}

//Outputs to external txt file.
void department::outputD(department depArray[]) {
	oFile.open("Output[D].txt");
	for (int i = 0; i < itemD; i++) {
		oFile << depArray[i].getname() << "," << depArray[i].getID() << "\n";
	}
	dFile.close();
}

