/******************************************************************************
Filename:  Functions.cpp
Purpose: this will create the neccesary function definitons needed to execute
in the pr2.cpp program avoiding cluttering
#******************************************************************************/
#include "Functions.h"
#include <iomanip>
//#include <iostream>
//Name:        readInt
//Description: Reads and validates the integer given by the user
//inputs:      int:
//					  num - the integer given by the user
//Outputs:     none
//return:      none
void readInt(int& num) {
	cout << "Enter the number of commands: ";
	cin >> num;
	//if the num is less than 1 or an invalid integer is entered this loop is
	//taken
	while ((!cin) || (num < 1)) {
		//clears stream--------
		cin.clear();
		cin.ignore(100, '\n');
		//---------------------
		cout << "Please enter a valid number: ";
		cin >> num;
	}
}
//Name:        undo
//Description: Attempts to undo toUndo(int) commands given by the user
//inputs:      Deque:
//					 list - Deque containing the commands
//			   int:
//					 toUndo - the number of commands to undo given by the user
//Outputs:     int:
//					 undid - the number of commands undid
//return:      none
void undo(Deque& list) {
	//local variables
	Command aCommand;
	int toUndo = 0;
	int undid = 0;
	//reads the number of commands to undo from the user
	readInt(toUndo);
	//Attempts to undo toUndo(int) commands
	for (int i = 0; i < toUndo; i++) {
		//local variables
		bool status = false;
		//if the End exists and successfuly assigns aCommand
		//from list, status is assigned true
		status = list.peekEnd(aCommand);
		//if status is still good(true), the following branch is taken
		if (status) {
			//if the End exists and successfuly removes the End
			//from list, status is assigned true
			status = list.removeFromEnd();
			//if status is still good(true), the following branch is taken
			if (status) {
				//if the aCommand is successfuly added to the front
				//of list, status is assigned true
				status = list.addToFront(aCommand);
				//if status is still good(true), the following branch is taken
				if (status) {
					//the number of undid commands is incremented
					undid++;
				}
			}
		}
		//if failure at anypoint, the loop is exited
		if (!status) {
			i = toUndo;
		}
	}
	//if the program did undo toUndo(int) commands
	//given by user the following branch is taken
	if (toUndo == undid) {
		cout << "After undo " << toUndo << " commands, the list is:\n";
		list.display();
	}
	//if the program didn't undo toUndo(int) commands given by user
	//but it did undo at least 1 command, the following branch is taken
	else if (undid > 0) {
		cout << "Error, couldn't undo " << toUndo << " commands. instead, \n";
		cout << undid << " commands were.\n";
		list.display();
	}
	//if the program didn't undo even one command the following branch is taken
	else {
		cout << "Error, couldn't undo " << toUndo << " commands.\n";
	}
}
//Name:        redo
//Description: Attempts to redo roRedo(int) commands given by the user
//inputs:      Deque Class:
//					 list - Deque containing the commands
//			   int:
//					 toRedo - the number of commands to redo given by the user
//Outputs:     int:
//					 redid - the number of commands redid
//return:      none
void redo(Deque& list) {
	//local variables
	Command aCommand;
	int toRedo = 0;
	int redid = 0;
	//reads the number of commands to redo from the user
	readInt(toRedo);
	//Attempts to redo toRedo(int) commands
	for (int i = 0; i < toRedo; i++) {
		//local variable
		bool status = false;
		//if the Front exists and successfuly assigns aCommand
		//from list, status is assigned true
		status = list.peekFront(aCommand);
		//if status is still good(true), the following branch is taken
		if (status) {
			//if the Front exists and successfuly removes the Front
			//from list, status is assigned true
			status = list.removeFromFront();
			//if status is still good(true), the following branch is taken
			if (status) {
				//if aCommand is successfuly added to the End
				//of list, status is assigned true
				status = list.addToEnd(aCommand);
				//if status is still good(true), the following branch is taken
				if (status) {
					//the number of redid commands is incremented
					redid++;
				}
			}
		}
		//if failure at anypoint, the loop is exited
		if (!status) {
			i = toRedo;
		}
	}
	//if the program did redo toRedo(int) commands 
	//given by user the following branch is taken
	if (toRedo == redid) {
		cout << "After redo " << toRedo << " commands, the list is:\n";
		list.display();
	}
	//if the program didn't undo toRedo(int) commands given by user
	//but it did redo at least 1 command, the following branch is taken
	else if (redid > 0) {
		cout << "Error, couldn't redo " << toRedo << " commands. instead, \n";
		cout << redid << " commands were.\n";
		list.display();
	}
	//if the program didn't redo even one command the following branch is taken
	else {
		cout << "Error, couldn't redo " << toRedo << " commands.\n";
	}
}

//Name:        cmdLoop
//Description: Allows the user to choose the following options:
//             undo, redo, display, and the user can choose 
//			   to quit at any time
//inputs:      char pointer
//				 option - the option of which function to do given by user	
//Outputs:	   none
//return:      none
void cmdLoop(Deque& list) {
	//local variables
	char option = 'z';
	bool valid = false;
	//if successfull in loading the file this branch is executed
	if (list.loadCommands()) {
		//since loading was successful the while loop can be taken
		valid = true;
		//displays the Commands List
		list.display();
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
			//if the user chose to add an Commands, the following branch is executed
			if (toupper(option) == 'U') {
				undo(list);
			}
			//if the user chose to display the list of Engineeers, the following branch is executed
			else if (toupper(option) == 'L') {
				list.display();
			}
			//if the user chose to remove Beginner Commandss, the following branch is executed
			else if (toupper(option) == 'R') {
				redo(list);
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
		cout << "Error in loading txt file or displaying list!!\n";
	}
}
//Name:        welcome
//Description: welcome message to the user
//inputs:      none
//Outputs:     none
//return:      none
void welcome() {
	cout << "Welcome User!\n What is the name of your Commandss file? ";
	cout << "File must be formatted\n(Index(int);Command(description))";
	cout << "to avoid failure. ";
}
//Name:        mainPrompt
//Description: prompt of options for the user
//inputs:      none
//Outputs:     none
//return:      none
void mainPrompt() {
	cout << endl << setw(25) << setfill('+') << endl;
	cout << "What would you like to do? (L)ist all the Commands, ";
	cout << "(U)ndo a certain number of command,\n(R)edo a certain ";
	cout << "number of commands, or (Q)uit? ";
}
//Name:        goodbye
//Description: goodbye message to the user
//inputs:      none
//Outputs:     none
//return:      none
void goodbye() {
	cout << "\nThanks for using my Command History program!!\n";
}
