#include <iostream>
#include "Patient.h"
#include <fstream>
#include <sstream>
#include <array>
#include <vector>


using namespace std;

// Inputs / Outputs files
ifstream pFile;
ofstream pOut;

//constructor
patient::patient() {
	//	departID.setID("");
	itemsP = 0;
	pat = "";
	patientId = "";
	patientName = "";
	patientDetails.email = "";
	patientDetails.phone = "";

	patientDetails.address.no = "";
	patientDetails.address.street = "";
	patientDetails.address.city = "";
	patientDetails.address.state = "";
	patientDetails.address.zip = "";

	patientInfo.birthDate = "";
	patientInfo.gender = "";



}
//constructor

//getters
string patient::getPID() {
	return patientId;
}

string patient::getPName() {
	return patientName;
}

string patient::getPFName() {
	return pfirst;
}

string patient::getPLName() {
	return plast;
}


string patient::getPGender() {
	return patientInfo.gender;
}

string patient::getPBirthDate() {
	return patientInfo.birthDate;
}

string patient::getDocID() {
	return pat;
}

string patient::getPPhone() {
	return patientDetails.phone;
}

string patient::getPEmail() {
	return patientDetails.email;
}


string patient::getHomeNo() {
	return patientDetails.address.no;
}

string patient::getHomeSt() {
	return patientDetails.address.street;
}

string patient::getHomeCity() {
	return patientDetails.address.city;
}
string patient::getHomeState() {
	return patientDetails.address.state;
}

string patient::getHomeZip() {
	return patientDetails.address.zip;
}


void patient::setHomeNo(string houseN) {
	this->patientDetails.address.no = houseN;

}
void patient::setHomeSt(string houseS) {
	this->patientDetails.address.street = houseS;

}
void patient::setHomeCity(string houseC) {
	this->patientDetails.address.city = houseC;
}
void patient::setHomeState(string houseState) {
	this->patientDetails.address.state = houseState;
}
void patient::setHomeZip(string houseZ) {

	this->patientDetails.address.zip = houseZ;

}


//setters
void patient::setDocID(string p) {
	this->pat = p;
}

void patient::setPEmail(string e) {
	this->patientDetails.email = e;
}

void patient::setPPhone(string pho) {
	this->patientDetails.phone = pho;
}

void patient::setPName(string name) {
	this->patientName = name;
}

void patient::setPID(string id) {
	this->patientId = id;
}

void patient::setPFName(string fir) {
	this->pfirst = fir;
}


void patient::setPLName(string l) {
	this->plast = l;
}

void patient::setPGender(string g) {
	this->patientInfo.gender = g;
}
void patient::setPBirthDate(string b) {
	patientInfo.birthDate = b;
}

//prints array.
void patient::printP(patient patientArray[]) {
	system("CLS");

	cout << "List Of patient\n" << endl;
	// Prints Array.
	for (int i = 0; i < itemsP; i++) {
		cout << patientArray[i].getPFName() << ","
			<< patientArray[i].getPLName() << ","
			<< patientArray[i].getPID() << ","
			<< patientArray[i].getDocID() << ","
			<< patientArray[i].getPBirthDate() << ","
			<< patientArray[i].getPGender() << ","
			<< patientArray[i].getHomeNo() << ","
			<< patientArray[i].getHomeSt() << ","
			<< patientArray[i].getHomeCity() << ","
			<< patientArray[i].getHomeState() << ","
			<< patientArray[i].getHomeZip() << ","
			<< patientArray[i].getPPhone() << ","
			<< patientArray[i].getPEmail() << ","
			<< endl;
	}
	cout << endl;
}


