```

Wed Dec 16 04:11:23 EST 2020


chmod +rwx .
wget -q -P ./data/ https://github.com/guyfrancoeur/INF3135_A2020/raw/master/tp/tp3.zip || wget -q -P ./data/ https://github.com/guyfrancoeur/INF3135_A2020/raw/master/tp/tp2.zip || wget -q -P ./data/ https://github.com/guyfrancoeur/INF3135_A2020/raw/master/tp/tp1.zip
unzip -qqo ./data/tp3.zip -d . || unzip -qqo ./data/tp2.zip -d . || unzip -qqo ./data/tp1.zip -d .
gcc -c -Wall -Werror=vla -pedantic -std=c11 malib.c -lm
gcc -c -Wall -Werror=vla -pedantic -std=c11 outil3.c -lm
gcc -Wall -Werror=vla -pedantic -std=c11 -o tp3 tp3.c malib.o outil3.o tcv.o -lm

```
