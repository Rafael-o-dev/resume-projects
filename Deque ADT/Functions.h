/******************************************************************************
Filename:  Functions.h
Purpose: this will create the neccesary function prototypes needed to execute
in the pr2.cpp program avoiding cluttering
#******************************************************************************/
#pragma once
#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_
#include "Deque.h"

void readInt(int&);

void welcome();

void mainPrompt();

void goodbye();

void undo(Deque&);

void redo(Deque&);

void cmdLoop(Deque&);
#endif 