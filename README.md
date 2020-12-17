 ![test-f](https://github.com/Nami-R2301/inf3135-a2020/workflows/test-f/badge.svg?branch=tp3)
 
 ![test-c](https://github.com/Nami-R2301/inf3135-a2020/workflows/test-c/badge.svg?branch=tp3)
 
 # Travail pratique 3

 ## Rendu à 460 commits!
 
 ## Description
 
  - Vous devez dans ce travail apporter des modifications au code existant. Vous ajouterez une fonction de gestion des arguments (options) de la ligne de commande.  Vous 
    devez créer un programme juste et robuste.  Des fichiers ## Auteur (modules) seront utilisés pour garder un code propre et lisible.  L'utilisation de toutes les 
    notions vue cette année est souhaitable. Finalement, le langage dans les mains d'un programmeur tel que vous peut produire, doit - Réalisé par Nami Reghbati; 
    REGN03079808. produire, un exécutable performant.  Votre exécutable sera soumis à un stress incroyable.

 ## Fonctionnement

   - Ce que vous devez faire : - Le programme exécutable peut être lancé en ligne de commande avec différentes syntaxes :
   - Compter, maintenir et afficher le nombre transactions selon les options demandées au lancement du logiciel.
   
   ```bash

   # sans option
 
   $ ./tp3 
   $ cat file.dat | ./tp3
   $ head -n 100 file.txt | tail -n 25 | ./tp3

   # avec option(s) de la ligne de commande (-d détaillé, -s sommaire, -t tranquille -i invalide)
    $ ./tp3 -s -d -i
    $ ./tp3 -s
    $ ./tp3 -t

    ...

   ``` 
   - Le rôle de votre programme est de lire des transactions (déjà fait durant le tp2). Le tp3 ajoute une fonctionnalité 
     qui compte de nombre de lignes lues et selon le cas affichera les informations recueillies. Les options suivantes doivent être gérées :

   Voici les cas et les traitements en fonction des options :   

   - option -i information invalide
     + Lorsqu'un code de transaction n'est reconnu;
     + Lorsque le timestamp est inférieur au temps précédent;

   - option -d information détaillée
     + Le nombre de transactions pour chacun des types de transactions;

   - option -s information sommaire
     + Le nombre total de transactions valides;
     + Le nombre total de transactions reçues;

   - option -t mode tranquille
     + Le mode tranquille n'affiche pas transaction en sortie;

 ## Contenu du projet

   - tcv.o: Fichier objet qui contient le code de toutes les fonctions déclarées dans le fichier 'tcv.h'.

   - tcv.h: Fichier d'entête qui sert à déclarer les prototypes des fonctions qui vont être utilisé dans 'tcv.o' et testé dans tp1.c. 

   - data/: Contient la librairie qui sera utilisé dans tp3.c ('tcv.h et 'tcv.o' ) en format compressé zip (tp1.zip || tp2.zip || tp3.zip) qui sera ensuite extrait dans la        racine du projet.

   - tp3: Executable du tp3.
 
   - malib.c: Implémentation des fonctions dans malib.h.

   - malib.h: Prototypes utilisé pour le tp2 dans le main de tp2.c.

   - tp3.c: Programme principale qui traitera les transactions donné en STDIN.

   - test-c.yml: YAML qui s'occupe de la compilation pour les résultats de tests fonctionnels du TP3.
   
   - test-f.yml: YAML qui s'occuper à produire les résultats de/des fichier(s) qui testeront les limites du fonctionnement du programme tp3.

   - outil3.h: Prototypes et déclaration de la fonction 'cmd' et 'distance' utilisé pour le tp3.

   - outil3.c: Implémentation des fonctions déclarées dans outil3.h.

 ## Réflexion et démarche
   
   - https://github.com/Nami-R2301/inf3135-a2020/blob/tp2/reflexion.md 

 ## Références + Signature 

   - Guy Francoeur -> https://github.com/guyfrancoeur/INF3135_A2020/blob/master/tp/tp2-%C3%A9nonc%C3%A9.md 
   - cplusplus reference -> https://www.cplusplus.com/reference/ 

 ## Statut et auto-évaluation

   - Fini. (100%). 
   - Je croix que je mérite au moins 18 points, car j'ai vraiment mis beaucoup de temps sur ce travail et j'ai vraiment réfléchi et essayé de le perfectionné.
     De plus, j'ai mis beaucoup d'effort à produire un dépôt parfait ainsi que des workflows très descriptif, simple et sans ambuiguités!

### Crée et édité par Nami Reghbati à 01:50 EST 17/12/2020 

