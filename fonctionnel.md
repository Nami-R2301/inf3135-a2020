![test-f](https://github.com/Nami-R2301/inf3135-a2020/workflows/test-f/badge.svg?branch=tp3)

## Tests fonctionnels pour le TP3 à jour: 

```

Wed Dec 16 23:54:53 EST 2020

******Tests sans arguments******

$ Fichier-tests-f.txt | ./tp3

Version #: 0.1.1008
10 10 9999 2
14 30 20000 0.0
14 31 30000 0.1
14 32 40000 0.0
14 33 50000 0.4
15 34 9999 20000 30000 40000 50000 
15 35 9999 20000 30000 40000 50000 
21 28.8 0.0 157
22 0 1 1
23 1 0 1

******Tests avec arguments******

$ Fichier-tests-f.txt | ./tp3 -i -s -d

Version #: 0.1.1008
10 10 9999 2
14 30 20000 0.0
14 31 30000 0.1
14 32 40000 0.0
14 33 50000 0.4
15 34 9999 20000 30000 40000 50000 
15 35 9999 20000 30000 40000 50000 
21 28.8 0.0 157
22 0 1 1
23 1 0 1
information invalide
  trx non reconnue : 2
  trx avec ts non sequentiel : 7
information detaillee
  trx 00 : 1
  trx 01 : 5
  trx 02 : 3
  trx 03 : 7
  trx 04 : 5
  trx 05 : 3
  le dernier ts lu : 38
information sommaire
  nbr trx valides : 11
  nbr trx (total) : 33

$ Fichier-tests-f.txt | ./tp3 -t -s -d -i

Version #: 0.1.1008
information invalide
  trx non reconnue : 2
  trx avec ts non sequentiel : 7
information detaillee
  trx 00 : 1
  trx 01 : 5
  trx 02 : 3
  trx 03 : 7
  trx 04 : 5
  trx 05 : 3
  le dernier ts lu : 38
information sommaire
  nbr trx valides : 11
  nbr trx (total) : 33

$ Fichier-tests-f.txt | ./tp3 --t --s --b --d

Version #: 0.1.1008
10 10 9999 2
14 30 20000 0.0
14 31 30000 0.1
14 32 40000 0.0
14 33 50000 0.4
15 34 9999 20000 30000 40000 50000 
15 35 9999 20000 30000 40000 50000 
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

==5878== Memcheck, a memory error detector
==5878== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==5878== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==5878== Command: ./tp3 -i -s -d
==5878== Parent PID: 5862
==5878== 
==5878== 
==5878== HEAP SUMMARY:
==5878==     in use at exit: 0 bytes in 0 blocks
==5878==   total heap usage: 13 allocs, 13 frees, 8,648 bytes allocated
==5878== 
==5878== All heap blocks were freed -- no leaks are possible
==5878== 
==5878== For counts of detected and suppressed errors, rerun with: -v
==5878== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)


==5880== Memcheck, a memory error detector
==5880== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==5880== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==5880== Command: ./tp3 -t -s -i -d
==5880== Parent PID: 5862
==5880== 
==5880== Use of uninitialised value of size 8
==5880==    at 0x523496B: _itoa_word (_itoa.c:179)
==5880==    by 0x523800D: vfprintf (vfprintf.c:1642)
==5880==    by 0x5241015: printf (printf.c:33)
==5880==    by 0x109F10: printOptions (in /home/runner/work/inf3135-a2020/inf3135-a2020/tp3)
==5880==    by 0x108D10: main (in /home/runner/work/inf3135-a2020/inf3135-a2020/tp3)
==5880== 
==5880== Conditional jump or move depends on uninitialised value(s)
==5880==    at 0x5234975: _itoa_word (_itoa.c:179)
==5880==    by 0x523800D: vfprintf (vfprintf.c:1642)
==5880==    by 0x5241015: printf (printf.c:33)
==5880==    by 0x109F10: printOptions (in /home/runner/work/inf3135-a2020/inf3135-a2020/tp3)
==5880==    by 0x108D10: main (in /home/runner/work/inf3135-a2020/inf3135-a2020/tp3)
==5880== 
==5880== Conditional jump or move depends on uninitialised value(s)
==5880==    at 0x5238114: vfprintf (vfprintf.c:1642)
==5880==    by 0x5241015: printf (printf.c:33)
==5880==    by 0x109F10: printOptions (in /home/runner/work/inf3135-a2020/inf3135-a2020/tp3)
==5880==    by 0x108D10: main (in /home/runner/work/inf3135-a2020/inf3135-a2020/tp3)
==5880== 
==5880== Conditional jump or move depends on uninitialised value(s)
==5880==    at 0x5238C4C: vfprintf (vfprintf.c:1642)
==5880==    by 0x5241015: printf (printf.c:33)
==5880==    by 0x109F10: printOptions (in /home/runner/work/inf3135-a2020/inf3135-a2020/tp3)
==5880==    by 0x108D10: main (in /home/runner/work/inf3135-a2020/inf3135-a2020/tp3)
==5880== 
==5880== 
==5880== HEAP SUMMARY:
==5880==     in use at exit: 0 bytes in 0 blocks
==5880==   total heap usage: 13 allocs, 13 frees, 8,648 bytes allocated
==5880== 
==5880== All heap blocks were freed -- no leaks are possible
==5880== 
==5880== For counts of detected and suppressed errors, rerun with: -v
==5880== Use --track-origins=yes to see where uninitialised values come from
==5880== ERROR SUMMARY: 4 errors from 4 contexts (suppressed: 0 from 0)

```