void patient::populateP(patient patientArray[]) {

	itemsP = 0;

	vector<string> thePatient;

	pFile.open("p.txt");

	string dName;
	int counter = 0;
	int tracker = 0;
	string dID;
	string test;
	string line;

	//Loops through file
	while (getline(pFile, line))
	{
		itemsP++;
		stringstream ss(line);

		string data;
		//Loops through each line cuts off before ,
		while (getline(ss, data, ','))
		{
			//Puts it into vector
			thePatient.push_back(data);
		}

	}

	for (int i = 0; i < itemsP; i++) {
		//Transfers values from vector to Array
		patientArray[counter].setPFName(thePatient.at(tracker));
		patientArray[counter].setPLName(thePatient.at(tracker + 1));
		patientArray[counter].setPID(thePatient.at(tracker + 2));
		patientArray[counter].setDocID(thePatient.at(tracker + 3));
		patientArray[counter].setPBirthDate(thePatient.at(tracker + 4));
		patientArray[counter].setPGender(thePatient.at(tracker + 5));

		patientArray[counter].setHomeNo(thePatient.at(tracker + 6));
		patientArray[counter].setHomeSt(thePatient.at(tracker + 7));
		patientArray[counter].setHomeCity(thePatient.at(tracker + 8));
		patientArray[counter].setHomeState(thePatient.at(tracker + 9));
		patientArray[counter].setHomeZip(thePatient.at(tracker + 10));

		patientArray[counter].setPPhone(thePatient.at(tracker + 11));
		patientArray[counter].setPEmail(thePatient.at(tracker + 12));

		counter++;

		tracker = tracker + 13; // Incraments to keep up.
	}

	pFile.close();

}
//Adds Patient.
void patient::addPatient() {
	string type;
	string first;
	string last;
	string sId;
	string dId;
	string birthD;
	string gender;
	string phoneN;
	string theEmail;

	string no;
	string street;
	string city;
	string state;
	string zip;

	ofstream patientO;

	//Opens file
	patientO.open("p.txt", ios::app);

	//User Input
	cout << "First Name:";
	cin >> first;

	cout << "Last Name:";
	cin >> last;

	cout << "Patient Id: ";
	cin >> sId;

	cout << "Doctor Id: ";
	cin >> dId;

	cout << "Birth Date: ";
	cin >> birthD;

	cout << "Gender: ";
	cin >> gender;

	cout << "Street No:";
	cin >> no;

	cout << "Street:";
	cin >> street;

	cout << "City:";
	cin >> city;

	cout << "State:";
	cin >> state;

	cout << "Zip:";
	cin >> zip;

	cout << "Phone Number";
	cin >> phoneN;

	cout << "Email:";
	cin >> theEmail;

	//Put User Input in the main file.
	patientO << endl << first
		<< "," << last << "," << sId << "," <<
		dId << "," << birthD << "," << gender
		<< "," << no << "," << street << "," << city
		<< "," << state << "," << zip
		<< "," << phoneN << "," << theEmail;

	patientO.close();



}

//Searches through array.
void patient::searchP(patient patientArray[]) {

	string theId;
	bool found;
	//int count = 5;

	cout << "patient ID: ";
	cin >> theId;

	found = false; // the ID is not found yet
	for (int i = 0; i < itemsP; i++) {
		if (patientArray[i].getPID() == theId) {
			found = true;
			cout << endl << "patient found!" << endl
				<< "Printing patient information"
				<< endl << "--------------------------" << endl;
			//OutPut founds stuff.
			cout << patientArray[i].getPFName() << " "
				<< patientArray[i].getPLName() << " "
				<< patientArray[i].getPID() << " "
				<< patientArray[i].getDocID() << " "
				<< patientArray[i].getPBirthDate() << " "
				<< patientArray[i].getPGender() << " "
				<< patientArray[i].getHomeNo() << " "
				<< patientArray[i].getHomeSt() << " "
				<< patientArray[i].getHomeCity() << " "
				<< patientArray[i].getHomeState() << " "
				<< patientArray[i].getHomeZip() << " "
				<< patientArray[i].getPPhone() << " "
				<< patientArray[i].getPEmail() << " "
				<< endl;
			break;
		}
	}
	if (!found) {
		cout << "patient with ID " << theId << " is NOT found!"
			<< endl << endl;
	}


}


//Outputs to external file.
void patient::outputP(patient patientArray[]) {

	pOut.open("Output[P].txt");

	//Loops thorugh array and calls getters then outputs it into file
	for (int i = 0; i < itemsP; i++) {
		pOut << patientArray[i].getPFName() << " "
			<< patientArray[i].getPLName() << " "
			<< patientArray[i].getPID() << " "
			<< patientArray[i].getDocID() << " "
			<< patientArray[i].getPBirthDate() << " "
			<< patientArray[i].getPGender() << " "
			<< patientArray[i].getHomeNo() << " "
			<< patientArray[i].getHomeSt() << " "
			<< patientArray[i].getHomeCity() << " "
			<< patientArray[i].getHomeState() << " "
			<< patientArray[i].getHomeZip() << " "
			<< patientArray[i].getPPhone() << " "
			<< patientArray[i].getPEmail() << " "
			<< endl;
	}

	pOut.close();
}








