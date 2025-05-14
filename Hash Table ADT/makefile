CC = g++
CPPFLAGS = -Wall -g -std=c++11

pr3: pr3.o Student.o Table.o Functions.o

pr3.o: Student.h Table.h Functions.h 

Student.o: Student.h

Table.o: Table.h

Functions.o: Functions.h

.PHONY: clean

clean:
	$(info -- cleaning --)
	rm -f *.o
	rm -f pr3
