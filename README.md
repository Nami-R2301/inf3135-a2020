---
title: Devoir final INF3173
author: Jean Privat
date: du 15 au 16 mars 2021
---

* Chaque devoir est **individuel**.
* Le sujet est en Markdown, répondez directement dans le fichier. Codage UTF-8, fins de lignes Unix.
* Répondez sur les lignes avec des chevrons (`>`), répondez après les chevrons ; vous pouvez en modifier le nombre, mais laissez les chevrons en place (pour que je voie vos réponses).
* Les limites maximales en nombre de mots des réponses seront interprétées avec intelligence.
* **Ne touchez pas** au reste du sujet. Un `diff` entre votre copie et le sujet ne **doit** faire apparaitre que vos réponses.
* Les réponses devront être aussi **détaillées** et **argumentées** que possible (en respectant la taille de la réponse attendue).
* Vous avez jusqu'au mardi 16 mars 2021 à 23h55 pour remettre votre fichier Markdown via Moodle. Vous pouvez faire autant de remises que vous le souhaitez, seule la dernière sera considérée.
* Merci de **ne pas discuter** du contenu du sujet sur Mattermost (ou via tout autre médium).
* Si vous avez des questions, vous pouvez toujours tenter de me les poser en message privé sur Mattermost, mais je me réserve le droit de **ne pas répondre** (ou de répondre après la date de remise).
* Tout non-respect du format ou des consignes sera pénalisé.
* La qualité du français ainsi que la rigueur, la précision et la justesse dans les explications et dans le vocabulaire du cours utilisé sera pris en compte.


## Identification des étudiants

* Nom: Reghbati
* Prénom: Nami
* Code permanent: REGN03079808


## Quiz

La première partie du devoir est sous forme d'un quiz indépendant.
Quand le quiz est commencé, il doit être terminé en moins de 30 minutes.

* <https://www.moodle2.uqam.ca/coursv3/mod/quiz/view.php?id=2296701>


## Présentation du programme metsys

Un programmeur débutant développe le programme `metsys.c` qui permet d'exécuter indépendamment un programme ou une commande shell.
L'astuce proposée par le programmeur est simple : si l'exécution directe du programme échoue, on l'exécute sous forme de commande shell grâce à l'option `-c` du shell.

```c
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<wait.h>

int metsys(char **cmd) {
	pid_t pid = fork();
	if (pid > 0) {
		int res = execv(*cmd, cmd); // on tente d'exécuter sans le shell
		if (res == -1) {
			// si ça échoue, on réessaye, mais avec le shell cette fois!
			pid = fork();
			if (pid > 0) {
				execl("/bin/bash", "sh", "-c", *cmd, cmd, (char*)NULL);
			}
		}
	}
	
	int status=0;
	wait(&status);
	return status;
}

int main(int argc, char **argv) {
	int code = metsys(argv+1);
	printf("#status=%d\n", code);
}
```


## Première expérience

Malheurusement, le programme ne fonctionne pas très bien.

Si on exécute `./metsys /bin/echo bonjour le monde`, on obtient

```
#status=0
bonjour le monde
```

Ce qui est surprenant, car l'affichage du `echo` apparait après la ligne de statut (qui indique la valeur du code de retour) ce qui laisserait sous-entendre des entorses philosophiques au principe de causalité et à la théorie de la linéarité du temps.


### Q1

Combien de processus sont mis en oeuvre lors de l'exécution de `./metsys /bin/echo bonjour le monde`?

Quels sont pour chacun d'eux :

* leurs relations de parenté ?
* les fork, exec, wait et exit réalisés ?
* leurs affichages ?

Détaillez et justifiez votre réponse.

(150 mots maximum)

**Processus :**
> Sur cette ligne, il y a deux processus mis en oeuvre si le `fork` de `metsys` passe : `./metsys` et `metsys[1]`.
> Le programme `./metsys` qui est exécuté par bash, va faire un `fork`, ce qui créera un processus enfant `metsys[1]`.

**Relations de parenté :**
> `metsys` est un enfant de `/bin/bash` et parent de `metsys[1]`.
> `metsys[1]` est un enfant de 'metsys'.

**Appel(s) réalisé(s) :**
> metsys réalise : un `fork`, un `execv(/bin/echo, Bonjour le monde)`, aucun `wait` et un `exit(0)`.
> `metsys[1]` réalise : aucun `fork`, aucun `exec`, un `wait` invalide (`ECHILD`) et un `exit(0)`(fin du `write`).

**Affichage(s) :**
> metsys affiche `bonjour le monde\n`.
> `metsys[1]` affiche `#status=0\n`.
> Ensemble, ils affichent `#status=0\nbonjour le monde\n`.


### Q2

