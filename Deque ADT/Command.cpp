/******************************************************************************
Filename:  Command.cpp
Purpose: this will create the neccesary member function definitions needed to
execute throughout the program,it has the neccessary private data,
constructor(s), destructor, and setters/getters for the Command ADT.
#******************************************************************************/
#include "Command.h"
using namespace std;
//Name:        Command constructor
//Description: constructs the new Command and its data
//inputs:      none 
//Outputs:     none
//return:      none
Command::Command() {
	//desc created and set to Unknown
	desc = new char[10];
	strcpy(desc, "(unknown)");
	//seqNum created and set to -1
	seqNum = -1;

}
//Name:        Command copy constructor
//Description: copys an existing Command and its data
//			   onto another existing Command
//inputs:      none
//Outputs:     none
//return:      none
Command::Command(const Command& otherCommand) {
	//creates pointers to the respective names
	//with the only neccesary size
	desc = new char[strlen(otherCommand.desc) + 1];
	//copies the Command onto the other Command
	*this = otherCommand;
}
//Name:        Command destructor
//Description: destroys an exisiting Command and its data
//inputs:      none
//Outputs:     none
//return:      none
Command::~Command() {
	//if desc delete the name and its pointer
	if (desc) {
		delete[] desc;
		desc = NULL;
	}
}
//Name:        Command assignment operator
//Description: Allows an Command and it's data to be directly assigned to 
//			   another Command
//inputs:      Command:
//					OtherCommand - an Command to asign to a different 
//					Command
//Outputs:     none
//return:      none
const Command& Command::operator=(const Command& otherCommand) {
	//avoids self aassignment
	if (this != &otherCommand) {
		//sets the respective data onto the private data
		this->setDesc(otherCommand.desc);
		this->seqNum = otherCommand.seqNum;
	}
	return *this;
}
//Name:        respective getters
//Description: retrieve the respective data  
//inputs:      none
//Outputs:     none
//return:      resective data
const char* Command::getDesc() const{
	return desc;
}
int Command::getSeqNum() const{
	return seqNum;
}
//Name:        setDesc
//Description: sets the private data desc with the
//			   user given desc 
//inputs:      char pointer
//					desc - the first name of an Command
//Outputs:     none
//return:      none
void Command::setDesc(const char* desc) {
	//if desc exists, delete it along with the pointer
	if (this->desc != NULL) {

		delete[] this->desc;
		this->desc = NULL;
	}
	//sets passed desc onto private desc
	this->desc = new char[strlen(desc) + 1];
	strcpy(this->desc, desc);
}
//Name:        setSeqNum
//Description: sets the private data seqNum with the
//			   user given seqNum 
//inputs:      int
//					seqNum - the Level/seqNum of the user
//Outputs:     none
//return:      none
void Command::setSeqNum(int seqNum) {
	//Assigns private seqNum with parameter seqNum 
	this->seqNum = seqNum;
}