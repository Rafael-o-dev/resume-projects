/******************************************************************************
Filename:  Student.cpp
Purpose: this will create the neccesary member function definitions needed to
execute throughout the program,it has the neccessary private data,
constructor(s), destructor, and setters/getters for the Student ADT.
#******************************************************************************/
#include "Student.h"
//Name:        Student constructor
//Description: constructs the new Student and its data
//inputs:      none 
//Outputs:     none
//return:      none
Student::Student() {
	//program created and set to Unknown
	program = new char[10];
	strcpy(program, "(unknown)");
	//name created and set to Unknown
	name = new char[10];
	strcpy(name, "(unknown)");
	//gNum created and set to -1
	gNum = -1;
	//gNum created and set to unknown
	standing = Unknown;

}
//Name:        Student copy constructor
//Description: copys an existing Student and its data
//			   onto another existing Student
//inputs:      none
//Outputs:     none
//return:      none
Student::Student(const Student& otherStudent) {
	//creates pointers to the respective names
	//with the only neccesary size
	program = new char[strlen(otherStudent.program) + 1];
	name = new char[strlen(otherStudent.name) + 1];
	//copies the Student onto the other Student
	*this = otherStudent;
}
//Name:        Student destructor
//Description: destroys an exisiting Student and its data
//inputs:      none
//Outputs:     none
//return:      none
Student::~Student() {
	//if program delete the name and its pointer
	if (program) {
		delete[] program;
		program = NULL;
	}
	//if name delete the name and its pointer
	if (name) {
		delete[] name;
		name = NULL;
	}
}
//Name:        Student assignment operator
//Description: Allows a Student and it's data to be directly assigned to 
//			   another Student
//inputs:      Student:
//					otherStudent - a Student to assign to a different 
//					Student
//Outputs:     none
//return:      none
const Student& Student::operator=(const Student& otherStudent) {
	//avoids self aassignment
	if (this != &otherStudent) {
		//sets the respective data onto the private data
		this->setProgram(otherStudent.program);
		this->setName(otherStudent.name);
		this->gNum = otherStudent.gNum;
		this->standing = otherStudent.standing;
	}
	return *this;
}
//Name:        respective getters
//Description: retrieve the respective data  
//inputs:      none
//Outputs:     none
//return:      resective data
const char* Student::getProgram() const{
	return program;
}
const char* Student::getName() const{
	return name;
}
const int Student::getGNum() {
	return gNum;
}
const Standing Student::getStanding() {
	return standing;
}
//Name:        setprogram
//Description: sets the private data program with the
//			   user given program 
//inputs:      char pointer
//					program - the program of a Student
//Outputs:     none
//return:      none
void Student::setProgram(const char* program) {
	//if program exists, delete it along with the pointer
	if (this->program != NULL) {

		delete[] this->program;
		this->program = NULL;
	}
	//sets passed program onto private program
	this->program = new char[strlen(program) + 1];
	strcpy(this->program, program);
}
//Name:        setname
//Description: sets the private data name with the
//			   user given name 
//inputs:      char pointer
//					program - the name of a Student
//Outputs:     none
//return:      none
void Student::setName(const char* name) {
	//if name exists, delete it along with the pointer
	if (this->name != NULL) {
		delete[] this->name;
		this->name = NULL;
	}
	//sets passed name onto private name
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}
//Name:        setgNum
//Description: sets the private data gNum with the
//			   user given gNum 
//inputs:      int:
//					gNum - the gNum of the user
//Outputs:     none
//return:      none
void Student::setGNum(int gNum) {
	this->gNum = gNum;
	}
//Name:        setStanding
//Description: sets the private data standing with the
//			   user given standing 
//inputs:      int
//					standing - the standing/Standing of the user
//Outputs:     none
//return:      none
void Student::setStanding(int standing) {
	//Assigns standing with the respective Standing
	switch (standing) {
		case 1:
			this->standing = Unnacceptable;
			break;
		case 2:
			this->standing = Improving;
			break;
		case 3:
			this->standing = Average;
			break;
		case 4:
			this->standing = Advanced;
			break;
		case 5:
			this->standing = Prodigy;
			break;
		//occurs if an error occured
		default:
			this->standing = Unknown;
			break;
	}
}
