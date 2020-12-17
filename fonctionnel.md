![test-f](https://github.com/Nami-R2301/inf3135-a2020/workflows/test-f/badge.svg?branch=tp3)

## Tests fonctionnels pour le TP3 à jour: 

```

Thu Dec 17 00:54:53 EST 2020

******Tests sans arguments******

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

******Tests avec arguments******

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
  trx 05 : 5
  le dernier ts lu : 41
information sommaire
  nbr trx valides : 21
  nbr trx (total) : 35

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
  trx 05 : 5
  le dernier ts lu : 41
information sommaire
  nbr trx valides : 21
  nbr trx (total) : 35

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

******Tests avec STDIN vide******

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

******Tests avec valgrind******


$ cat .github/workflows/Fichier-tests-f.txt | valgrind ./tp3 -i -s -d

==6038== Memcheck, a memory error detector
==6038== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==6038== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==6038== Command: ./tp3 -i -s -d
==6038== 
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
  trx 05 : 5
  le dernier ts lu : 41
information sommaire
  nbr trx valides : 21
  nbr trx (total) : 35
==6038== 
==6038== HEAP SUMMARY:
==6038==     in use at exit: 0 bytes in 0 blocks
==6038==   total heap usage: 13 allocs, 13 frees, 8,648 bytes allocated
==6038== 
==6038== All heap blocks were freed -- no leaks are possible
==6038== 
==6038== For counts of detected and suppressed errors, rerun with: -v
==6038== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

$ ./tp3 -t -i -dd -sfg -sffgg

==6040== Memcheck, a memory error detector
==6040== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==6040== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==6040== Command: ./tp3 -t -i -dd -sfg -sffgg
==6040== 
Version #: 0.1.1008
==6040== 
==6040== HEAP SUMMARY:
==6040==     in use at exit: 0 bytes in 0 blocks
==6040==   total heap usage: 13 allocs, 13 frees, 8,648 bytes allocated
==6040== 
==6040== All heap blocks were freed -- no leaks are possible
==6040== 
==6040== For counts of detected and suppressed errors, rerun with: -v
==6040== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```
