 # Travail pratique 2

   ## Description

	Pour le TP#2, nous implémentons des tests unitaires qui testent la fonctionalité du programme 'TCV'.
	Le code est déjà inclu dans le dépôt dont le projet se trouve, plus précisément les fichiers 'TCV.h'
 	et 'TCV.o'. Pour ce travail, on utilise la librairie 'Cunit' en mode basique pour effectuer nos tests.
	Le dépôt github qu'on utilise pour déposer ce TP doit être prêt à rendre le **18 Octobre 2020 :: 23:59 EST**.       
   ## Auteur

	Réalisé par Nami Reghbati; REGN03079808.

   ## Fonctionnement

	*Le programme tp1.c doit tester à l'aide de la librairie cUnit toutes variantes des fonctions suivantes :*

        Valider la température humaine : validerTH_X
        Valider la température ambiante : validerTA_X
        Valider la pulsation : validerPulsation_X
        Valider le Signal : validerSignal_X
        contenues dans les fichiers :

        objet : tcv.o; => Contient le code des fonctions précédentes.
        entête : tcv.h. => Contient les prototypes utilisés dans tcv.o et tp1.c pour les tests.

        Le rôle du programme tp1.c et de son exécutable est de tester et afficher les noms des tests (fonctions)
	qui échouent et qui passent. Ainsi, il sera >

        Il y aura une fonction de test (cUnit) pour chacune des fonctions contenues/listées/à tester dans tcv.h.

        c'est-à-dire : il y a un test_nom_de_la_fonction par fonction ex. : test_validerSignal_1;
        Il y aura sûrement plusieurs assert pour chacune des fonctions afin de tester tous les cas possibles.

        Le programme exécutable tp1 doit être lancé en ligne de commande avec la syntaxe suivante :

        $ ./tp1 => *OU avec les make "test" et "liste" pour respecter certaines conditions.*

	Ex 1:
		Commande(s) pour compilation et execution du projet: 'make lib'; 'make'; ./tp1 
		
		Résultat:

		------------------------------------------------------------------------------------------------------ 

		CUnit - A unit testing framework for C - Version 2.1-3 http://cunit.sourceforge.net/

		Test: validerTH_1... passed
		Test: validerTH_2... FAILED
		1. tp1.c:27  - CU_ASSERT_TRUE(validerTH_2( (unsigned) 17 ) && validerTH_2( (unsigned) 40 ))

   		Run Summary:    Type  Total    Ran Passed Failed Inactive
              	suites      1      1    n/a      0        0
               	tests       1      1      1      1        0
             	asserts     2      2      2      2      n/a

		Elapsed time =    0.000 seconds
		
		1. tp1.c:27  - CU_ASSERT_TRUE(validerTH_1( (unsigned) 17 ) && validerTH_1( (unsigned) 40 ))
		------------------------------------------------------------------------------------------------------
	Ex 2:
		Commande(s) pour compilation et execution du projet: 'make lib'; make test
		
		Résultat:

		------------------------------------------------------------------------------------------------------
		CUnit - A unit testing framework for C - Version 2.1-3 http://cunit.sourceforge.net/

                Test validerTH_1: passed...

                Run Summary:    Type  Total    Ran Passed Failed Inactive
                suites      1      1    n/a      0        0
                tests       1      1      1      1        0
                asserts     2      2      2      2      n/a

                Elapsed time =    0.000 seconds
		------------------------------------------------------------------------------------------------------

	Ex 3:

		Commande(s) pour compilation et execution du projet: 'make lib'; make liste

                Résultat:


                Test validerTH_1: passed...

---------------------------------------------------------------------------------------------------------------------

   ## Contenu du projet

   	Makefile: Automatise la compilation en lui spécifiant la cible et la source ainsi que quelle(s) commande(s)
		exécuter pour faire la bonne compilation.

	cp.txt: Code permanent de l'auteur.

	tp1.c: Contient le code des tests unitaires des fonctions déclarées dans 'tcv.h' et codé dans 'tcv.o'.

	tcv.o: Fichier objet qui contient le code de toutes les fonctions déclarées dans le fichier 'tcv.h'.

	tcv.h: Fichier d'entête qui sert à déclarer les prototypes des fonctions qui vont être utilisé dans 'tcv.o
		et testé dans tp1.c.

	data/: Contient la librairie qui sera utilisé dans tp1.c ('tcv.h et 'tcv.o ) en format compressé zip (tp1.zip)
		qui sera ensuite extrait dans la racine du projet.

	liste.sh: Fichier executable bash qui contiendra la commande pour simplifier l'affichage des test en affichant
		seulement ceux qui ont réussi. Ce fichier ne prend que le STDOUT comme argument.
	
	tp1: Fichier exécutable qui contiendra la totalité des tests unitaires sur le code de 'tcv.o'. Ce fichier
		prend comme argument les fichiers 'tcv.o et 'tcv.h' lors de la compilation Cunit.

	.gitignore: Contient les fichier objets et binaires pour ne pas les prendrent en considération lors des dépôts.  

	README.md: Fichier texte qui décrit le projet en détails.

   ## Références

	Guy Francoeur -> https://github.com/guyfrancoeur/INF3135_A2020/blob/master/tp/tp2-%C3%A9nonc%C3%A9.md ;
	cplusplus reference -> https://www.cplusplus.com/reference/ ;


   ## Statut et auto-évaluation

	-fini Makefile et liste.sh (30%).

   	-Je croix que je mérite au moins 8 points, car j'ai vraiment mis beaucoup de temps sur ce travail et
	 j'ai vraiment réfléchi et essayé de le perfectionné.
----------------------------------------------------------------------------------------------------------------------------------------------------
Crée et édité par Nami Reghbati à 18:47 EST 14/11/2020
