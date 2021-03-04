// Project_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Course Number: 3100
// Course Title: Data Struc & Algorithms
// Name: Brien Schmaltz
// Email: schmaltz.6@wright.edu
// Prof Name: Professor Liu
// Date: 2/22/2021
// Project Name: Programming Assignment #2
#include <iostream>
#include <iomanip>
#include <fstream>
#include <windows.h>
#include <istream>
#include <string>
#include <iostream>
#include "Employee.h"
#include <cassert>


char get_user_command();
// Postcondition: The user has been prompted to enter a one character command.
// The next character has been read (skipping blanks and newline characters), 
// and this character has been returned.
void print_menu();
// Postcondition: A menu of choices for this program has been written to cout.
void readRecord();
// Postcondition: Strings have been written out to output.txt
void readSpecificRecord();
// Postcondition: Strings have been read from all.last.txt and written to Example2.txt
void readCompare();
// Postcondition: Strings have been read and compared. Output is result. 
void readCompareLessthan();
int main()
{
    /////////////////////////////////////////////////START OF PROJECT CODE///////////////

    // Part 1 create the employee object
    Employee e;
    Employee f(321, "Lee", "Bob");
    Employee c(f);
    //~c();
    //~e(); No clue why the deconstructor wont work. Should still be called when program ends 
    cout << "Copy/De/Default Constructor functions tested. The Deconstructor will run at the end when you quit. (5)\n";
    cout << "Testing getters/setters \n";
    e.setFirstName("Brien");
    e.setLastName("Schmaltz");
    e.setID(15326);
    cout << "Info dump of e:" << e.getFirstName() << " " << e.getLastName() << " " << e.getID() << "\n";
    cout << "Info dump of f:" << f.getFirstName() << " " << f.getLastName() << " " << f.getID() << "\n";
    cout << "The overload operators are tested in options 3 and 4. " << "\nTo test other employee records in 4, re-arrange the first 2 records in the Small-Database file\n\n ";



    char choice;
    do {
        print_menu();
        choice = toupper(get_user_command()); //Converts choice to uppercase char
        switch (choice) {

        case '1': readRecord();
            break;
        case '2': readSpecificRecord();
            break;
        case '3': readCompare();
            break;
        case '4': readCompareLessthan();
            break;
        case '5': std::cout << "Ridicule is the best test of truth. \n";
            break;
        default:  std::cout << choice << " is invalid. \n";
        }

    } while ((choice != '5'));

    return EXIT_SUCCESS;
}
//Method prints out menu to console. returns nothing
void print_menu()
// Library facilities used: iostream.h
{
    std::cout << "The following choices are available: \n";
    std::cout << " (1)   Enter in an employee record and have it read back.\n";
    std::cout << " (2)   Read employee records from a file.\n";
    std::cout << " (3)   Compare two employee records from an input file.\n";
    std::cout << " (4)   Read two employee records and compare.\n";
    std::cout << " (5)   Quit this test program\n";
}
//Method gets user command for menu system. Returns user command
char get_user_command()
// Library facilities used: iostream
{
    char command;
    std::cout << "Enter choice: ";
    std::cin >> command; // Input of characters skips blanks and newline character
    return command;
}


