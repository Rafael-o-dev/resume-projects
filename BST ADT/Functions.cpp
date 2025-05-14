/******************************************************************************
Filename:  Functions.cpp
Purpose: this will create the neccesary function definitons needed to execute
in the pr3.cpp program avoiding cluttering
#******************************************************************************/
#include "Functions.h"
//#include <iostream>
//Name:        readGNum
//Description: Reads and validates the gNum given by the user
//inputs:      int:
//					  gNum - the gNum given by the user
//Outputs:     none
//return:      none
void readGNum(int& num) {
	cout << "Enter the student's g number(1000-9999) : ";
	cin >> num;
	//if the num is less than 1 or an invalid integer is entered this loop is
	//taken
	while ((!cin) || (num < 1000) || (num > 9999)) {
		//clears stream--------
		cin.clear();
		cin.ignore(100, '\n');
		//---------------------
		cout << "Please enter a valid number(1000-9999): ";
		cin >> num;
	}
}
//Name:        readStanding
//Description: Reads and validates the standing given by the user
//inputs:      int:
//					  standing - the standing of an Engineer
//Outputs:     none
//return:      none
void readStanding(int& standing) {
	//prompt
	cout << "What is the new standing? 1(Unnacceptable), 2(Improving), 3(Average)";
	cout << ", 4(Advanced), 5(Prodigy);";
	//collect standing
	cin >> standing;
	//if the standing is less than Beginner or higher than Expert than this loop is taken
	while ((!cin) || (standing < Unnacceptable) || (standing > Prodigy)) {
		//clears stream--------
		cin.clear();
		cin.ignore(100, '\n');
		//repeat collection
		cout << "Please enter a valid standing 1-5: ";
		cin >> standing;
	}
}
//Name:        setStanding
//Description: displays the standing formated
//inputs:      int
//					standing - the standing of the user
//Outputs:     standing/exeperience formated
//return:      none
void displayStanding(int standing) {
	switch (standing) {
	case Unnacceptable:
		cout << "Unnacceptable";
		break;
	case Improving:
		cout << "Improving";
		break;
	case Average:
		cout << "Average";
		break;
	case Advanced:
		cout << "Advanced";
		break;
	case Prodigy:
		cout << "Prodigy";
		break;
		//occurs if an error occured
	default:
		cout << "Unknown";
		break;
	}
}
//Name:        addingStudent
//Description: collects and adds a newStudent to the BST
//inputs:      Student class:
//                              pointer of char:
//                                      tempProgram - program of the Student
//                                      tempName - name of the Student
//                              int:
//                                      tempgNum - the gNum of the
//                                      Student
//                              Standing:
//                                      tempstanding - the standing
//                                       of the Student
//Outputs:     pointer of char:
//                                      tempName - name of the Student
//return:      none
void addingStudent(BST& bst) {
	//local variables---------------------
	bool valid = false;
	Student aStudent;
	char tempProgram[STR_SIZE];
	char tempName[STR_SIZE];
	int tempGNum;
	int tempStanding;
	//collects the data per variables
	cout << "What is the program the student is in? ";
	cin.getline(tempProgram, STR_SIZE, '\n');
	cout << "What is the student's name? ";
	cin.getline(tempName, STR_SIZE, '\n');
	readGNum(tempGNum);
	readStanding(tempStanding);
	//adds data to aStudent
	aStudent.setProgram(tempProgram);
	aStudent.setName(tempName);
	aStudent.setGNum(tempGNum);
	aStudent.setStanding(tempStanding);
	//adds the Student to the head of the chain
	//and assigns valid with the status of the function
	valid = bst.addStudent(aStudent);
	//success message
	if (valid) {
		cout << "successfuly added " << tempName << " into the BST";
	}
	//failure message
	else {
		cout << "Failed to add " << tempName << " into the BST";
	}
}
//Name:        removingStudent
//Description: collects a gNum of a student to remove from the bst
//inputs:      
//             int:
//					tempGNum - the gNum to search for                                    
//Outputs:     none
void removingStudent(BST& bst) {
	//local variables
	bool valid = false;
	int tempGNum;
	//collects the tempGNum to search for
	readGNum(tempGNum);
	//assigns valid with the status of the function
	valid = bst.removeStudent(tempGNum);
	//following branch is taken if the function was successful
	if (valid) {
		cout << "Succeeded in removing student.\n";
	}
	//following branch is taken if function failed
	else {
		cout << "Failed in removing student!\n";
	}
}
//Name:        retrievingStudent
//Description: collects a gNum of a student and retrieve its data
//inputs:      BST by reference:
//					bst - the binary search tree
//             int:
//					tempGNum - the gNum to search for                                    
//Outputs:     none
void retrievingStudent(BST& bst) {
	//local variables
	bool valid = false;
	int tempGNum;
	Student tempStudent;
	//collects the tempGNum to search for
	readGNum(tempGNum);
	//assigns valid with the status of the function
	valid = bst.retrieve(tempStudent,tempGNum);
	//following branch is taken if the function was successful
	if (valid) {
		cout << "found student:\n";
		cout << "    " << left << setw(15) << tempStudent.getProgram();
		cout << left << setw(14) << tempStudent.getName();
		cout << tempStudent.getGNum() << "    ";
		displayStanding(tempStudent.getStanding());
	}
	//following branch is taken if function failed
	else {
		cout << "Failed in finding student!\n";
	}
}
//Name:        removingProgram
//Description: collects and attempts to remove students from a program
//inputs:      pointer of char:
//							   tempProgram - the program to search for and
//							                 remove from the bst                              
//Outputs:     pointer of char:
//							   tempProgram - the program to search for and
//							                 remove from the bst    
void removingProgram(BST& bst) {
	//local variables
	bool valid = false;
	char tempProgram[STR_SIZE];
	//collects the tempProgram from the user
	cout << "What is the program the student is in? ";
	cin.getline(tempProgram, STR_SIZE, '\n');
	//assigns valid with the status of the function
	valid = bst.removeProgram(tempProgram);
	//following branch is taken if the function was successful
	if (valid) {
		cout << "Succeeded in removing students in " << tempProgram << ".\n";
	}
	//following branch is taken if function failed
	else {
		cout << "Failed in removing students in " << tempProgram << ".\n";
	}
}
//Name:        cmdLoop
//Description: Allows the user to choose the following options:
//             add a student, remove a student, remove a program, display
//             the whole BST, monitor performance of the bst, retrieve,
//			   and the user can choose to quit at any time
//inputs:      char pointer
//				 option - the option of which function to do given by user	
//Outputs:	   none
//return:      none
void cmdLoop(BST& bst) {
	//local variables
	char option = 'z';
	bool valid = false;
	//if successfull in loading the file this branch is executed
	if (bst.loadStudents()) {
		//since loading was successful the while loop can be taken
		valid = true;
		//displays the Students BST
		bst.display();
		//while the user doesn't quit or an error occurs this loop will continue
		//to run
		while (valid) {
			//prompts the user for the options they can pick
			mainPrompt();
			//collects option
			cin >> option;
			cout << endl;
			//clear buffer
			cin.ignore(100, '\n');
			//if the user chose to add a Student, the following branch is executed
			if (toupper(option) == 'A') {
				addingStudent(bst);
			}
			//if the user chose to display the BST of Students , the following branch is executed
			else if (toupper(option) == 'D') {
				bst.display();
			}
			//if the user chose to remove a program, the following branch is executed
			else if (toupper(option) == 'P') {
				removingProgram(bst);
			}
			//if the user chose to remove a student, the following branch is executed
			else if (toupper(option) == 'R') {
				removingStudent(bst);
			}
			//if the user chose to monitor, the following branch is executed
			else if (toupper(option) == 'M') {
				cout << "height of the tree: " << bst.monitor() << endl;
			}
			//if the user chose to retrieve, the following branch is executed
			else if (toupper(option) == 'T') {
				retrievingStudent(bst);
			}
			// if the user chose to quit, the following branch is executed
			else if (toupper(option) == 'Q') {
				valid = false;
			}
			// if the user entered an invalid option, the following branch is taken
			else {
				cout << "Invalid option, try again\n";
			}

		}
	}
	//If an invalid file was entered, the following branch is taken
	else {
		cout << "Error in loading txt file or displaying BST!!\n";
	}
}
//Name:        welcome
//Description: welcome message to the user
//inputs:      none
//Outputs:     none
//return:      none
void welcome() {
	cout << "Welcome User!\nThis is my student BST program\n";
}
//Name:        mainPrompt
//Description: prompt of options for the user
//inputs:      none
//Outputs:     none
//return:      none
void mainPrompt() {
	cout << "\nWhat would you like to do? (D)isplay all the Students, ";
	cout << "(A)dd a student, (R)emove a student\n (P) to delete ";
	cout << "students of a program, (M)onitor the length of each chain or (Q)uit? ";
}
//Name:        goodbye
//Description: goodbye message to the user
//inputs:      none
//Outputs:     none
//return:      none
void goodbye() {
	cout << "\nThanks for using my student BST program!!\n";
}