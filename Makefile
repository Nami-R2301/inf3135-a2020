PROG1 = tp1
PROG2 = tp2
CC = -Wall -Werror=vla -pedantic -std=c11
MATH = -lm
CUNIT = -I/usr/include/CUnit -L/usr/lib/x86_64-linux-gnu


default: $(PROG2).c
	chmod +rwx .
	wget -q -P ./data/ https://github.com/guyfrancoeur/INF3135_A2020/raw/master/tp/tp1.zip
	unzip -qqo ./data/tp1.zip -d .
	gcc $(CC) tp2.c -o tp2 $(MATH)

tp1:
	chmod +rwx .
	wget -q -P ./data/ https://github.com/guyfrancoeur/INF3135_A2020/raw/master/tp/tp1.zip
	unzip -qqo ./data/tp1.zip -d .
	gcc $(CC) $(CUNIT) -o $(PROG1) $(PROG1).c tcv.o -lcunit

lib:
	chmod +rwx .
	wget -q -P ./data/ https://github.com/guyfrancoeur/INF3135_A2020/raw/master/tp/tp1.zip
	unzip -qqo ./data/tp1.zip -d . 

test-tp1a:
	chmod +rwx .
	wget -q -P ./data/ https://github.com/guyfrancoeur/INF3135_A2020/raw/master/tp/tp1.zip
	unzip -qqo ./data/tp1.zip -d .
	gcc $(CC) $(CUNIT) -o $(PROG1) $(PROG1).c tcv.o -lcunit
	./tp1

test-tp1b:
	chmod +rwx .
	wget -q -P ./data/ https://github.com/guyfrancoeur/INF3135_A2020/raw/master/tp/tp1.zip
	unzip -qqo ./data/tp1.zip -d .
	gcc $(CC) $(CUNIT) -o $(PROG1) $(PROG1).c tcv.o -lcunit
	./tp1 | bash liste.sh


test-tp2:
	chmod +rwx .
	wget -q -P ./data/ https://github.com/guyfrancoeur/INF3135_A2020/raw/master/tp/tp1.zip
	unzip -qqo ./data/tp1.zip -d .
	gcc $(CC) -o tp2 tp2.c malib.c $(MATH)
	./tp2

clean:
	chmod +rwx .
	rm -f *.o; rm -f tcv.h; rm -f ./tp1; rm -fdr ./data

.PHONY: default tp1 lib test-tp1a test-tp1b test-tp2 clean 
