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
//Description: collects and adds a newStudent to the table
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
void addingStudent(Table& table) {
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
	valid = table.addStudent(aStudent);
	//success message
	if (valid) {
		cout << "successfuly added " << tempName << " into the table";
	}
	//failure message
	else {
		cout << "Failed to add " << tempName << " into the table";
	}
}
void editingStudent(Table& table) {
	//local variables
	bool valid = false;
	char tempProgram[STR_SIZE];
	char tempName[STR_SIZE];
	int tempStanding;
	//collects the data per program and name to search for
	cout << "What is the program the student is in? ";
	cin.getline(tempProgram, STR_SIZE, '\n');
	cout << "What is the student's name? ";
	cin.getline(tempName, STR_SIZE, '\n');
	readStanding(tempStanding);
	//assigns valid with the status of the function
	valid = table.edit(tempProgram, tempName, tempStanding);
	//following branch is takenif the functions was successful
	if (valid) {
		cout << "Succeeded in editing " << tempName << "'s standing\n";
	}
	//following branch is taken if function failed
	else {
		cout << "Failed in editing " << tempName << "'s standing!\n";
	}
}
//Name:        cmdLoop
//Description: Allows the user to choose the following options:
//             add a student, remove unnacceptable standing students, display
//             the whole table, edit a student's standing, monitor each chain
//             length, and the user can choose to quit at any time
//inputs:      char pointer
//				 option - the option of which function to do given by user	
//Outputs:	   none
//return:      none
void cmdLoop(Table& table) {
	//local variables
	char option = 'z';
	bool valid = false;
	//if successfull in loading the file this branch is executed
	if (table.loadStudents()) {
		//since loading was successful the while loop can be taken
		valid = true;
		//displays the Students table
		table.display();
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
				addingStudent(table);
			}
			//if the user chose to display the table of Students , the following branch is executed
			else if (toupper(option) == 'D') {
				table.display();
			}
			//if the user chose to edit a Student standing, the following branch is executed
			else if (toupper(option) == 'E') {
				editingStudent(table);
			}
			//if the user chose to remove Beginner Studentss, the following branch is executed
			else if (toupper(option) == 'R') {
				if (table.removeLowest()) {
					cout << "removed all unnacceptable standing students.\n";
				}
				else {
					cout << "Didn't remove any unnacceptable standing students!\n";
				}
			}
			else if (toupper(option) == 'M') {
				table.monitor();
			}
			//else if (toupper(option) == 'T') {
				//table.retrieve();
			//}
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
		cout << "Error in loading txt file or displaying table!!\n";
	}
}
//Name:        welcome
//Description: welcome message to the user
//inputs:      none
//Outputs:     none
//return:      none
void welcome() {
	cout << "Welcome User!\nThis is my student table program\n";
}
//Name:        mainPrompt
//Description: prompt of options for the user
//inputs:      none
//Outputs:     none
//return:      none
void mainPrompt() {
	cout << "\nWhat would you like to do? (D)isplay all the Students, ";
	cout << "(E)dit a student's standing,\n(R)emove Unnacceptable ";
	cout << "Students, (M)onitor the length of each chain or (Q)uit? ";
}
//Name:        goodbye
//Description: goodbye message to the user
//inputs:      none
//Outputs:     none
//return:      none
void goodbye() {
	cout << "\nThanks for using my student table program!!\n";
}
