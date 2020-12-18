![test-f](https://github.com/Nami-R2301/inf3135-a2020/workflows/test-f/badge.svg?branch=tp3)



## Tests fonctionnels pour le TP3 à jour (Thu Dec 17 22:26:04 EST 2020): 



### Contenu de/des Fichier(s) testé(s) :

```

$ cat .github/workflows/Fichier-tests-f.txt

10 00 0 0
10 10 9999 2
12 01 20.6
13 01 ERREUR
13 01 ERREUR
13 01 ERREUR
14 01 ERREUR
15 01 ERREUR
16 01 36.9
16 01 0.0
17 02 ERREUR
17 02 ERREUR
17 02 ERREUR
20 02 0.0
21 02 -58.77
22 03 157
23 03 ERREUR
24 03 ERREUR
25 03 ERREUR
26 03 ERREUR
27 03 ERREUR
28 03 49
29 04 -40 9999
30 04 -35 20000
31 04 -45 10000
32 04 0 40000
33 04 -60.6 100000
34 05 11111 1000 2000 3000 4000 5000 6000 7000 8000
35 05 0 1111 1111 1111 1111
36 05 60000 1111 11111 11111
37 05 9999
38 06 00
39 07 11111 1111
40 08 -1234
41 05 111111
42 05 -1


```


### Tests sans arguments :

```

$ cat .github/workflows/Fichier-tests-f.txt | ./tp3

Version #: 0.1.1008
10 10 9999 2
14 30 20000 0.0
14 31 10000 0.1
14 33 100000 0.4
15 34 9999 20000 10000 100000 
15 35 9999 20000 10000 100000 
15 36 9999 20000 10000 100000 
15 37 9999 20000 10000 100000 
21 28.8 0.0 157
22 0 1 1
23 1 0 1

```


### Tests avec arguments :


```

$ cat .github/workflows/Fichier-tests-f.txt | ./tp3 -i -s -d

Version #: 0.1.1008
10 10 9999 2
14 30 20000 0.0
14 31 10000 0.1
14 33 100000 0.4
15 34 9999 20000 10000 100000 
15 35 9999 20000 10000 100000 
15 36 9999 20000 10000 100000 
15 37 9999 20000 10000 100000 
21 28.8 0.0 157
22 0 1 1
23 1 0 1
information invalide
  trx non reconnue : 3
  trx avec ts non sequentiel : 6
information detaillee
  trx 00 : 1
  trx 01 : 5
  trx 02 : 3
  trx 03 : 7
  trx 04 : 5
  trx 05 : 6
  le dernier ts lu : 42
information sommaire
  nbr trx valides : 21
  nbr trx (total) : 36

$ cat .github/workflows/Fichier-tests-f.txt | ./tp3 -t -s -d -i

Version #: 0.1.1008
information invalide
  trx non reconnue : 3
  trx avec ts non sequentiel : 6
information detaillee
  trx 00 : 1
  trx 01 : 5
  trx 02 : 3
  trx 03 : 7
  trx 04 : 5
  trx 05 : 6
  le dernier ts lu : 42
information sommaire
  nbr trx valides : 21
  nbr trx (total) : 36

$ cat .github/workflows/Fichier-tests-f.txt | ./tp3 --t --s --b --d

Version #: 0.1.1008
10 10 9999 2
14 30 20000 0.0
14 31 10000 0.1
14 33 100000 0.4
15 34 9999 20000 10000 100000 
15 35 9999 20000 10000 100000 
15 36 9999 20000 10000 100000 
15 37 9999 20000 10000 100000 
21 28.8 0.0 157
22 0 1 1
23 1 0 1

$ cat .github/workflows/Fichier-tests-f.txt | ./tp3 -t

Version #: 0.1.1008

```


### Tests avec STDIN vide :


```

$ ./tp3 -t

Version #: 0.1.1008

$ ./tp3 -i -s -d

Version #: 0.1.1008
21 0.0 0.0 0
22 0 0 0
23 0 0 0
information detaillee
  trx 00 : 0
  trx 01 : 0
  trx 02 : 0
  trx 03 : 0
  trx 04 : 0
  trx 05 : 0
  le dernier ts lu : 0
information sommaire
  nbr trx valides : 0
  nbr trx (total) : 0

$ ./tp3

Version #: 0.1.1008
21 0.0 0.0 0
22 0 0 0
23 0 0 0

```


### Tests avec valgrind


```


$ cat .github/workflows/Fichier-tests-f.txt | valgrind ./tp3 -i -s -d

==6046== Memcheck, a memory error detector
==6046== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==6046== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==6046== Command: ./tp3 -i -s -d
==6046== 
Version #: 0.1.1008
10 10 9999 2
14 30 20000 0.0
14 31 10000 0.1
14 33 100000 0.4
15 34 9999 20000 10000 100000 
15 35 9999 20000 10000 100000 
15 36 9999 20000 10000 100000 
15 37 9999 20000 10000 100000 
21 28.8 0.0 157
22 0 1 1
23 1 0 1
information invalide
  trx non reconnue : 3
  trx avec ts non sequentiel : 6
information detaillee
  trx 00 : 1
  trx 01 : 5
  trx 02 : 3
  trx 03 : 7
  trx 04 : 5
  trx 05 : 6
  le dernier ts lu : 42
information sommaire
  nbr trx valides : 21
  nbr trx (total) : 36
==6046== 
==6046== HEAP SUMMARY:
==6046==     in use at exit: 0 bytes in 0 blocks
==6046==   total heap usage: 13 allocs, 13 frees, 8,648 bytes allocated
==6046== 
==6046== All heap blocks were freed -- no leaks are possible
==6046== 
==6046== For counts of detected and suppressed errors, rerun with: -v
==6046== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

$ ./tp3 -t -i -dd -sfg -sffgg

==6047== Memcheck, a memory error detector
==6047== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==6047== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==6047== Command: ./tp3 -t -i -dd -sfg -sffgg
==6047== 
Version #: 0.1.1008
==6047== 
==6047== HEAP SUMMARY:
==6047==     in use at exit: 0 bytes in 0 blocks
==6047==   total heap usage: 13 allocs, 13 frees, 8,648 bytes allocated
==6047== 
==6047== All heap blocks were freed -- no leaks are possible
==6047== 
==6047== For counts of detected and suppressed errors, rerun with: -v
==6047== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```
