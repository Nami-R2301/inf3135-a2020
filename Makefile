PROG = tp3
CC = -Wall -Werror=vla -pedantic -std=c11
MATH = -lm
CUNIT = -I/usr/include/CUnit -L/usr/lib/x86_64-linux-gnu


default: $(PROG).c
	chmod +rwx .
	wget -q -P ./data/ https://github.com/guyfrancoeur/INF3135_A2020/raw/master/tp/tp3.zip || wget -q -P ./data/ https://github.com/guyfrancoeur/INF3135_A2020/raw/master/tp/tp2.zip || wget -q -P ./data/ https://github.com/guyfrancoeur/INF3135_A2020/raw/master/tp/tp1.zip
	unzip -qqo ./data/tp3.zip -d . || unzip -qqo ./data/tp2.zip -d . || unzip -qqo ./data/tp1.zip -d .
	gcc -c $(CC) malib.c $(MATH)
	gcc -c $(CC) outil3.c $(MATH)
	gcc $(CC) -o $(PROG) $(PROG).c malib.o outil3.o tcv.o $(MATH)

lib:
	chmod +rwx .
	wget -q -P ./data/ https://github.com/guyfrancoeur/INF3135_A2020/raw/master/tp/tp3.zip || wget -q -P ./data/ https://github.com/guyfrancoeur/INF3135_A2020/raw/master/tp/tp2.zip || wget -q -P ./data/ https://github.com/guyfrancoeur/INF3135_A2020/raw/master/tp/tp1.zip
	unzip -qqo ./data/tp3.zip -d . || unzip -qqo ./data/tp2.zip -d . || unzip -qqo ./data/tp1.zip -d .

tp3:
	chmod +rwx .
	wget -q -P ./data/ https://github.com/guyfrancoeur/INF3135_A2020/raw/master/tp/tp3.zip || wget -q -P ./data/ https://github.com/guyfrancoeur/INF3135_A2020/raw/master/tp/tp2.zip || wget -q -P ./data/ https://github.com/guyfrancoeur/INF3135_A2020/raw/master/tp/tp1.zip
	unzip -qqo ./data/tp3.zip -d . || unzip -qqo ./data/tp2.zip -d . || unzip -qqo ./data/tp1.zip -d .
	gcc -c malib.c $(CC) $(MATH)
	gcc -c $(CC) outil3.c $(MATH)
	gcc $(CC) -o $(PROG) $(PROG).c malib.o outil3.o tcv.o $(MATH)

clean:
	chmod +rwx .
	rm -f *.o; rm -f tcv.h; rm -f ./$(PROG); rm -fdr ./data;

.PHONY: default tp1 lib test-tp1a test-tp1b test-tp2 clean
