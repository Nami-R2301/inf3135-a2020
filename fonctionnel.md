![test-f](https://github.com/Nami-R2301/inf3135-a2020/workflows/test-f/badge.svg?branch=tp3)

## Tests fonctionnels pour le TP3 à jour: 

```

Thu Dec 17 00:18:39 EST 2020

******Tests sans arguments******

$ Fichier-tests-f.txt | ./tp3

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

$ Fichier-tests-f.txt | ./tp3 -i -s -d

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

$ Fichier-tests-f.txt | ./tp3 -t -s -d -i

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

$ Fichier-tests-f.txt | ./tp3 --t --s --b --d

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

$ Fichier-tests-f.txt | ./tp3 -t

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

==6063== Memcheck, a memory error detector
==6063== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==6063== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==6063== Command: ./tp3 -i -s -d
==6063== Parent PID: 6047
==6063== 
==6063== 
==6063== HEAP SUMMARY:
==6063==     in use at exit: 0 bytes in 0 blocks
==6063==   total heap usage: 13 allocs, 13 frees, 8,648 bytes allocated
==6063== 
==6063== All heap blocks were freed -- no leaks are possible
==6063== 
==6063== For counts of detected and suppressed errors, rerun with: -v
==6063== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)


==6065== Memcheck, a memory error detector
==6065== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==6065== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==6065== Command: ./tp3 -t -s -i -d
==6065== Parent PID: 6047
==6065== 
==6065== 
==6065== HEAP SUMMARY:
==6065==     in use at exit: 0 bytes in 0 blocks
==6065==   total heap usage: 13 allocs, 13 frees, 8,648 bytes allocated
==6065== 
==6065== All heap blocks were freed -- no leaks are possible
==6065== 
==6065== For counts of detected and suppressed errors, rerun with: -v
==6065== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```
