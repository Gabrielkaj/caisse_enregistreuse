#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double argents[14] = {2000, 1000, 500, 200, 100, 50, 25, 20, 10, 5, 1, 0.50, 0.20, 0.05};
int stock[14] = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};


double generer_valeur() {
	return ((double)(rand() % 20000)) / 100.0;
}


void calcule_monnaie(double rendu) {
	printf("Reste : %2f RS\n", rendu);
	for (int i = 0; i < 14; i++) {
		int nombre = 0;
		while (rendu >= argents[i] && stock[i] > 0) {
			rendu = (int)((rendu - argents[i])* 100.0) / 100.0;
			stock[i]--;
			nombre++;
		}

		if (nombre > 0){
			printf ("Rs %2f x %d\n", argents[i], nombre);
		}
	}


	if (rendu > 0.001) {
		printf ("Pas de monnaie en dessous de 0.05 ." );
		printf ("Reste : %2f Rs\n", rendu);
	}
}

int verifier_stock() {
	for (int i = 0; i < 14; i++) {
		if (stock[i] > 0){
			return 1;
		}
	}
	return 0;
}


void afficher_stock() {
	printf ("Stock : \n");
	for (int i = 0; i < 14; i++) {
		printf("Rs %2f : %d\n", argents[i], stock[i]);
	}
}


int main ()
{
	char choix;


	if (!verifier_stock()) {
		printf ("La caisse est vide. Que vouez-vous faire?  Remplir (r) ou Fermer (f) : ");
		scanf ("%c", &choix);
		if (choix = 'r') {
			for (int i = 0; i < 14; i++) {
				stock[i] = 10;
				continue;
			}
		}
		else {
			choix  = 'n';
		}
	}

	double a_payer = generer_valeur();
	printf ("Vous devez payer : %2f Rs\n", a_payer);


	double donne = 0.0;
	printf ("Le montant payer est de :");
	scanf ("%lf", &donne);

	while (donne < a_payer) {
		printf ("Veuillez augmenter le montant a payer. \n ");

		printf ("Le montant a payer est de :");
		scanf ("%lf", &donne);

	}

	double rendu = donne - a_payer;
	calcule_monnaie(rendu);
	afficher_stock;

	printf("Fin du programme.\n");

}
