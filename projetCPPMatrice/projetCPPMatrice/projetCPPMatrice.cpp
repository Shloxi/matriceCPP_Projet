// projetCPPMatrice.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "Cmatrice.cpp"
#include "CMatrice.h"
#include "CException.h"

int main()
{
	std::cout << "Branche dev_Romu\n";

	//Création du tableau de pointeurs de pointeurs pour la Matrice
	int nbLig = 5;
	int nbCol = 5;
	int ** tpptableau;
	tpptableau = new int *[nbLig];
	for (int i = 0; i < nbLig; ++i) {
		tpptableau[i] = new int[nbCol];
	}

	tpptableau[0][0] = 1;
	tpptableau[0][1] = 0;
	tpptableau[0][2] = 0;
	tpptableau[0][3] = 0;
	tpptableau[0][4] = 0;
	tpptableau[1][0] = 0;
	tpptableau[1][1] = 3;
	tpptableau[1][2] = 0;
	tpptableau[1][3] = 0;
	tpptableau[1][4] = 0;
	tpptableau[2][0] = 0;
	tpptableau[2][1] = 0;
	tpptableau[2][2] = 0;
	tpptableau[2][3] = 0;
	tpptableau[2][4] = 5;
	tpptableau[3][0] = 0;
	tpptableau[3][1] = 0;
	tpptableau[3][2] = 0;
	tpptableau[3][3] = 0;
	tpptableau[3][4] = 0;
	tpptableau[4][0] = 0;
	tpptableau[4][1] = 6;
	tpptableau[4][2] = 0;
	tpptableau[4][3] = 0;
	tpptableau[4][4] = 0;

	try {
		CMatrice<int> * M1 = new CMatrice<int>(5, 5, tpptableau);


		// Affichage de M1
		cout << "Base" << endl;
		cout << *M1 << endl;

		// Multiplication de M1
		CMatrice<int> * M2 = M1->multiply(5);
		cout << "Multiplication" << endl;
		cout << *M2 << endl;

		CMatrice<int> * MA = new CMatrice<int>();
		*MA = (*M1)*(*M1);
		cout << "M1 * M1" << endl;
		cout << *MA << endl;

		// Transposée de M1
		CMatrice<int> * MT = M1->transpose();
		cout << "Transposee" << endl;
		cout << *MT << endl;

		// Division de M1
		CMatrice<int> * M3 = M1->divide(5);
		cout << "Division" << endl;
		cout << *M3 << endl;

		// On verifie si M1 a été modifié
		cout << "M1 non changee ?" << endl;
		cout << *M1 << endl;

		// On test la construction de matrice par fichier.

		//CMatrice<float> * M4 = new CMatrice<float>("testMatriceFalse.txt");
		CMatrice<float> * M5 = new CMatrice<float>("testMatriceTrue.txt");
		cout << "Matrice via fichier" << endl;
		cout << *M5 << endl;
		//M5->pouet();
		

		// Test surcharge
		CMatrice<int> * MTest = new CMatrice<int>();
		*MTest = *M1 * 5;
		cout << "Surcharge operateur *" << endl;
		cout << *MTest << endl;

		CMatrice<int> * MTest2 = new CMatrice<int>();
		*MTest2 = 5 * (*M1);
		cout << *MTest2 << endl;

		CMatrice<int> * MTest3 = new CMatrice<int>();
		*MTest3 = *M1 / 5;
		cout << "Surcharge operateur /" << endl;
		cout << *MTest3 << endl;

		//Addition de matrice
		CMatrice<float> * MAdd = new CMatrice<float>();
		*MAdd = *M5 + *M5;
		cout << "M1 + M2" << endl;
		cout << *MAdd << endl;

		//Soustraction de matrice
		CMatrice<int> * MSub = new CMatrice<int>();
		*MSub = *M1 - *M2;
		cout << "M1 - M2" << endl;
		cout << *MSub << endl;
		if (typeid(int) == typeid(float)) {
			cout << "zebi" << endl;
		}
		
	}
	catch (CException e) {
		std::cerr << e.ExceptGetIndexError();
	}

	std::cout << "All work done" << std::endl;
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
