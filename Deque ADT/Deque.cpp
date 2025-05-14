/******************************************************************************
Filename:  Deque.h
Purpose: this will create the neccesary member function definition needed to
execute throughout the program,it has the constructor(s), destructor, public 
functions for the Deque ADT.
#******************************************************************************/
#include "Deque.h"

//Name:        Deque constructor
//Description: constructs the new Deque and its data set to invalid 
//			   values
//inputs:      none 
//Outputs:     none
//return:      none
Deque::Deque() {
	counter = 0;
	undo = 0;
	front = NULL;
	rear = NULL;
}

//Name:        Deque destructor
//Description: destroys an exisiting Deque and its data
//inputs:      none
//Outputs:     none
//return:      none
Deque::~Deque() {
	//local variable
	Node* curr = front;
	//while curr points to a valid address it will delete it's contents 
	//and move onto the next address
	while (front != NULL) {
		curr = front->next;
		delete front;
		front = curr;
	}
}
//Name:        addToEnd
//Description: Attempts to add a Command to the end of Deque 
//inputs:      Command:
//					aCommand - a Command to add to the list
//Outputs:     none
//return:      bool:
//				 status - the status of the function
bool Deque::addToEnd(const Command& aCommand) {
	//set status to true because aCommand was pre-verified
	bool status = true;
	//creates new node for aCommand
	Node* addNode = new Node; 
	//sets the prev and next pointers of addNode to NULL
	addNode->prev = NULL;
	addNode->next = NULL;
	//assigns theCommand of addNode to aCommand
	addNode->theCommand = aCommand;
	//if no front pointer exists, the following branch is taken
	if (!front) {
		//addNode is both the front and rear of deque
		front = addNode;
		rear = addNode;
	}
	//if a front pointer exists, the following branch is taken
	else {
		//the next pointer after rear is addNode
		rear->next = addNode;
		//the pointer before addNode is rear
		addNode->prev = rear;
		//addNode is now rear
		rear = addNode;
	}
	//returns the status of the function
	return status;
}
//Name:        addToFront
//Description: Attempts to add a Command to the Front of Deque 
//inputs:      Command:
//					aCommand - a Command to add to the list
//Outputs:     none
//return:      bool:
//				 status - the status of the function
bool Deque::addToFront(const Command& aCommand) {
	//set status to true because aCommand was pre-verified
	bool status = true;
	//creates new node for the aCommand
	Node* addNode = new Node;
	//sets the prev and next pointers of addNode to NULL
	addNode->prev = NULL;
	addNode->next = NULL;
	//assigns theCommand of addNode to aCommand
	addNode->theCommand = aCommand;
	//sets the pointer before the front to addNode
	front->prev = addNode;
	//the pointer after addNode is front
	addNode->next = front;
	//addNode is now the front
	front = addNode;
	//returns the status of the function
	return status;
}
//Name:        removeFromEnd
//Description: Attempts to remove a Command from the end of Deque 
//inputs:      none
//Outputs:     none
//return:      bool:
//				 status - the status of the function
bool Deque::removeFromEnd() {
	//local variables
	bool status = false;
	Node* end = rear;
	//if undo is less than counter, the following branch is taken
	//it prevents from undoing commands that have already been undone
	if (undo < counter) {
		//removes the rear from deque
		rear->prev->next = NULL;
		//assigns rear to the pointer before rear
		rear = rear->prev;
		//deletes the end node
		delete end;
		end = NULL;
		//successfully removed end 
		status = true;
		//undo is incremented
		undo++;
	}
	//returns the status of the function
	return status;
}
//Name:        removeFromFront
//Description: Attempts to remove a Command from the front of Deque 
//inputs:      none
//Outputs:     none
//return:      bool:
//				 status - the status of the function
bool Deque::removeFromFront() {
	//local variables
	bool status = false;
	Node* top = front;
	//if undo is greater than 0, the following branch is taken
	//prevents from redoing commands that haven't been undone
	if (undo > 0) {
		//sets front pointer to the pointer after front
		front = front->next;
		//the pointer before front is NULL
		front->prev = NULL;
		//deletes the top node
		delete top;
		top = NULL;
		//successfully redid a command
		status = true;
		//decrements undo 
		undo--;
	}
	//returns the status of the function
	return status;
}
//Name:        peekEnd
//Description: Attempts to assign aCommand with the end command of the deque 
//inputs:      none
//Outputs:     none
//return:      bool:
//				 status - the status of the function
bool Deque::peekEnd(Command& aCommand) const {
	//local variable
	bool status = false;
	//if rear exists, the following branch is taken
	if (rear) {
		//assigns aCommand with the command from rear
		aCommand = rear->theCommand;
		//succesfully assigned aCommand
		status = true;
	}
	//return the status of the function
	return status;
}
//Name:        peekFront
//Description: Attempts to assign aCommand with the front command of the deque 
//inputs:      none
//Outputs:     none
//return:      bool:
//				 status - the status of the function
bool Deque::peekFront(Command& aCommand) const {
	//local variable
	bool status = false;
	//if front exists, the following branch is taken
	if (front) {
		//assigns aCommand with the command from front
		aCommand = front->theCommand;
		//successfully assigned aCommand
		status = true;
	}
	//returns the status of the function
	return status;
}
//Name:        loadCommands
//Description: Reads all the data from "Commands.txt" to load into Deque
//inputs:      none
//Outputs:     none
//return:      bool:
//					status - the status of the function
bool Deque::loadCommands() {
	//local variables----
	ifstream CommandFile;
	bool status = false;
	//opens fileName
	CommandFile.open("Commands.txt");
	//CommandFile is opened succesfully, the following branch is taken
	if (CommandFile) {
		//local variable
		bool valid = true;
		//While the end of the file hasn't been reached, and the assignment 
		//was successful, the loop continues
		while (!CommandFile.eof()){
			//local variables---------------------
			Command aCommand;
			char tempDesc[STR_SIZE];
			int tempNum;
			//collects the data per variables
			CommandFile >> tempNum;
			CommandFile.get();
			CommandFile.getline(tempDesc, STR_SIZE, '\n');
			CommandFile.peek();
			//adds data to aCommand
			aCommand.setSeqNum(tempNum);
			aCommand.setDesc(tempDesc);
			//adds the command to the end of the deque
			//and assigns valid with the status of the function
			valid = addToEnd(aCommand);
			//increases the counter of Deque with each successfull 
			//addition
			if (valid) {
				counter++;
				//successful in loading commmands
				status = true;
			}
		}
		//closes file
		CommandFile.close();
	}
	//returns the status of the function
	return status;
}

//Name:        display
//Description: displays the list of Commands formatted
//inputs:      none
//Outputs:	   Deque class:
//                     pointer to Command class:
//                            pointer of char:
//                                   desc - the description of the command
//                            int:
//                                   seqNum - the sequence number of the Command
//return:       bool
bool Deque::display() {
	//local variables
	Node* curr = NULL;
	int tempUndo = undo;
	bool status = false;
	//if Deque is not empty, the following branch is taken
	if (counter > 0) {
		cout << endl;
		//prints the deque from front to end
		for (curr = front; curr; curr = curr->next) {
			cout << curr->theCommand.getSeqNum();
			cout << ". " << curr->theCommand.getDesc();
			cout << endl;
			//if it was an undone function, seperated with an extra endline
			if (tempUndo > 0) {
				cout << endl;
				//decrements the number of tempUndo
				tempUndo--;
			}
		}
		cout << endl;
		//successful in printing the list
		status = true;
	}
	//returns the status of the function
	return status;
}

