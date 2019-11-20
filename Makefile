CC = gcc
FLAGS = -Wall -g

# $@ - the file on the left side of the :
# $< - the first name in the dependencies list
# $^ - the right side of :

all: main.out 
main.out: main.o myBank.o
	$(CC) $(FLAGS) -o main.out $^ -I.
main.o: main.c myBank.h
	$(CC) $(FLAGS) -c -o $@ $< -I.
myBank.o: myBank.c
	$(CC) $(FLAGS) -fPIC -c -o $@ $< -I.
	
.PHONY: clean all
	
clean:
	rm -f *.o *.out
