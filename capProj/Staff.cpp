#include <iostream>
#include "Staff.h"
#include <fstream>
#include <sstream>
#include <array>
#include <vector>


using namespace std;

ifstream sFile;
ofstream sOut;

//constructor
staff::staff() {
	//	departID.setID("");
	itemS = 0;
	dep = "";
	staffId = "";
	staffName = "";
	details.email = "";
	details.phone = "";
	info.birthDate = "";
	info.gender = "";

}
//constructor

//getters
string staff::getSID() {
	return staffId;
}

string staff::getSName() {
	return staffName;
}

string staff::getFName() {
	return first;
}

string staff::getLName() {
	return last;
}

string staff::getType() {
	return type;
}

string staff::getGender() {
	return info.gender;
}

string staff::getBirthDate() {
	return info.birthDate;
}

string staff::getDep() {
	return dep;
}

string staff::getPhone() {
	return details.phone;
}

string staff::getEmail() {
	return details.email;
}





//setters

void staff::setdep(string dp) {
	this->dep = dp;
}

void staff::setEmail(string e) {
	this->details.email = e;
}

void staff::setPhone(string pho) {
	this->details.phone = pho;
}

void staff::setSName(string name) {
	this->staffName = name;
}

void staff::setSID(string id) {
	this->staffId = id;
}

void staff::setFname(string f) {
	this->first = f;
}
void staff::setLname(string l) {
	this->last = l;
}
void staff::setType(string t) {
	this->type = t;
}
void staff::setGender(string g) {
	this->info.gender = g;
}
void staff::setBirthDate(string b) {
	info.birthDate = b;
}



void staff::printS(staff staffArray[]) {
	system("CLS");

	cout << "List Of Staff\n" << endl;

	for (int i = 0; i < itemS; i++) {
		cout << staffArray[i].getType() << ","
			<< staffArray[i].getFName() << ","
			<< staffArray[i].getLName() << ","
			<< staffArray[i].getSID() << ","
			<< staffArray[i].getDep() << ","
			<< staffArray[i].getBirthDate() << ","
			<< staffArray[i].getGender() << ","
			<< staffArray[i].getPhone() << ","
			<< staffArray[i].getEmail()
			<< endl;


	}
	cout << endl;
}


void staff::populateS(staff staffArray[]) {
	vector<string> theStaff;

	sFile.open("s.txt");

	string dName;
	int counter = 0;
	int track = 0;
	string dID;
	string test;
	string line;

	while (getline(sFile, line))
	{
		itemS++;
		stringstream ss(line);

		string data;

		while (getline(ss, data, ','))
		{
			theStaff.push_back(data);
		}

	}

	for (int i = 0; i < theStaff.size() % 8; i++) {
		staffArray[counter].setType(theStaff.at(track));
		staffArray[counter].setFname(theStaff.at(track + 1));
		staffArray[counter].setLname(theStaff.at(track + 2));
		staffArray[counter].setSID(theStaff.at(track + 3));
		staffArray[counter].setdep(theStaff.at(track + 4));
		staffArray[counter].setBirthDate(theStaff.at(track + 5));
		staffArray[counter].setGender(theStaff.at(track + 6));
		staffArray[counter].setPhone(theStaff.at(track + 7));
		staffArray[counter].setEmail(theStaff.at(track + 8));

		counter++;
		track = track + 9;
	}

	sFile.close();

}

void staff::addStaff() {

	string type;
	string first;
	string last;
	string sId;
	string dId;
	string birthD;
	string gender;
	string phoneN;
	string theEmail;

	ofstream staffO;

	staffO.open("s.txt", ios::app);


	cout << "Staff Type: ";
	cin >> type;

	cout << "First Name:";
	cin >> first;

	cout << "Last Name:";
	cin >> last;

	cout << "Staff Id: ";
	cin >> sId;

	cout << "Department Id: ";
	cin >> dId;

	cout << "Birth Date: ";
	cin >> birthD;

	cout << "Gender: ";
	cin >> gender;

	cout << "Phone Number";
	cin >> phoneN;

	cout << "Email:";
	cin >> theEmail;

	staffO << "\n" << type << "," << first
		<< "," << last << "," << sId << "," <<
		dId << "," << birthD << "," << gender
		<< "," << phoneN << "," << theEmail;

	staffO.close();

}

void staff::searchS(staff staffArray[]) {

	string theId;
	bool found;
	int count = 5;

	cout << "Staff ID: ";
	cin >> theId;

	found = false; // the ID is not found yet
	for (int i = 0; i < itemS; i++) {
		if (staffArray[i].getSID() == theId) {
			found = true;
			cout << endl << "Staff found!" << endl
				<< "Printing Staff information"
				<< endl << "--------------------------" << endl;
			cout << staffArray[i].getType() << " "
				<< staffArray[i].getFName() << " "
				<< staffArray[i].getLName() << " "
				<< staffArray[i].getSID() << " "
				<< staffArray[i].getDep() << " "
				<< staffArray[i].getBirthDate() << " "
				<< staffArray[i].getGender() << " "
				<< staffArray[i].getPhone() << " "
				<< staffArray[i].getEmail()
				<< endl;
			break;
		}
	}
	if (!found) {
		cout << "Staff with ID " << theId << " is NOT found!"
			<< endl << endl;
	}
}



void staff::outputS(staff staffArray[]) {

	sOut.open("Output[S].txt");

	for (int i = 0; i < itemS; i++) {
		sOut << staffArray[i].getType() << ","
			<< staffArray[i].getFName() << ","
			<< staffArray[i].getLName() << ","
			<< staffArray[i].getSID() << ","
			<< staffArray[i].getDep() << ","
			<< staffArray[i].getBirthDate() << ","
			<< staffArray[i].getGender() << ","
			<< staffArray[i].getPhone() << ","
			<< staffArray[i].getEmail()
			<< endl;
	}

	sOut.close();

}










