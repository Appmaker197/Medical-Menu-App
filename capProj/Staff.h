#ifndef STAFF_H
#define STAFF_H

#include <string>
#include "Staff.h"
using namespace std;


struct personal
{
	string gender;
	string birthDate;
};

struct contact
{
	string phone;
	string email;
};

class staff
{
private:
	//variable
	//department departID;
	int itemS;
	string dep;
	string staffId;
	string staffName;
	string first;
	string last;
	string type;
	personal info;
	contact details;

public:
	//defualt contructers
	staff();

	//getters
	string getSID();
	string getSName();
	string getFName();
	string getLName();
	string getType();
	string getGender();
	string getBirthDate();
	string getPhone();
	string getEmail();
	string getDep();

	//setters
	void setGender(string g);
	void setBirthDate(string b);
	void setPhone(string ph);
	void setEmail(string e);
	void setdep(string d);
	void setType(string t);
	void setSID(string p);
	void setSName(string n);
	void setFname(string f);
	void setLname(string l);
	//print
	void printS(staff staffArray[]);

	//Other Functions.
	void addStaff();
	void populateS(staff staffArray[]);
	void searchS(staff staffArray[]);
	void outputS(staff staffArray[]);
};
#endif