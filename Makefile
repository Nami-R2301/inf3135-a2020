PROG1 = tp1
PROG2 = tp2
CC = -Wall -Werror=vla -pedantic -std=c11
MATH = -lm
CUNIT = -I/usr/include/CUnit -L/usr/lib/x86_64-linux-gnu


default: $(PROG2).c
	chmod +rwx ~/inf3135-a2020/
	wget -q -P ~/inf3135-a2020/data/ https://github.com/guyfrancoeur/INF3135_A2020/raw/master/tp/tp2.zip
	unzip -qqo ~/inf3135-a2020/data/tp1.zip -d ~/inf3135-a2020/
	echo "Allo"
	gcc $(CC) tp2.c -o tp2

tp1:
	chmod +rwx ~/inf3135-a2020/
	wget -q -P ~/inf3135-a2020/data/ https://github.com/guyfrancoeur/INF3135_A2020/raw/master/tp/tp1.zip
	unzip -qqo ~/inf3135-a2020/data/tp1.zip -d ~/inf3135-a2020/
	gcc $(CC) $(CUNIT) -o $(PROG) $(PROG).c tcv.o -lcunit

lib:
	chmod +rwx ~/inf3135-a2020/
	wget -q -P ~/inf3135-a2020/data/ https://github.com/guyfrancoeur/INF3135_A2020/raw/master/tp/tp2.zip
	unzip -qqo ~/inf3135-a2020/data/tp1.zip -d ~/inf3135-a2020/ 

test-tp1a:
	chmod +rwx ~/inf3135-a2020/
	wget -q -P ~/inf3135-a2020/data/ https://github.com/guyfrancoeur/INF3135_A2020/raw/master/tp/tp1.zip
	unzip -qqo ./data/tp1.zip -d ~/inf3135-a2020/
	gcc $(CC) $(CUNIT) -o $(PROG) $(PROG).c tcv.o -lcunit
	bash ~/inf3135-a2020/tp1

test-tp1b:
	chmod +rwx ~/inf3135-a2020/
	wget -q -P ~/inf3135-a2020/data/ https://github.com/guyfrancoeur/INF3135_A2020/raw/master/tp/tp1.zip
	unzip -qqo ~/inf3135-a2020/data/tp1.zip -d ~/inf3135-a2020/
	gcc $(CC) $(CUNIT) -o $(PROG) $(PROG).c tcv.o -lcunit
	echo "#!/bin/bash\n#Programme qui lie la sortie standard et l'interprete comme une entree standard en affichant seulement les tests qui ont passes.\n\nSTDINP=\$$(grep -e "passed" -)\n\necho \"\n\n\n\$$STDINP\n\n\n\"" > liste.sh
	~/inf3135-a2020/tp1 | bash  ~/inf3135-a2020/liste.sh


test-tp2:
	bash  ~/inf3135-a2020/tp2

clean:
	chmod +rwx ~/inf3135-a2020/
	rm -f  ~/inf3135-a2020/*.o; rm -f  ~/inf3135-a2020/*.h; rm -f  ~/inf3135-a2020/tp1; rm -fdr  ~/inf3135-a2020/data; rm -f  ~/inf3135-a2020/liste.sh
	rm -fr malib.*; rm -fr *.yml

.PHONY: default tp1 lib test-tp1a test-tp1b test-tp2 clean 
