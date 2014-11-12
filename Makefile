CC = gcc
CFLAGS = -c -g -Wall -Wextra
LFLAGS = -Wall -Wextra

.PHONY: all clean

all: clientInterestProject

clientInterestProject: clientInterestProject.o
	$(CC) $(LFLAGS) $^ -o $@ -lm

clientInterestProject.o: clientInterestProject.c clientInterestProject.h
	$(CC) $(CFLAGS) $< 

clean:
	rm -f clientInterstProject.o

