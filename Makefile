PROG = tp1
CC = -Wall -Werror=vla -pedantic -std=c11
MATH = -lm
CUNIT = -I/usr/include/CUnit -L/usr/lib/x86_64-linux-gnu

DEFAULT:
	gcc $(CC) $(CUNIT) -o $(PROG) $(PROG).c tcv.o -lcunit

lib:
	chmod +rwx .
	wget -q -P ./data https://github.com/guyfrancoeur/INF3135_A2020/raw/master/tp/tp1.zip
	unzip -o ./data/tp1.zip -d . 

test:
	gcc $(CC) $(CUNIT) -o $(PROG) $(PROG).c tcv.o -lcunit
	./tp1

liste:
	gcc $(CC) $(CUNIT) -o $(PROG) $(PROG).c tcv.o -lcunit
	bash liste.sh tp1.sh

clean:
	rm -f *.o
	rm -f *.h
	rm -f tp1
	rm -fdr ./data
	ls -lash

.PHONY: clean DEFAULT lib test liste 
