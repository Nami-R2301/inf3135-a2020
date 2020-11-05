PROG = tp1
CC = -Wall -Werror=vla -pedantic -std=c11
MATH = -lm
CUNIT = -I/usr/include/CUnit -L/usr/lib/x86_64-linux-gnu

DEFAULT:
	chmod +rwx .
	wget -q -P ./data https://github.com/guyfrancoeur/INF3135_A2020/raw/master/tp/tp1.zip
	unzip -qqo ./data/tp1.zip -d .
	gcc $(CC) $(CUNIT) -o $(PROG) $(PROG).c tcv.o -lcunit

lib:
	chmod +rwx .
	wget -q -P ./data https://github.com/guyfrancoeur/INF3135_A2020/raw/master/tp/tp1.zip
	unzip -qqo ./data/tp1.zip -d . 

test:
	wget -q -P ./data https://github.com/guyfrancoeur/INF3135_A2020/raw/master/tp/tp1.zip
	unzip -qqo ./data/tp1.zip -d .
	gcc $(CC) $(CUNIT) -o $(PROG) $(PROG).c tcv.o -lcunit
	./tp1

liste:
	chmod +rwx .
	wget -q -P ./data https://github.com/guyfrancoeur/INF3135_A2020/raw/master/tp/tp1.zip
	unzip -qqo ./data/tp1.zip -d .
	gcc $(CC) $(CUNIT) -o $(PROG) $(PROG).c tcv.o -lcunit
	echo "#!/bin/bash\n#Programme qui lie la sortie standard et l'interprete comme une entree standard en affichant seulement les tests qui ont passes.\n\nSTDIN=\$$(grep -e "FAILED" -)\n\necho \"\n\n\n\$$STDIN\n\n\n\"" > listeFailed.sh
	echo "\nSTDINP=\$$(grep -e "passed" -)\n\necho \"\n\n\n\$$STDINP\n\n\n\"" > listePassed.sh
	./tp1 | bash listePassed.sh
	./tp1 | bash listeFailed.sh

clean:
	chmod +rwx .
	rm -f *.o; rm -f *.h; rm -f tp1; rm -fdr ./data; rm -f liste.sh

.PHONY: clean DEFAULT lib test liste 
