# Réflexion lors de l'accomplissement du tp2

---------------------------------------------
## Fonctionnement du fichier tp2.c :

- *Coder dans un fichier tp2.c la fonction main du tp2.*

- *Entrées de tp2.c : Stdin.* 

- *Sortie de tp2.c : Stdout.*
----------------------------------------------

## Contrainte(s) :

- Utiliser tcv.h et tcv.o fournit dans tp1.zip.

- Branche nommé tp2 (contient le projet).

-----------------------------------------------
### Compréhension après deuxième lecture :

- Les formats des données en entrées seront respecté (*Les transactions sont très formelles. Il s'agit d'un système dit critique, aucune nuance possible.
  Ceci ne veut pas dire que les transactions ou le système est exempt d'erreurs.*), donc on ne doit pas ce soucier des formats d'entrées (espaces superflues,
  manquement d'un ou plusieurs arguments, argument(s) de trop, etc...).

- Incrémentation d'un compteur d'erreur par type de donnée d'entrée invalide.

- Trois incrémentation du même type incrémentera un autre compteur (transaction 22) du même type pour signifier une erreur majeur.

- Seulement *TH* et *TA* peuvent contenir des *ERREUR* comme argument en entrée.

- L'ordre des transaction est importante. Cepandant, nous pouvons avoir une température ambiante sans nécéssairement avoir une température humaine.
  les évenements doivent être en ordre croissant, mais il peut en avoir d'absent.

- Température ambiante et humaine contiennent la même signature.

- En lisant les échanges de données (transaction 15), je croix comprendre que nous comparons l'id du signal RSSI (événement 04) et les ids du premier niveau.

- On réaffiche les *timestamp* en entrée dans les transactions de sorties.

- Seulement une transaction de sortie pour 21, 22 et 23 vers la fin du programme (après avoir traité toutes les données.

- On va probablement utiliser *math.h* pour calculer la distance, car je ne croix pas qu'on peut implementer des exposants d'une manière courte en C.

------------------------------------------------

### Créer par Nami Reghbati 05/11/2020 : 13:00
