![test-f](https://github.com/Nami-R2301/inf3135-a2020/workflows/test-f/badge.svg?branch=tp3)

## Tests fonctionnels pour le TP3 à jour: 

```

Thu Dec 17 00:37:45 EST 2020

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
  trx 05 : 4
  le dernier ts lu : 40
information sommaire
  nbr trx valides : 12
  nbr trx (total) : 34

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
  trx 05 : 4
  le dernier ts lu : 40
information sommaire
  nbr trx valides : 12
  nbr trx (total) : 34

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

==6028== Memcheck, a memory error detector
==6028== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==6028== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==6028== Command: ./tp3 -i -s -d
==6028== 
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
  trx 05 : 4
  le dernier ts lu : 40
information sommaire
  nbr trx valides : 12
  nbr trx (total) : 34
==6028== 
==6028== HEAP SUMMARY:
==6028==     in use at exit: 0 bytes in 0 blocks
==6028==   total heap usage: 13 allocs, 13 frees, 8,648 bytes allocated
==6028== 
==6028== All heap blocks were freed -- no leaks are possible
==6028== 
==6028== For counts of detected and suppressed errors, rerun with: -v
==6028== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

$ ./tp3 -t -i -dd -sfg -sffgg

==6029== Memcheck, a memory error detector
==6029== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==6029== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==6029== Command: ./tp3 -t -i -dd -sfg -sffgg
==6029== 
Version #: 0.1.1008
==6029== 
==6029== HEAP SUMMARY:
==6029==     in use at exit: 0 bytes in 0 blocks
==6029==   total heap usage: 13 allocs, 13 frees, 8,648 bytes allocated
==6029== 
==6029== All heap blocks were freed -- no leaks are possible
==6029== 
==6029== For counts of detected and suppressed errors, rerun with: -v
==6029== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```
