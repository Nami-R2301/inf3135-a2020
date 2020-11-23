 # Travail pratique 2

   ## Description
   - Vous devez dans un fichier nommé tp2.c coder la fonction main() du projet tous contre le virus. Ce système gère des données en entrée (stdin) et en sortie (stdout).
     Le déploiement de certains produits informatique, comme le nôtre, peut devenir complexe lorsque les clients (pastilles) sont répandus partout dans le monde.
     Le déploiement de programmes dit "parfait"est important considérant le sujet et le nombre de modules visés. Une erreur va surement faire les manchettes et sauvez moins
     de vie. La date de livraison est importante et doit être respectée.Cette fois vous utiliserez les fonctions valides disponibles dans tcv.h et tcv.o pour réaliser le travail.

   - Le rôle du programme tp2.c et de son exécutable est de traiter toutes les lignes de données. Dans certains cas vous avez à produire des données sur le canal (stdout)
     de sortie standard. Ceci simule le dialogue (les données échangées). Le résultat en sortie est celui qui sera évalué. 
 
   ## Auteur

   - Réalisé par Nami Reghbati; REGN03079808.

   ## Fonctionnement
   
   - Le programme exécutable peut être lancé en ligne de commande avec différentes syntaxes :

   ```bash $ ./tp2 ## Contenu du projet

   $ cat file.dat | ./tp2
 
   $ ./script.sh | ./tp2 

   $ head -n 100 file.txt | ./tp2 ...

  ``` 
   Le rôle de votre programme est de lire des transactions.  Les transactions sont décrites dans la section **Transaction en entrée / Transaction en sortie**.  Les transactions 
   sont très formelles.  Il s'agit d'un système dit critique, aucune nuance possible.  Ceci ne veut pas dire que les transactions ou le système - Makefile: Automatise la compilation en 
   lui spécifiant la cible et la source ainsi que quelle(s) commande(s) exécuter pour faire la bonne compilation. est exempt d'erreurs.  Vous ne devez, en aucun temps (jamais), laisser 
   le hasard gérer la situation.

   - tp1.c: Contient le code des tests unitaires des fonctions déclarées dans 'tcv.h' et codé dans 'tcv.o'.

   - tcv.o: Fichier objet qui contient le code de toutes les fonctions déclarées dans le fichier 'tcv.h'.

   - tcv.h: Fichier d'entête qui sert à déclarer les prototypes des fonctions qui vont être utilisé dans 'tcv.o' et testé dans tp1.c. 


  - data/: Contient la librairie qui sera utilisé dans tp1.c ('tcv.h et 'tcv.o ) en format compressé zip (tp1.zip) qui sera ensuite extrait dans la racine du projet.

   - liste.sh: Fichier executable bash qui contiendra la commande pour simplifier l'affichage des test en affichant seulement ceux qui ont réussi. Ce fichier ne prend que le STDOUT comme 
     argument. 

   - tp1: Fichier exécutable qui contiendra la totalité des tests unitaires sur le code de 'tcv.o'. Ce fichier prend comme argument les fichiers 
     'tcv.o et 'tcv.h' lors de la compilation Cunit.

 ## Réflexion et démarche
   
   - https://github.com/Nami-R2301/inf3135-a2020/blob/tp2/reflexion.md 

 ## Références + Signature 

   - Guy Francoeur -> https://github.com/guyfrancoeur/INF3135_A2020/blob/master/tp/tp2-%C3%A9nonc%C3%A9.md 
   - cplusplus reference -> https://www.cplusplus.com/reference/ 

   ## Statut et auto-évaluation

   - fini Makefile et liste.sh (30%). 
  - Je croix que je mérite au moins 8 points, car j'ai vraiment mis beaucoup de temps sur ce travail et j'ai vraiment réfléchi et essayé de le perfectionné.

### Crée et édité par Nami Reghbati à 18:47 EST 14/11/2020 

