![test-c](https://github.com/Nami-R2301/inf3135-a2020/workflows/test-c/badge.svg?branch=tp3)

## Tests de compilation pour le TP3 à jour:

```

Wed Dec 16 22:21:45 EST 2020


chmod +rwx .
wget -q -P ./data/ https://github.com/guyfrancoeur/INF3135_A2020/raw/master/tp/tp3.zip || wget -q -P ./data/ https://github.com/guyfrancoeur/INF3135_A2020/raw/master/tp/tp2.zip || wget -q -P ./data/ https://github.com/guyfrancoeur/INF3135_A2020/raw/master/tp/tp1.zip
unzip -qqo ./data/tp3.zip -d . || unzip -qqo ./data/tp2.zip -d . || unzip -qqo ./data/tp1.zip -d .
gcc -c -Wall -Werror=vla -pedantic -std=c11 malib.c -lm
gcc -c -Wall -Werror=vla -pedantic -std=c11 outil3.c -lm
gcc -Wall -Werror=vla -pedantic -std=c11 -o tp3 tp3.c malib.o outil3.o tcv.o -lm

```
