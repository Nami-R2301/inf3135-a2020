 # Travail pratique 1

   ## Description

	Pour le TP#1, nous implémentons des tests unitaires qui testent la fonctionalité du programme 'TCV'.
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
   

   ## Contenu du projet

   	<TODO>

   ## Références

	Guy Francoeur -> https://github.com/guyfrancoeur/INF3135_A2020/blob/master/tp/tp1-%C3%A9nonc%C3%A9.md ;
	https://github.com/guyfrancoeur/INF3135_A2020/blob/master/code/cUnit.md

	Cunit Source Forge -> http://cunit.sourceforge.net/index.html

   ## Statut

	Structure fini. (60% complété, reste les tests à implementer)
   
   ## Autoévaluation
   
   	<TODO>

