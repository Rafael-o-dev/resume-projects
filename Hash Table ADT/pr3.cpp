/******************************************************************************
# Author:           Rafael Ojeda Tellez
# Name:             Hash Table ADT project
# Description:      This program will serve as a student table that keeps track 
                    of Students and their data(program, name, gNum, and 
                    standing) and allows the user to choose the following 
                    options: add a student, remove unnacceptable standing 
                    students, display the whole table, edit a student's 
                    standing, monitor each chain length, and the user can 
                    choose to quit at any time
# Input:            Students.txt:
                        Table class:
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
                    Table class:
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
                                size - keeps track of the Net chain length across
                                the table
#******************************************************************************/
#include "Functions.h"
int main()
{
    //constructor of the Table
    Table table;
    //welcome message
    welcome();
    //Runs the command and prompt loop
    cmdLoop(table);
    //Displays the goodbye message
    goodbye();
    return 0;
}
