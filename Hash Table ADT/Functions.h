/******************************************************************************
Filename:  Functions.h
Purpose: this will create the neccesary function prototypes needed to execute
in the pr3.cpp program avoiding cluttering
#******************************************************************************/
#pragma once
#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_
#include "Table.h"

void readGNum(int&);

void readStanding(int&);

void displayStanding(int);

void addingStudent(Table&);

void editingStudent(Table&);

void welcome();

void mainPrompt();

void goodbye();

void cmdLoop(Table&);
#endif 