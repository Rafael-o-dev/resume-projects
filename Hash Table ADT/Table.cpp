/******************************************************************************
Filename:  Table.h
Purpose: this will create the neccesary member function definition needed to
execute throughout the program,it has the constructor(s), destructor, public
functions for the Table ADT.
#******************************************************************************/
#include "Table.h"
#include "Functions.h"
//Name:        Table constructor
//Description: constructs the new Table and its data set to invalid 
//			   values
//inputs:      none 
//Outputs:     none
//return:      none
Table::Table() {
	size = 0;
	currCap = CAP;
	aTable = new Node * [currCap];
	for (int i = 0; i < currCap; i++) {
		aTable[i] = NULL;
	}
}

//Name:        Table destructor
//Description: destroys an exisiting Table and its data
//inputs:      none
//Outputs:     none
//return:      none
Table::~Table() {
	//loop goes through each element of the table
	for (int i = 0; i < currCap; i++) {
		//destroys the chain
		destroyChain(aTable[i]);
	}
	//if aTable exists the following branch is taken
	if (aTable) {
		//deletes aTable
		delete[] aTable;
	}
}
//Name:        destroyChain
//Description: destroys the chain by recursion
//inputs:      Node pointer by reference
//					curr - the current node pointer
//Outputs:     none
//return:      none
void Table::destroyChain(Node *& curr) {
	if (curr) {
		destroyChain(curr->next);
		delete curr;
		size--;
	}
}
//Name:        addStudent
//Description: Attempts to add a Student to the head of Table 
//inputs:      Student:
//					aStudent - a Student to add to the table
//Outputs:     none
//return:      bool:
//				 status - the status of the function
bool Table::addStudent(const Student& aStudent) {
	//assigns the index based on the program
	int index = calculateIndex(aStudent.getProgram());
	//set status to true because aStudent was pre-verified
	bool status = true;
	//creates new node for the aStudent
	Node* addNode = new Node;
	//sets the prev and next pointers of addNode to NULL
	addNode->next = NULL;
	//assigns theStudent of addNode to aStudent
	addNode->theStudent = aStudent;
	//the pointer after addNode is head
	addNode->next = aTable[index];
	//addNode is now the head
	aTable[index] = addNode;
	size++;
	//returns the status of the function
	return status;
}
//Name:        calculateIndex
//Description: finds the index using the search key
//inputs:      char pointer:
//					key - the key to search in the table
//Outputs:     none
//return:      int num - 
//						 returns the index
int Table::calculateIndex(const char* key) const {
	//local variable
	int num = 0;
	//loop increments all the ascii values of key
	for (; *key != '\0'; key++) {
		num += *key;
	}
	//returns the num % by currCap
	return num % currCap;
}
//Name:        calculateIndex
//Description: attempts to edit the standing of a student
//inputs:      char pointer:
//					program - the program to search in the table
//					name - the name to search in the chain
//			   int:
//					newStanding - the new standing to apply to the
//								  student
//Outputs:     none
//return:      bool:
//					status - the status of the function
bool Table::edit(char* program, char* name, int newStanding) {
	//local variables
	bool status = false;
	Standing tempStanding;
	//assigns i the index of the program
	int i = calculateIndex(program);
	//loop traverses the chain till the end or name is found
	for (Node* curr = aTable[i]; curr || !status; curr = curr->next) {
		//if the name matches the current name, the following branch is taken
		if (strcmp(curr->theStudent.getName(), name) == 0) {
			//sets the node of where the standing was found
			tempStanding = curr->theStudent.getStanding();
			//if newStanding isn't the same as the current standing
			//the following branch is taken
			if (tempStanding != newStanding) {
				//assigns the current standing with the newStanding
				curr->theStudent.setStanding(newStanding);
				status = true;
			}
		}
	}
	//returns the status of the function
	return status;
}
//Name:        removeLowest
//Description: Attempts to remove all Students from the head of Table 
//inputs:      none
//Outputs:     none
//return:      bool:
//				 status - the status of the function
bool Table::removeLowest() {
	//local variables
	bool status = false;
	Node* prev = NULL;
	//loop goes through the each element in the table till currCap
	for (int i = 0; i < currCap; i++) {
		//loop traverses the entire chain
		for (Node * curr = aTable[i]; curr; curr = curr->next) {
			//if the cuurent standing matches unnacceptable, the following branch is taken
			if (curr->theStudent.getStanding() == Unnacceptable) {
				//If the Node pointer is at the head, then the following branch is taken
				if (!prev) {
					//the head is now the pointer after head
					aTable[i] = curr->next;
					//assigns previous with the head pointer to avoid 
					//unnecessary traversals
					prev = aTable[i];
				}
				//If the Node pointer is at the tail, then the following branch is taken
				else if (curr->next == NULL) {
					//The pointer after previous is NULL
					prev->next = NULL;
				}
				//If the Node pointer is in between the head and tail
				//then the following branch is taken
				else {
					//assigns the next pointer after the previous pointer
					//with the pointer after the current pointer
					//to remove the current pointer
					prev->next = curr->next;
				}
				//deletes the current pointer
				delete curr;
				//current is assigned with the previous pointer to avoid
				//unnecessary traversals
				curr = prev;
				status = true;
				size--;
			}
			prev = curr;
		}
	}
	return status;
}
//Name:        loadStudents
//Description: Reads all the data from "Students.txt" to load into Table
//inputs:      students.txt file
//Outputs:     none
//return:      bool:
//					status - the status of the function
bool Table::loadStudents() {
	//local variables----
	ifstream StudentFile;
	bool status = false;
	//opens fileName
	StudentFile.open("Students.txt");
	//StudentFile is opened succesfully, the following branch is taken
	if (StudentFile) {
		//local variable
		bool valid = true;
		//While the end of the file hasn't been reached, and the assignment 
		//was successful, the loop continues
		while ((!StudentFile.eof())&&(valid)) {
			//local variables---------------------
			Student aStudent;
			char tempProgram[STR_SIZE];
			char tempName[STR_SIZE];
			int tempGNum;
			int tempStanding;
			//collects the data per variables
			StudentFile.getline(tempProgram, STR_SIZE, ';');
			StudentFile.getline(tempName, STR_SIZE, ';');
			StudentFile >> tempGNum;
			StudentFile.get();
			StudentFile >> tempStanding;
			StudentFile.ignore(5, '\n');
			StudentFile.peek();
			//adds data to aStudent
			aStudent.setProgram(tempProgram);
			aStudent.setName(tempName);
			aStudent.setGNum(tempGNum);
			aStudent.setStanding(tempStanding);
			//adds the Student to the end of the Table
			//and assigns valid with the status of the function
			valid = addStudent(aStudent);
			status = true;
		}
		//closes file
		StudentFile.close();
	}
	//returns the status of the function
	return status;
}

