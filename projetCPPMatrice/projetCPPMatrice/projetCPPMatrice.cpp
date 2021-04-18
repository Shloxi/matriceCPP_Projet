// projetCPPMatrice.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.

#include <iostream>
#include "CMatrice.h"
#include "CException.h"
#include "Cmatrice.cpp"

int main(int argc, char** argv)
{
	cout << "Bienvenue sur le programme de Hugo PERVEYRIE et Romuald DURET !\n";

	if (argc == 1) {
		cout << "Vous n'avez pas rentrer d'argument" << endl;
		return 0;
	}
	else {

		//Création des matrices
		int cptErreur = 0;
		int tailleTableau = 0;
		CMatrice<float> * tCMatrice[100];
		for (int i = 1; i < argc; ++i) {
			try {
				tCMatrice[i - 1 - cptErreur] = new CMatrice<float>(argv[i]);
				++tailleTableau;
				cout << (*tCMatrice[i - 1 - cptErreur]) << endl;
			}
			catch (CException e) {
				cerr << e.errors[e.ExceptGetIndexError()] << endl << endl;
				++cptErreur;
			}
		}
		if (tailleTableau != 0) {
			int x;
			cout << "Veuillez saisir une valeur : ";
			cin >> x;
			// Opérations élémentaires sur les matrices
			try {
				cout << "Multiplication des matrices par " << x << endl;
				for (int i = 0; i < tailleTableau; ++i) {
					cout << *(tCMatrice[i]) * x << endl;
				}

				cout << "Division des matrices par " << x << endl;
				for (int i = 0; i < tailleTableau; ++i) {
					cout << *(tCMatrice[i]) / x << endl;
				}
			}
			catch (CException e) {
				cerr << e.errors[e.ExceptGetIndexError()] << endl << endl;
			}

			// Opération complexes sur les matrices
			try {
				cout << "Addition de toutes les matrices" << endl;
				CMatrice<float> * res = new CMatrice<float>(*tCMatrice[0]);
				for (int i = 1; i < tailleTableau; ++i) {
					*res = *res + *tCMatrice[i];
				}
				cout << *res << endl;

				cout << "Addition et Soustraction alternee de toutes les matrices" << endl;
				CMatrice<float> * res2 = new CMatrice<float>(*tCMatrice[0]);
				for (int i = 1; i < tailleTableau; ++i) {
					if (i % 2 == 0) {
						*res2 = *res2 + *tCMatrice[i];
					}
					else {
						*res2 = *res2 - *tCMatrice[i];
					}
				}
				cout << *res2 << endl;

				cout << "Multiplication de toutes les matrices" << endl;
				CMatrice<float> * res3 = new CMatrice<float>(*tCMatrice[0]);
				for (int i = 1; i < tailleTableau; ++i) {
					*res3 = *res3 * *tCMatrice[i];
				}
				cout << *res3 << endl;
			}
			catch (CException e) {
				cerr << e.errors[e.ExceptGetIndexError()] << endl << endl;
			}
		}
	}
	return 0;
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
