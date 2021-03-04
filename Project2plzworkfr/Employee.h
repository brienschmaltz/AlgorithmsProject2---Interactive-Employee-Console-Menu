//Employee.h provided by Dr. Meilin Liu in Fall 2020, and you can modify it if you want. 
// Course Number: 3100
// Course Title: Data Struc & Algorithms
// Name: Brien Schmaltz
// Email: schmaltz.6@wright.edu
// Prof Name: Professor Liu
// Date: 2/22/2021
// Project Name: Programming Assignment #2


#ifndef _Employee_
#define _Employee_

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

class Employee {

public:
	Employee(int IdNum = 11111, std::string last = " lastname", std::string first = "firstname");
	Employee(const Employee& person);
	~Employee();
	void setFirstName(string first);
	void setLastName(string last);
	void setID(int IdNum);
	int getID() const;
	std::string getFirstName() const;
	std::string getLastName() const;

	friend std::istream& operator>>(std::istream& ins, Employee& person) 
	{
		ins >> person.lastname >> person.firstname >> person.ID;
		return ins;
	}
	friend std::ostream& operator<<(std::ostream& outs, Employee& person) 
	{
		outs << person.lastname << " " << person.firstname << " " << person.ID << endl;
		return outs;
	}

private:
	int ID;
	string lastname;
	string firstname;


};

//std::ostream& operator<<(std::ostream& outs, const Employee& person);
bool operator==(const Employee& p1, const Employee& p2); // compares two employee records to see if they are the same
bool operator<(const Employee& p1, const Employee& p2); // test if one employee's last name is less than another employee's. 
	
#endif