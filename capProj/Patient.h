#ifndef PATIENT_H
#define PATIENT_H

#include <string>
#include "Patient.h"
using namespace std;


struct home
{
	string no;
	string street;
	string city;
	string state;
	string zip;
};

struct personalP
{
	string gender;
	string birthDate;
};

struct contactP
{
	string phone;
	string email;
	home address;
};



class patient
{
private:
	//variable
	//department departID;
	int itemsP;
	string pat;
	string patientId;
	string patientName;
	string pfirst;
	string plast;
	personalP patientInfo;
	contactP patientDetails;
	home patientDet;

public:
	//defualt contructers
	patient();

	//getters
	string getPID();
	string getPName();
	string getPFName();
	string getPLName();
	string getPGender();
	string getPBirthDate();
	string getPPhone();
	string getPEmail();
	string getDocID();

	string getHomeNo();
	string getHomeSt();
	string getHomeCity();
	string getHomeState();
	string getHomeZip();



	//setters
	void setPGender(string g);
	void setPBirthDate(string b);
	void setPPhone(string ph);
	void setPEmail(string e);
	void setDocID(string d);
	void setPID(string p);
	void setPName(string n);
	void setPFName(string fir);
	void setPLName(string l);

	void setHomeNo(string houseN);
	void setHomeSt(string houseS);
	void setHomeCity(string houseC);
	void setHomeState(string houseState);
	void setHomeZip(string houseZ);


	//print
	void printP(patient patientArray[]);

	//Other Functions.
	void addPatient();
	void populateP(patient patientArray[]);
	void searchP(patient patientArray[]);
	void outputP(patient patientArray[]);
};



#endif
