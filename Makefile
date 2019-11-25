CC = gcc
AR = ar
FLAGS = -Wall -g

# $@ - the file on the left side of the :
# $< - the first name in the dependencies list
# $^ - the right side of :

all: main.out libmyBank.a
libmyBank.a: myBank.o
	$(AR) -rcs libmyBank.a $^ 
main.out: main.o libmyBank.a
	$(CC) $(FLAGS) -o main.out $^ -I.
main.o: main.c myBank.h
	$(CC) $(FLAGS) -c -o $@ $< -I.
myBank.o: myBank.c
	$(CC) $(FLAGS) -fPIC -c -o $@ $< -I.
	
.PHONY: clean all
	
clean:
	rm -f *.o *.out *.a
