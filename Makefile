PROG = tp1
CC = -Wall -Werror=vla -pedantic -std=c11
MATCH = -lm

DEFAULT:
	gcc $(CC) $(PROG).c -o $(PROG).o -lm
	gcc $(PROG).c -o $(PROG) -lm

lib:
	wget -q -P ./data https://github.com/guyfrancoeur/INF3135_A2020/raw/master/tp/tp1.zip
	unzip -o ./data/tp1.zip -d ./data/
	rm -f ./data/tp1.zip

test:
	./tp1

clean:
	rm -f *.o
	rm -f *.h
	rm -f tp1
	rm -fdr ./data

.PHONY: clean DEFAULT lib test 
