#include <stdio.h>
#include <time.h>
#include <math.h>

double timer( void (*f) ( long ), long digits );
void boucleAvant( long digits );
void boucleApres( long digits );
void racineCarreEntiere( long chiffreEntier );

int main( int argc, char *user[] ) {
	
	if ( argc == 2 ) {
		long x = 32;
		long j = 17179869184;
       	 	printf( "\n\nHello, %s\n\n", user[1] );
		printf( "Temps total d'execution pour boucle A : %f\n\n", timer( ( boucleAvant ),  x ) );
		printf( "Temps total d'execution pour boucle B : %f\n\n", timer( ( boucleApres ),  x ) );
		printf( "Temps total d'execution pour 'racineCarreEntiere'  : %f\n\n", timer( ( racineCarreEntiere ),  j ) );
        	return 0;
	} else {
		printf( "Usage: argv[0] 'Votre nom'\nErreur : Un seul argument permis.\n" );
		return -1;
	}
}

double timer( void ( *f ) ( long ), long digits ) {
	clock_t begin = clock();
	f( digits );
	clock_t end = clock();
	return (double) ( end - begin ) / CLOCKS_PER_SEC;
}

void boucleAvant( long digits ) {
	
	printf( "Boucle d'entiers de variante A (++i) : " );
        for( long i = 0; i < digits; ++i ) {
        	printf( "%ld", i );
        }
	printf( "\n\n" );
}

void boucleApres( long digits ) {

	printf( "Boucle d'entiers de variante B (i++) : " );
	for( long j = 0; j < digits; ++j ) {
                printf( "%ld", j );
        }
	printf( "\n\n" );
}

void racineCarreEntiere( long chiffreEntier ) {
	 printf( "Racine carre entiere de %ld = %LF\n\n", chiffreEntier,  sqrtl ( (double) chiffreEntier) );
}


//void ligneCommande() {
//}

//int somme(void) {
//}

//bool estTrie(void) {
//}

//void elementPlusFrequent(void) {
//}

//void nombreOccurences(void) {
//}




