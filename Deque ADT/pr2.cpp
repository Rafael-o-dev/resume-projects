/******************************************************************************
# Author:           Rafael O.
# Name:             Doubly Deque ADT
# Description:      This program will serve as a command history(using a doubly 
                    deque), the function keeps track of the command description 
                    with its sequence number, the user can choose to redo,undo, 
                    or display the commands, or quit at anytime.
# Input:            Commands.txt:
                        Deque class:
                            pointer to Command class:
                                pointer of char:
                                        desc - description of the Command
                                int:
                                        seqNum - the sequence number of the 
                                        Command
                                        
                    Command class:
                                pointer of char:
                                        tempDesc - description of the Command
                                int:
                                        tempSeqNum - the sequence number of 
                                        the command
                    Int:
                        toUndo - the number of comands to undo iven by user
                        toRedo - the number of commands to redo given by user
                    char:
                        option - the option given by user to execute a 
                        function
# Output:
                    Deque class:
                            pointer to Command class:
                                pointer of char:
                                        desc - description of the Command
                                int:
                                        seqNum - the sequence number of 
                                        the command
                    Int:
                        toUndo - the number of comands to undo iven by user
                        toRedo - the number of commands to redo given by user
#******************************************************************************/
#include "Functions.h"
int main()
{
    //constructor of the Deque class
    Deque list;
    //welcome message
    welcome();
    //Runs the command and prompt loop
    cmdLoop(list);
    //Displays the goodbye message
    goodbye();
    return 0;
}