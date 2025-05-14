/******************************************************************************
Filename:  BST.h
Purpose: this will create the neccesary member function prototypes needed to
execute throughout the program,it has the neccessary private data,Node struct
constructor(s), destructor, public functions for the BST ADT.
#******************************************************************************/
#pragma once
#ifndef BST_H_
#define BST_H_
#include "Student.h"

class BST {
private:
	struct Node {
		Student theStudent;
		Node* right;
		Node* left;
	};
	ofstream outFile;
	Node* root;
	int size;
	void add(Node*&, const Student&, bool&);
	void destroy(Node*&);
	void displayInOrder(Node*);
	bool remove(Node*&, const int);
	void removeP(Node*&, char*, bool&);
	void retrieval(Node* curr, Student&, const int, bool&) const;
	void deleteNode(Node*& );
	int getHeight(Node* curr);
public:
	BST();
	~BST();
	bool addStudent(const Student&);
	bool removeProgram(char*);
	bool removeStudent(const int);
	bool retrieve(Student&,const int) const;
	bool loadStudents();
	bool display();
	int monitor();
};
#endif