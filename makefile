CC = g++
CFLAGS = -g -Wall -Wextra

default: deque

deque:  main.o
	$(CC) $(CFLAGS) -o deque main.o

main.o: main.cpp deque.h
	$(CC) $(CFLAGS) -c main.cpp

clean:
	$(RM) *.o *~ deque
