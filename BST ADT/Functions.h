/******************************************************************************
Filename:  Functions.h
Purpose: this will create the neccesary function prototypes needed to execute
in the pr4.cpp program avoiding cluttering
#******************************************************************************/
#pragma once
#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_
#include "BST.h"

void readGNum(int&);

void readStanding(int&);

void displayStanding(int);

void addingStudent(BST&);

void removingStudent(BST& bst);

void removingProgram(BST& bst);

void welcome();

void mainPrompt();

void goodbye();

void cmdLoop(BST&);
#endif