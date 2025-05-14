/******************************************************************************
Filename:  BST.h
Purpose: this will create the neccesary member function definition needed to
execute throughout the program,it has the constructor(s), destructor, public
functions for the BST ADT.
#******************************************************************************/
#include "BST.h"
#include "Functions.h"
//Name:        BST constructor
//Description: constructs the new BST and its data set to invalid 
//			   values
//inputs:      none 
//Outputs:     none
//return:      none
BST::BST() {
	root = NULL;
	size = 0;
}

//Name:        BST destructor
//Description: destroys an exisiting BST and its data
//inputs:      none
//Outputs:     none
//return:      none
BST::~BST() {
	destroy(root);
}
//Name:        destroy
//Description: destroys the bst with a node pointer
//inputs:      Node pointer by reference
//					curr - the current node pointer
//Outputs:     none
//return:      none
void BST::destroy(Node*& curr) {
	if (curr) {
		destroy(curr->left);
		destroy(curr->right);
		//if error
		//delete curr->theStudent;
		delete curr;
		curr = NULL;
	}
}
//Name:        add
//Description: attempts to add a aStudent into the bst, and changes status
//			   if the function was succesful or not, using recursion
//inputs:      Node pointer by reference
//					curr - the current node pointer
//			   Student by const reference:
//					aStudent - a Student to add to the BST
//			   bool by reference:
//				 status - the status of the function
//Outputs:     none
//return:      none
void BST::add(Node*& curr, const Student& aStudent, bool& status) {
	//if the curr pointer is empty/NULL, the following branch is taken
	if (!curr) {
		//creates new node for the aStudent
		Node* addNode = new Node;
		//sets the right and left pointers of addNode to NULL
		addNode->right = NULL;
		addNode->left = NULL;
		//assigns theStudent of addNode to aStudent
		addNode->theStudent = aStudent;
		//curr pointer is now the new node
		curr = addNode;
		//function was succesful
		status = true;
		//size is incremented
		size++;
	}
	//if the gNum of aStudent is less than the curr gNum, the following branch is taken  
	else if (aStudent.getGNum() < curr->theStudent.getGNum()) {
		//travereses the left subtree
		add(curr->left, aStudent, status);
	}
	//if the gNum of aStudent is greater than the curr gNum, the following branch is taken
	else {
		//traverses the right subtree
		add(curr->right, aStudent, status);
	}
}
//Name:        displayInOrder
//Description: displays the BST of the Students formatted in order from
//			   least to greatest
//inputs:      Node pointer by reference
//					curr - the current node pointer
//Outputs:	   BST class:
//                     pointer of char:
//                                      program - program of the Student
//                                      name - name of the Student
//                     int:
//                                      gNum - the gNum of the Student
//                     Standing:
//                                      standing - the standing of the Student
//return:      none
void BST::displayInOrder(Node* curr) {
	//if curr exists, the following branche is taken
	if (curr) {
		//traverses till the very end of the left subtree
		//displays the student and its data
		displayInOrder(curr->left);
		cout << "    " << left << setw(15) << curr->theStudent.getProgram();
		cout << left << setw(14) << curr->theStudent.getName();
		cout << curr->theStudent.getGNum() << "    ";
		displayStanding(curr->theStudent.getStanding());
		cout << endl;
		//traverses till the very end of the right subtree
		displayInOrder(curr->right);
	}
}
//Name:        remove(private)
//Description: attempts to remove a student from the bst with
//			   the matching aGNum using recursion
//inputs:      Node pointer by reference
//					curr - the current node pointer
//			   const int:
//                 aGNum - the gNum to search for in the bst
//Outputs:     none
//return:      none
bool BST::remove(Node*& curr, const int aGNum) {
	bool status = false;
	if (curr) {
		//if the curr gNum is the same as aGNum, the following branch is taken
		if (curr->theStudent.getGNum() == aGNum) {
			//deletes the node from the bst
			deleteNode(curr);
			//the aGNum to search for in the bst was found, status is successful
			status = true;
		}
		//if the curr gNum is greater than aGNum, the following branch is taken
		else if (curr->theStudent.getGNum() > aGNum) {
			//traverses the left subtree and returns the status
			return remove(curr->left, aGNum);
		}
		//if the curr gNum is less than aGNum, the following branch is taken
		else {
			//traverses the right subtree and returns the status
			return remove(curr->right, aGNum);
		}
	}
	//returns the status of the function
	return status;
}
//Name:        retrieve
//Description: attempts to retrieve a student with the matching aGNum
//			   by referenece, by calling the private recursive function
//			   retrieval()
//inputs:      Student by reference
//					aStudent - the student and its data if found
//			   const int:
//                 aGNum - the gNum to search for in the bst
//Outputs:     none
//return:      bool:
//				 status - the status of the function
bool BST::retrieve(Student& aStudent, const int aGNum) const {
	//local variable
	bool status = false;
	//calls on retrieval and passes status by reference to change status
	retrieval(root, aStudent, aGNum, status);
	//returns the status of the function
	return status;
}
//Name:        retrieval(private)
//Description: attempts to retrieve a student with the matching aGNum
//			   by referenece, by recursion and changes status to true if 
//			   found
//inputs:      Node pointer by reference:
//					curr - the current pointer of the bst
//			   Student by reference:
//					aStudent - the student and its data if found
//			   const int:
//                  aGNum - the gNum to search for in the bst
//			   bool by reference:
//				 status - the status of the function
//Outputs:     none
//return:      none
void BST::retrieval(Node* curr, Student& aStudent, const int aGNum, bool& status) const {
	//if curr pointer exists, the following branch is taken
	if (curr) {
		//if the curr gNum is the same as aGNum, the following branch is taken
		if (curr->theStudent.getGNum() == aGNum) {
			//assigns aStudent's data with the current student's data
			aStudent = curr->theStudent;
			//the aGNum to search for in the bst was found, returns success
			status = true;
		}
		//if the curr gNum is greater than aGNum, the following branch is taken
		else if (curr->theStudent.getGNum() > aGNum) {
			retrieval(curr->left,aStudent, aGNum, status);
		}
		//if the curr gNum is less than aGNum, the following branch is taken
		else {
			retrieval(curr->right, aStudent, aGNum, status);
		}
	}
}
//Name:        removeP(private)
//Description: attempts to find any student in aProgram
//			   and remove them from the bst by calling deleteNode()
//inputs:      Node pointer by reference
//					curr - the current node pointer
//			   pointer of char:
//					aProgram - the program to search for and delete its 
//							   students
//			   bool by reference:
//					status - the status of the function
//Outputs:     none
//return:      none
void BST::removeP(Node*& curr, char* aProgram, bool & status) {
	//if curr exists, the following branch is taken
	if (curr) {
		//traverses the very left of the curr subtree
		removeP(curr->left, aProgram, status);
		//traverses the very right of the curr subtree
		removeP(curr->right, aProgram, status);
		//if the curr program matches aProgram, the following branch is taken
		if (strcmp(curr->theStudent.getProgram(), aProgram) == 0) {
			//deletes the current node pointer from bst
			deleteNode(curr);
			//function was successful
			status = true;
		}
	} 
}
//Name:        deleteNode
//Description: deletes curr from the bst using recursion
//inputs:      Node pointer by reference
//					curr - the current node pointer
//Outputs:     none
//return:      none
void BST::deleteNode(Node*& curr) {
	//if the node is a leaf, the following branch is taken
	if (!curr->left && !curr->right) {
		//deletes curr
		delete curr;
		curr = NULL;
	}
	//if the nodes has a left child, the following branch is taken
	else if (!curr->right) {
		//local variable
		Node* temp = curr;
		//replaces curr with the left child
		curr = curr->left;
		//deletes the unlinked node
		delete temp;
	}
	//if the nodes has a right child, the following branch is taken
	else if (!curr->left) {
		//local variable
		Node* temp = curr;
		//replaces curr with the right child
		curr = curr->right;
		//deletes the unlinked node
		delete temp;
	}
	//if curr has 2 children, the following branch is taken
	else {
		//local variables
		Node* prev = NULL;
		//tCurr is set to the right child of curr
		Node* tCurr = curr->right;
		//if tCurr does not have a left child, the following branch is taken
		if (!tCurr->left) {
			//assigns the right child of the curr node with 
			curr->right = tCurr->right;
		}
		//if tCurr does have a left child, the following branch is taken
		else {
			//while tCurr has a left child
			while (tCurr->left) {
				//previous pointer assigned with tCurr
				prev = tCurr;
				//traverses the left subtree of tCurr
				tCurr = tCurr->left;
			}
			//assigns the left child of previous with the right child of tCurr
			prev->left = tCurr->right;
		}
		//assigns the current student with the tCurr student
		curr->theStudent = tCurr->theStudent;
		delete tCurr;
	}
	size--;
}
//Name:        removeProgram
//Description: attempts to find any student in aProgram
//			   and remove them from the bst by calling recursive function
//			   removeP()
//inputs:      pointer of char:
//					aProgram - the program to search for and delete its 
//							   students
//Outputs:     none
//return:      bool:
//					status - the status of the function
bool BST::removeProgram(char* aProgram) {
	//local variables
	bool status = false;
	Node* curr = root;
	//call the recursive function to remove students in aProgram
	removeP(curr, aProgram, status);
	//returns the status of the function
	return status;
}
//Name:        removeStudent
//Description: attempts to remove a student from the bst with
//			   the matching aGNum using recursive function remove()
//inputs:      const int:
//                 aGNum - the gNum to search for in the bst
//Outputs:     none
//return:      bool:
//					status - the status of the function
bool BST::removeStudent(const int aGNum) {
	//local variables
	bool status = false;
	Node* curr = root;
	//sets status with success or failure
	status = remove(curr, aGNum);
	//returns the status of the function
	return status;
}
//Name:        addStudent
//Description: Attempts to add a Student in the bstm using 
//			   the recursive function add()
//inputs:      Student:
//					aStudent - a Student to add to the BST
//Outputs:     none
//return:      bool:
//				 status - the status of the function
bool BST::addStudent(const Student& aStudent) {
	//local variables
	bool status = false;
	//calls on the recursive function add and passes status 
	//by reference
	add(root, aStudent, status);
	//return the status of the function
	return status;
}
//Name:        loadStudents
//Description: Reads all the data from "Students.txt" to load into BST
//inputs:      students.txt file
//Outputs:     none
//return:      bool:
//					status - the status of the function
bool BST::loadStudents() {
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
		while ((!StudentFile.eof()) && (valid)) {
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
			//adds the Student to the end of the BST
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
//Description: displays the BST of Students formatted im order
//inputs:      none
//Outputs:	   BST class:
//                     pointer of char:
//                                      program - program of the Student
//                                      name - name of the Student
//                              int:
//                                      gNum - the gNum of the Student
//                              Standing:
//                                      standing - the standing of the Student
//return:       bool:
//					status - the status of the function
bool BST::display() {
	//local variables
	bool status = false;
	//if the tree is not empty, the following branch is taken
	if (size > 0) {
		cout << "    " << left << setw(15) << "Program";
		cout << setw(14) << "Name";
		cout << setw(8) << "gNum";
		cout << setw(6) << "Standing\n";
		cout << "    " << left << setw(15) << "_______";
		cout << setw(14) << "__________";
		cout << setw(8) << "_____";
		cout << setw(6) << "______\n";
		//displays the tree in order
		displayInOrder(root);
		//successful in printing the bst
		status = true;
	}
	//returns the status of the function
	return status;
}
//Name:        monitor
//Description: returns the height of the tree using the recursive 
//			   function getHeight()
//inputs:      none
//Outputs:	   none   
//return:      int:
//   				height - height of the tree
int BST::monitor() {
	//local variables
	int height = 0;
	//finds the height of the tree
	height = getHeight(root);
	//returns the height of the tree
	return height;
}
//Name:        getHeight
//Description: returns the height of the tree using the recursion
//inputs:      none
//Outputs:	   none   
//return:      int:
//   				height - height of the tree
int BST::getHeight(Node* curr) {
	//if curr does not exist the following branch is taken
	if (!curr) {
		//height is 0
		return 0;
	}
	//if curr does exist the following branch is taken
	else {
		//returns the max height from the root to the highest level/height
		return 1 + max(getHeight(curr->left), getHeight(curr->right));
	}
}
