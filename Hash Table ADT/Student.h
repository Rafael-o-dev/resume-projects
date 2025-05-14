/******************************************************************************
Filename:  Student.h
Purpose: this will create the neccesary member function prototypes needed to
execute throughout the program,it has the neccessary private data,
constructor(s), destructor, and setters/getters for the Student ADT.
This will also create the Enums needed for the int and Standing of user.
Along with a string constant
#******************************************************************************/
#ifndef STUDENT_H_
#define STUDENT_H_
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
const int STR_SIZE = 256;

//The Standing the Student can be assigned with 
enum Standing {Unknown, Unnacceptable, Improving, Average, Advanced, Prodigy};
using namespace std;

class Student {
private:
	//pointer to the first name of the Student
	char* program;
	//pointer to the last name of the Student
	char* name;
	//the gNum of the Student
	int gNum;
	//the standing of the Student
	Standing standing;

public:
	//Student constructor
	Student();
	//Student copy constructor
	Student(const Student&);
	//Student assignment operator
	const Student& operator=(const Student&);
	//Student destructor
	~Student();
	//getters with the respective names
	const char* getProgram() const;
	const char* getName() const;
	const int getGNum();
	const Standing getStanding();
	//setters with the respective name
	void setProgram(const char*);
	void setName(const char*);
	void setGNum(int);
	void setStanding(int);

};

#endif