Pourquoi l'affichage de la ligne de statut a lieu avant l'affichage du echo ?
Est-ce systématique ou est-ce que l'ordre peut varier d'une exécution à l'autre ?
Détaillez et justifiez votre réponse.

(150 mots maximum)

**Raisonement de l'affichage :** 
> Le `main` de `metsys` s'exécute en lui passant `argv[1]` comme argument. Ensuite, nous rentrons dans le `if` principal, 
> seulement si ont est le processus parent. Pendant ce temps, l'enfant ignore le `if` et initialise `status` à zéro et 
> passe par dessus la ligne contenant : `wait`, car il n'est pas un processus parent (`ECHILD`). Enfin, l'enfant termine
> le programme en affichant le status.

**Résultat systématique ou non? :** 
> non, car le parent n'attend pas pour l'enfant ce qui amène à des affichages varier. Par exemple : Le processus enfant 
> peut finir avant l'exécution de `echo` par le parent. Le processus parent peut aussi échouer tous les `exec`, ce qui
> amène celui-ci à exécuter le reste du code après les `exec`et répéter l'affichage. Si l'enfant prend plus de temps que
> le parent à exécuter ses tâches, le programme se termine avant que l'enfant se rend au `printf`.

### Q3

En prenant comme contexte l'exécution du programme dans cette première expérience, donnez un exemple précis et concret qui correspond à chacune des transitions d'états de processus suivantes:

Passage de l'état actif à l'état prêt.

**Exemple (contexte mono-coeur) : `./metsys /bin/sleep 20`**

> Dans cet exemple, après le clonage (fork), le processus parent metsys passe d'actif à prêt, car l'ordonnanceur donne 
> la main à `metsys[1]` (enfant), ce qui donne que l'enfant termine et affiche en premier. Si le parent aurait reçu la 
> ressource avant, le programme aurait terminé sans afficher le status grâce au `exec`.

Passage de l'état actif à l'état bloqué.

> Suivant le même exemple, lorsque le processus parent metsys se rend à la ligne du `exec`, le parent devient
> momentairement bloqué lorsque `exec` exécute la commande, car elle est en soie bloquante. 

Passage de l'état actif à l'état zombi.

> Suivant le même exemple, le processus enfant fini avant son parent, donc il deviendra un processus zombie, car il 
> contiendra une entrée dans la table des processus malgré le fait qu'il a fini son exécution (`Z defunct`). 


## Seconde expérience

Cette fois-ci on exécute `./metsys echo au revoir`, mais cela affiche

```
#status=0
#status=0

```

Ce qui est très incorrect, car :

* « `au revoir` » n'est aucunement affiché
* Il y a 2 lignes de statut
* Le tout est terminé par une ligne blanche sans rapport


### Q4

Combien de processus sont mis en oeuvre lors de l'exécution de `./metsys echo au revoir` ?

Quels sont pour chacun d'eux :

* leurs relations de parenté ?
* les fork, exec, wait et exit réalisés ?
* leurs affichages ?

Détaillez et justifiez votre réponse.

(150 mots maximum)

**Processus :**
> Sur cette ligne, il y a trois processus mis en oeuvre si les `fork` de `metsys` passent : `./metsys`, `metsys[1]` et
> `metsys[2]`. Le programme `./metsys` qui est exécuté par bash, va faire deux `fork`, ce qui créera deux processus 
> enfants `metsys[1]` et `metsys[2]`, car `execv(cmd[0], cmd)` ne peut pas interprèter `echo` sans le shell et passe au 
> deuxième `fork`.

**Relations de parenté :**
> metsys est l'enfant de /bin/bash et parent de `metsys[1]` et `metsys[2]`.
> `metsys[2]` est l'enfant de `metsys[1]`.
> `metsys[1]` est l'enfant de metsys et parent de `metsys[2]`.

**Appel(s) réalisé(s) :**
> metsys réalise : deux `fork`,  un `exec` invalide (`execv(cmd[0], cmd)`) et un `exec` valide, aucun `wait` et un `exit(0)`.
> `metsys[1]` réalise : aucun `fork`, aucun `exec`, un `wait` invalide  (`ECHILD`) et un `exit(0)`.
> `metsys[2]` réalise : aucun `fork`, aucun `exec`, un `wait` invalide (`ECHILD`) et un `exit(0)`.

**Affichage(s) :**
> metsys affiche `\n`.
> `metsys[1]` affiche `#status=0\n`.
> `metsys[2]` affiche `#status=0\n`.


### Q5 (question bonus difficile)

Pourquoi « au revoir » n'est pas affiché.
Est-ce que cette exécution du programme aurait pu avoir un autre comportement ou un affichage différent ?

(200 mots maximum)

