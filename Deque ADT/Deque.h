/******************************************************************************
Filename:  Deque.h
Purpose: this will create the neccesary member function prototypes needed to
execute throughout the program,it has the neccessary private data,Node struct
constructor(s), destructor, public functions for the Deque ADT.
#******************************************************************************/
#pragma once
#ifndef DEQUE_H_
#define DEQUE_H_
#include "Command.h"

class Deque {
private:
	int counter;
	struct Node {
		Command theCommand;
		Node* next;
		Node* prev;
	};
	ofstream outFile;
	Node* front;
	Node* rear;
	//number of undone functions
	int undo;
public:
	Deque();
	~Deque();
	bool addToEnd(const Command& aCommand);
	bool removeFromEnd();
	bool addToFront(const Command& aCommand);
	bool removeFromFront();
	bool peekEnd(Command&) const;
	bool peekFront(Command&) const;
	bool loadCommands();
	bool display();

};
#endif