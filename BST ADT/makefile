CC = g++
CPPFLAGS = -Wall -g -std=c++11

pr4: pr4.o Student.o BST.o Functions.o

pr4.o: Student.h BST.h Functions.h 

Student.o: Student.h

BST.o: BST.h

Functions.o: Functions.h

.PHONY: clean

clean:
	$(info -- cleaning --)
	rm -f *.o
	rm -f pr4
