#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include <string>
#include "Department.h"

using namespace std;

class department
{
private:
	//variable
	int itemD;
	string nameD;
	string id;
public:
	//defualt contructers
	department();
	department(string i, string d, int it);
	//getters
	string getID();
	string getname();
	//setters
	void setID(string p);
	void setName(string n);
	//print
	void print(department depArray[]);

	//Other Functions.
	void add();
	void populate(department depArray[]);
	void search(department depArray[]);
	void outputD(department depArray[]);


};
#endif