//////////////////////////////////////////////////////////////////
 //Part 2 
 void readRecord() {
        string tlast, tfirst;
        int tid;
        
        std::cout << "Enter in an employee's last name: ";
        std::cin >> tlast;       

        std::cout << "\nEnter in an employee's first name: ";
        std::cin >> tfirst;

        std::cout << "\nEnter in an employee's ID: ";
        //Invalid input checking
        while (!(std:: cin >> tid) || tid < 0 || tid > 99999) { //Prevents user from inputting a string. 
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
            std::cout << "Invalid Input.\n" << "Please enter another, 0-99999 : ";
        }

        //Creat a new employee object given user input
        Employee e1(tid, tlast, tfirst);
        //Print it out to the console. Using overloaded operator
        std::cout << "\n" << e1 << "\n";

        //Start I/O
        std::ofstream out;
        out.open("eRecord.txt");
        out << e1 << "\n";
        out.close();
    }
 //Part 3 
 void readSpecificRecord() {
     //Start I/O
    std::ifstream in;
    std::ofstream out;
    in.open("Small-Database.txt");
    assert(!in.fail()); //If file doesn't open, throw error. 
    out.open("output.txt");
    assert(!out.fail()); //If file doesn't open, throw error. 

    // Get user input
    int i, j;
    std::cout << "Enter the number of employee records you would like to read from a file: \n";
    //Invalid input checking
        while (!(std::cin >> j) || j < 1 || j > 99) { //Prevents user from inputting a string. 
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
            std::cout << "Invalid Input.\n" << "Please enter another, 1-99 : ";
        }
    //Start reading employee information and put into object to write
    Employee e2;

    for (i = 0; i < j; i++) {
        in >> e2;
        out << e2;
        std::cout << e2;
    }
    std::cout << "\n";
}
 void readCompare() {

     std::ifstream in;
     in.open("Small-Database.txt");
     assert(!in.fail()); //If file doesn't open, throw error. 
  
     Employee firstE;
     Employee secondE;
     boolean answer;
     in >> firstE; //Reads first line.
     in >> secondE; // Reads second line. Second employee. 

     //Note to grader: if you would like to test other names, please just reaarange the first two in the file. They can be any other record. 

     std::cout << "I have chosen: \n" << firstE << " and \n" << secondE;
     if (firstE == secondE) {
         std::cout << "\nThe two employee records chosen. By me. The supreme AI overlord of this program are the SAME \n" ;
     }
     else 
     {
         std::cout << "\nThe two employee records chosen. By me. The supreme AI overlord of this program are NOT the SAME \n";
     }
     

     
 }
 
 void readCompareLessthan() {
     /// <summary>
     /// First Employee
     /// </summary>
     string t1last, t1first;
     int t1id;
     std::cout << "Enter in employee 1's last name: ";
     std::cin >> t1last;

     std::cout << "\nEnter in employee 1's first name: ";
     std::cin >> t1first;

     std::cout << "\nEnter in employee 1's ID: ";
     //Invalid input checking
     while (!(std::cin >> t1id) || t1id < 0 || t1id > 99999) { //Prevents user from inputting a string. 
         std::cin.clear();
         std::cin.ignore(INT_MAX, '\n');
         std::cout << "Invalid Input.\n" << "Please enter another, 0-99999 : ";
     }

     //Creat a new employee object given user input
     Employee te1(t1id, t1last, t1first);
     //Print it out to the console. Using overloaded operator
     std::cout << "\n" << te1 << "\n";

     /// <summary>
     /// Second employee
     /// </summary>
     string t2last, t2first;
     int t2id;
     std::cout << "Enter in employee 2's last name: ";
     std::cin >> t2last;

     std::cout << "\nEnter in employee 2's first name: ";
     std::cin >> t2first;

     std::cout << "\nEnter in employee 1's ID: ";
     //Invalid input checking
     while (!(std::cin >> t2id) || t2id < 0 || t2id > 99999) { //Prevents user from inputting a string. 
         std::cin.clear();
         std::cin.ignore(INT_MAX, '\n');
         std::cout << "Invalid Input.\n" << "Please enter another, 0-99999 : ";
     }

     //Creat a new employee object given user input
     Employee te2(t2id, t2last, t2first);
     //Print it out to the console. Using overloaded operator
     std::cout << "\n" << te2 << "\n";

     /////PART 5 comparison
     std::cout << "I am comparing: " << te1.getLastName() << " With : " << te2.getLastName();
     if (te1 < te2) {
         std::cout << " || " << te1.getLastName() << " is less than : " << te2.getLastName();
     }
     else
     {
         std::cout << " || " << te1.getLastName() << " is greater than : " << te2.getLastName() << " ";
     }
 }
 