//Name:        display
//Description: displays the table of Students formatted
//inputs:      none
//Outputs:	   Table class:
//                     pointer of char:
//                                      program - program of the Student
//                                      name - name of the Student
//                                      tempName - name of the Student
//                              int:
//                                      gNum - the gNum of the Student
//                              Standing:
//                                      standing - the standing of the Student
//return:       bool:
//					status - the status of the function
bool Table::display() {
	//local variables
	Node* curr = NULL;
	bool status = false;
	//if Table is not empty, the following branch is taken
	if (size > 0) {
		cout << "    " << left << setw(15) << "Program";
		cout << setw(14) << "Name";
		cout << setw(8) << "gNum";
		cout << setw(6) << "Standing\n";
		cout << "    " << left << setw(15) << "_______";
		cout << setw(14) << "__________";
		cout << setw(8) << "_____";
		cout << setw(6) << "______\n";
		//loop goes thorugh each index of the table till currCap
		for (int i = 0; i < currCap; i++) {
			//traverses each chain and displays the student formatted
			for (curr = aTable[i]; curr; curr = curr->next) {
				cout << "    " << left << setw(15) << curr->theStudent.getProgram();
				cout << left << setw(14) << curr->theStudent.getName();
				cout << curr->theStudent.getGNum() << "    ";
				displayStanding(curr->theStudent.getStanding());
				cout << endl;
			}
		}
		//successful in printing the table
		status = true;
	}
	//returns the status of the function
	return status;
}
//Name:        monitor
//Description: displays the chain length of each chain
//inputs:      none
//Outputs:	   int:
//					length - the chain length of the current chain
//return:       bool:
//					status - the status of the function
bool Table::monitor() {
	//local variable
	bool status = true;
	//loop goes thorugh each index of the table till currCap
	for (int i = 0; i < currCap; i++) {
		int length = 0;
		//traverses each chain and increments length per node in
		//the chain
		for (Node * curr = aTable[i]; curr; curr = curr->next) {
			length++;
		}
		//displays the chain length
		cout << "Chain " << i << " length: " << length << endl;
	}
	//returns the status of the function
	return status;
}
