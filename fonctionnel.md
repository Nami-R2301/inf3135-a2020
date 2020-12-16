![test-f](https://github.com/Nami-R2301/inf3135-a2020/workflows/test-f/badge.svg?branch=tp3)

## Tests fonctionnels pour le TP3 à jour: 

```

Wed Dec 16 17:24:15 EST 2020

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
  trx avec ts non sequentiel : 6
information detaillee
  trx 00 : 1
  trx 01 : 5
  trx 02 : 3
  trx 03 : 7
  trx 04 : 5
  trx 05 : 2
  le dernier ts lu : 37
information sommaire
  nbr trx valides : 11
  nbr trx (total) : 31

$ Fichier-tests-f.txt | ./tp3 -t -s -d -i

Version #: 0.1.1008
information invalide
  trx non reconnue : 2
  trx avec ts non sequentiel : 6
information detaillee
  trx 00 : 1
  trx 01 : 5
  trx 02 : 3
  trx 03 : 7
  trx 04 : 5
  trx 05 : 2
  le dernier ts lu : 37
information sommaire
  nbr trx valides : 11
  nbr trx (total) : 31

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

```
