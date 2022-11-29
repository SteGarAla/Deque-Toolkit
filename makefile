CC = g++
CFLAGS = -g -Wall -Wextra

default: deque

deque: deque.h main.o
	$(CC) $(CFLAGS) -o deque deque.h main.o

main.o: main.cpp deque.h
	$(CC) $(CFLAGS) -c main.cpp

clean:
	$(RM) *.o *~ deque
