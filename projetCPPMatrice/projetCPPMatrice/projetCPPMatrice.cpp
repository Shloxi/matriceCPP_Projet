// projetCPPMatrice.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "Cmatrice.cpp"
#include "CMatrice.h"
#include "CException.h"

struct aze {
	int aze;
};

int main()
{
    std::cout << "Branche dev_Romu\n";
	
	//Création de tableaux dynamiques
	int nbLig = 5;
	int nbCol = 5;
	int ** tpptableau;
	tpptableau = new int * [nbLig];
	for (int i = 0; i < nbLig; ++i) {
		tpptableau[i] = new int[nbCol];
	}	
	tpptableau[0][0] = 0;
	tpptableau[0][1] = 1;
	tpptableau[0][2] = 2;
	tpptableau[0][3] = 3;
	tpptableau[0][4] = 4;
	tpptableau[1][0] = 5;
	tpptableau[1][1] = 6;
	tpptableau[1][2] = 7;
	tpptableau[1][3] = 8;
	tpptableau[1][4] = 9;
	tpptableau[2][0] = 10;
	tpptableau[2][1] = 11;
	tpptableau[2][2] = 12;
	tpptableau[2][3] = 13;
	tpptableau[2][4] = 14;
	tpptableau[3][0] = 15;
	tpptableau[3][1] = 16;
	tpptableau[3][2] = 17;
	tpptableau[3][3] = 18;
	tpptableau[3][4] = 19;
	tpptableau[4][0] = 20;
	tpptableau[4][1] = 21;
	tpptableau[4][2] = 22;
	tpptableau[4][3] = 23;
	tpptableau[4][4] = 24;
	CMatrice<int> * M1 = new CMatrice<int>(5,5, tpptableau);
	aze azez;
	
	M1->display();
	//CMatrice<int> * M1 = new CMatrice<int>();
	//CException * e = new CException();

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
