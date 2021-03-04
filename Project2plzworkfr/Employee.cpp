#include "Employee.h"
// Course Number: 3100
// Course Title: Data Struc & Algorithms
// Name: Brien Schmaltz
// Email: schmaltz.6@wright.edu
// Prof Name: Professor Liu
// Date: 2/22/2021
// Project Name: Programming Assignment #2


//Parameterized Constructor
Employee::Employee(int IdNum , std::string last , std::string first ) {
	ID = IdNum;
	lastname = last;
	firstname = first;
}
//Copy Constructor
Employee::Employee(const Employee& person) {
	firstname = person.firstname;
    lastname = person.lastname;
	ID = person.ID;
	cout << " The Copy Constructor just ran\n";

}
//Deconstructor
Employee::~Employee() {
	
	ID = 0;
	//delete[] &ID;
	lastname = "null";
	//delete[] &lastname;
	firstname = "null";
	cout << "\nThe destructor just ran\n";
}

void Employee::setFirstName(string first) {
	firstname = first;
}

void Employee::setLastName(string last) {
	lastname = last; 
}

void Employee::setID(int IdNum) {
	ID = IdNum;
}

int Employee::getID() const {
	return ID;
}

 std::string Employee::getFirstName() const {
	 return firstname;

}

std::string Employee::getLastName() const {
	return lastname;
}
bool operator==(const Employee& p1, const Employee& p2)
{
	return (p1.getLastName() == p2.getLastName() &&
		p1.getFirstName() == p2.getFirstName() &&
		p1.getID() == p2.getID());
}
bool operator<(const Employee& p1, const Employee& p2) {
	return (p1.getLastName() < p2.getLastName());
}
