#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double generer_valeur() {
	return ((double)(rand() % 2000)) / 100.0;
}



int main ()
{
	double argents[14] = {2000, 1000, 500, 200, 100, 50, 25, 20, 10, 5, 1, 0.50, 0.20, 0.05};
	int stock[14] = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
	char choix;


	do {

		if (!verifier_stock()) {
			printf ("La caisse est vide. Que vouez-vous faire?  Remplir (r) ou Fermer (f) : ");
			scanf ("%c", &choix);

			if (choix == "r") {
				for (int i = 0; i < 14; i++) {
					stock[i] = 10;
					continue;
				}

			}
			else {
				break;
			}
		}

	double a_payer = generer_valeur();
	printf ("Vous devez payer : %2f Rs\n", a_payer);


	double donne = 0.0;
	do {
		printf ("Le montant payer est de :");
		scanf ("%lf", &donne);
	}while (donne < a_payer);

	double rendu = donne - a_payer;
	calcule_monnaie(rendu);
	afficher_stock;

	printf("Fin du programme")

}
