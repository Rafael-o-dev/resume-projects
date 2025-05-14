/******************************************************************************
Filename:  Command.h
Purpose: this will create the neccesary member function prototypes needed to
execute throughout the program,it has the neccessary private data,command 
constructor(s), destructor, public functions for the Command ADT.
#******************************************************************************/
#pragma once
#ifndef COMMAND_H_
#define COMMAND_H_
#include <iostream>
#include <fstream>
#include <cstring>
const int STR_SIZE = 256;
using namespace std;
class Command {
private:
	//pointer to the first name of the Command
	char* desc;
	//the seqNum of the Command
	int seqNum;
public:
	//Command constructor
	Command();
	//Command copy constructor
	Command(const Command&);
	//Command assignment operator
	const Command& operator=(const Command&);
	//Command destructor
	~Command();
	//getters with the respective names
	const char* getDesc() const;
	int getSeqNum() const;
	//setters with the respective name
	void setDesc(const char*);
	void setSeqNum(int);
};
#endif