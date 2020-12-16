```chmod +rwx .
wget -q -P ./data/ https://github.com/guyfrancoeur/INF3135_A2020/raw/master/tp/tp3.zip || wget -q -P ./data/ https://github.com/guyfrancoeur/INF3135_A2020/raw/master/tp/tp2.zip || wget -q -P ./data/ https://github.com/guyfrancoeur/INF3135_A2020/raw/master/tp/tp1.zip
unzip -qqo ./data/tp3.zip -d . || unzip -qqo ./data/tp2.zip -d . || unzip -qqo ./data/tp1.zip -d .
unzip:  cannot find or open ./data/tp3.zip, ./data/tp3.zip.zip or ./data/tp3.zip.ZIP.
gcc -c -Wall -Werror=vla -pedantic -std=c11 malib.c -lm
gcc -c -Wall -Werror=vla -pedantic -std=c11 outil3.c -lm
gcc -Wall -Werror=vla -pedantic -std=c11 -o tp3 tp3.c malib.o outil3.o tcv.o -lm
```
