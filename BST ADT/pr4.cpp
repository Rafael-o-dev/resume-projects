/******************************************************************************
# Author:           Rafael Ojeda Tellez
# Project:       BST ADT
# Description:      This program will serve as a student BST that keeps track
                    of Students and their data(program, name, gNum, and
                    standing) and Allows the user to choose the following 
                    options: add a student, remove a student, remove a program, 
                    display the whole BST, monitor the height of the bst, 
                    retrieve, and the user can choose to quit at any time
# Input:            Students.txt:
                        BST class:
                            pointer to Student class:
                                pointer of char:
                                        program - program of the Student
                                        name - name of the Student
                                int:
                                        gNum - the gNum of the Student
                                Standing:
                                        standing - the standing of the Student
                    Student class:
                            Student class:
                                pointer of char:
                                        tempProgram - program of the Student
                                        tempName - name of the Student
                                int:
                                        tempgNum - the gNum of the
                                        Student
                                Standing:
                                        tempstanding - the standing
                                        of the Student
# Output:
                    BST class:
                            pointer to Student class:
                                pointer of char:
                                        program - program of the Student
                                        name - name of the Student
                                        tempName - name of the Student
                                int:
                                        gNum - the gNum of the Student
                                Standing:
                                        standing - the standing of the Student
                            Int
                                height - the max height of the the BST
#******************************************************************************/
#include "Functions.h"
int main()
{
    //constructor of the BST
    BST bst;
    //welcome message
    welcome();
    //Runs the command and prompt loop
    cmdLoop(bst);
    //Displays the goodbye message
    goodbye();
    return 0;
}