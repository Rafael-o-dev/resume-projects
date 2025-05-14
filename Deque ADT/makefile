CC = g++
CPPFLAGS = -Wall -g -std=c++11

pr2: pr2.o Command.o Deque.o Functions.o

pr1.o: Command.h Deque.h Functions.h 

Command.o: Command.h

Deque.o: Deque.h

Functions.o: Functions.h

.PHONY: clean

clean:
	$(info -- cleaning --)
	rm -f *.o
	rm -f pr2