**Raisonement de l'affichage :**
> La raison pour laquelle l'affichage est incorrecte, c'est parce que (`execl("/bin/bash", "sh", "-c", *cmd, cmd, (char*)NULL)`
> est mal utilisé, car ce qui se trouve après le sous-shell (`sh -c`) doit être échappé avec des guillemets (`"` ou `''`)
> puisque  l'option `-c` spécifie que le shell lit la chaine de commandes qui le suit et non l'entrée standard (man sh).
> Donc, la commande `echo au revoir` est en réalité interprétée comme `"echo"`. Finalement, vu que la commande `echo` 
> concatène un retour de chariot à sa chaîne de caractères en argument et que celle-ci est vide dans cet exemple, `"echo"`
> est équivalente à `echo "" + \n`, expliquant l'affichage de la ligne vide au lieu de `au revoir`. 

**Résultat systématique ou non? :**
> Non, car il pourrait y avoir trois affichages différents. Soit `#status=0\n#status=0\n\n`, ou `#status=0\n\n#status=0\n`
> ou `\n#status=0\n#status=0\n`. Comme lors de l'exemple précédent, le code de la méthode `metsys()` de metsys est écrit
> de façon à ce que le processus parent n'attend jamais après ses enfants. Donc, les processus enfants et le parent 
> s'exécutent en parallèle et leur ordre d'affichage dépend de l'ordonancement du système d'exploitation.


## Critique et solution

### Q6

En vous adressant directement au programmeur débutant, pointez chacun des nombreux problèmes de son programme et indiquez ce qui aurait dû être fait.

(200 mots maximum)

> Le processus parent ne devrait pas exécuter la/les commande(s) en argument. Il faut l'isoler des enfants en mettant 
> des conditions selon le `pid` du processus qui est en exécution. Faisant en sorte que la fonction `wait()` soit
> appelée seulement par le processus parent et non par les enfants, car présentement les affichages des statuts peuvent
> ne pas être affichés si le processus parent fini avant que l'enfant exécute le `printf`.
> Il faut gérer le cas d'erreur des `fork`, en rajoutant une condition qui empêche l'exécution des autres tâches en cas
> d'erreurs.
> Le `fork` addtionnel est superflu et inutile. Si `exec` retourne, ça veut dire que `exec` a échoué et le processus enfant
> est encore actif. Ce qui veut dire que le `pid` et sa condition son inutiles, car seul les enfants peuvent rentrer 
> initialement dans le `if` précédent.
> L'implementation de `execl()` assume que `argv[1+]` est une seule commande échappée par des guillemets doubles ce qui
> rend le programme non-robuste. Il faudrait concatener `argv[1]` avec des guillemets doubles avant de faire le `execl()`.
> `status` ne retourne pas le bon code de retour. Il faut utiliser `WEXITSTATUS(status)` pour afficher le bon.


### Q7

Appliquez vos corrections (cf Q6) au programme `metsys.c` et proposez ainsi une solution fonctionnelle.

```c
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<wait.h>
#include <string.h>

int metsys(char **cmd, const int *argc) {
    pid_t pid = fork();
    if(pid == -1) return -1;
    if (pid == 0) { //seulement les enfants entrent.
        execv(cmd[0], cmd); // on tente d'exécuter sans le shell
        char argN[FILENAME_MAX] = ""; //char* de argv[1-n];
        for(int i = 0; i < *argc - 1; ++i) {
            strcat(argN, cmd[i]);
            strcat(argN, " ");
        }
        execl("/bin/bash", "sh", "-c", argN, (char*)NULL);
    }
    int status=0;
    wait(&status); //parent attend.
    return WEXITSTATUS(status); //exit de l'enfant
}

int main(int argc, char **argv) {
    int code = metsys(argv + 1, &argc);
    printf("#status=%d\n", code);
} //Potentiellement, il serait pertinent de rajouter une gestion de code de retour personalisée.
```

## Quiz inversé

### Q8

Proposez une courte question **originale** de quiz sur les systèmes de fichiers (capsules 300 à 330) destinée à des étudiants du cours INF3173.
La question doit être à choix de réponses, avec 4 réponses possibles, mais dont exactement une seule est correcte.
Les 3 autres réponses doivent être suffisamment vraisemblables par rapport à la bonne réponse pour que la question soit intéressante et pertinente à l'évaluation des connaissances sur les principes des systèmes d'exploitation.

> * Question: Vers quoi, d'après vous, l'inode du répertoire parent (`..`) de root (`/`) pointerai?
> * Mauvaise réponse 1: Un inode inférieur au répertoire de root.
> * Mauvaise réponse 2: Un inode supérieur au répertoire de root.
> * Mauvaise réponse 3: Rien. Root ne contient pas de répertoire parent.
> * Bonne réponse: L'inode du répertoire de root. 
