PROG = hello
CC = -Wall -std=c11
DGB = hello-dbg.o
MATCH = -lm

DEFAULT:
	gcc $(CC) $(PROG).c -o $(PROG).o -lm
	gcc $(CC) -g  $(PROG).c -o $(DGB) -lm
	gcc $(PROG).c -o $(PROG) -lm
clean:
	rm -f .o*
	rm -f ./*.o

.PHONY: clean DEFAULT  
