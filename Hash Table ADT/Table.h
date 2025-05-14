/******************************************************************************
Filename:  Table.h
Purpose: this will create the neccesary member function prototypes needed to
execute throughout the program,it has the neccessary private data,Node struct
constructor(s), destructor, public functions for the Table ADT.
#******************************************************************************/
#pragma once
#ifndef TABLE_H_
#define TABLE_H_
#include "Student.h"

class Table {
private:
	struct Node {
		Student theStudent;
		Node* next;
	};
	ofstream outFile;
	Node** aTable;
	const static int CAP = 10;
	int currCap;
	int size;
	int calculateIndex(const char*) const;
	void destroyChain(Node*&);
public:
	Table();
	~Table();
	bool addStudent(const Student& aStudent);
	bool removeLowest();
	//bool retrieve(char*,Student[],int &) const;
	bool edit(char*, char*, int);
	bool loadStudents();
	bool display();
	bool monitor();

};
#endif