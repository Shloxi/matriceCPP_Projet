#include <stdio.h>
#include <iostream>
#include <fstream>
#include "CMatrice.h"
#include "CMatriceOperation.cpp"
#include "CException.h"
using namespace std;


/*
##################
  CONSTRUCTEURS
##################
*/

template <typename T> CMatrice<T>::CMatrice() {
	eNbLigne = 0;
	eNbCol = 0;
	tppTableau = NULL;
}

template <typename T> CMatrice<T>::CMatrice(int eLigne, int eCol) {
	eNbLigne = eLigne;
	eNbCol = eCol;

	tppTableau = new T *[eLigne];
	for (int i = 0; i < eLigne; i++) {
		tppTableau[i] = new T[eCol];
		for (int j = 0; j < eCol; j++) {
			tppTableau[i][j] = 0;
		}
	}
}

template <typename T> CMatrice<T>::CMatrice(int eLigne, int eCol, T ** tppValeurs) {
	eNbLigne = eLigne;
	eNbCol = eCol;
	tppTableau = tppValeurs;
}

template <typename T> CMatrice<T>::CMatrice(const char * filename) throw() {
	// On vérifie que le nom du fichier n'est pas null
	if (filename == NULL) {

		throw CException(CMatriceFileNotExist);
	}

	// On vérifie que le flux crée est fonctionnelle
	ifstream monFlux(filename);
	if (!monFlux) {
		throw CException(CMatriceEmptyFile);
	}

	// sOutput : Variable de récupération des caractères du fichier
	// sArg : Variable de récupération des arguments du fichier pour la matrice
	// iTailleArg : Taille de la variable sArg pour des vérifications
	// i : Compteur
	// verifType : Tableau de caractères pour la vérification du type de matrice
	char sOutput[100];
	char sArg[100];
	int iTailleArg;
	int i = 12;
	char verifType[6] = "float";

	// Verification des prochaines informations
	char verifTexteType[13] = "TypeMatrice=";
	monFlux >> sOutput;
	i = 0;
	while (i < 12 && sOutput[i] == verifTexteType[i]) {
		++i;
	}
	if (i != 12) {
		throw CException(CMatriceWrongTypeFile);
	}

	// Recuperation du type de la Matrice
	while (sOutput[i] != '\0' || i > 80) {
		sArg[i - 12] = sOutput[i];
		++i;
	}
	sArg[i - 12] = '\0';
	iTailleArg = i - 12;

	// Verification du type de la Matrice
	if (iTailleArg != 5) {
		throw CException(CMatriceWrongTypeFile);
	}
	else {
		for (int cpt = 0; cpt < 5; cpt++) {
			if (sArg[cpt] != verifType[cpt]) {
				throw CException(CMatriceWrongTypeFile);
			}
		}
	}

	// Verification des prochaines informations
	char verifTexteLignes[10] = "NBLignes=";
	monFlux >> sOutput;
	i = 0;
	while (i < 9 && sOutput[i] == verifTexteLignes[i]) {
		++i;
	}
	if (i != 9) {
		throw CException(CMatriceWrongSyntax);
	}

	// Recuperation du nombre de lignes
	i = 9;
	while (sOutput[i] != '\0' || i > 80) {
		sArg[i - 9] = sOutput[i];
		++i;
	}
	sArg[i - 9] = '\0';
	iTailleArg = i - 9;
	if (iTailleArg == 0) {
		throw CException(CMatriceWrongLine);
	}
	eNbLigne = atoi(sArg);

	// Verification des prochaines informations
	char verifTexteColonnes[12] = "NBColonnes=";
	monFlux >> sOutput;
	i = 0;
	while (i < 11 && sOutput[i] == verifTexteColonnes[i]) {
		++i;
	}
	if (i != 11) {
		throw CException(CMatriceWrongSyntax);
	}

	// Recuperation du nombre de colonnes
	i = 11;
	while (sOutput[i] != '\0' || i > 80) {
		sArg[i - 11] = sOutput[i];
		++i;
	}
	sArg[i - 11] = '\0';
	iTailleArg = i - 11;
	if (iTailleArg == 0) {
		throw CException(CMatriceWrongCol);
	}
	eNbCol = atoi(sArg);

	// Verification du nombre de ligne et colonnes
	if (eNbLigne == 0) {
		throw CException(CMatriceWrongLine);
	}
	if (eNbCol == 0) {
		throw CException(CMatriceWrongCol);
	}

	// Allocation en memoire de la structure de la matrice
	float **tpptableau;
	tpptableau = new float *[eNbLigne];
	for (int cpt = 0; cpt < eNbLigne; ++cpt) {
		tpptableau[cpt] = new float[eNbCol];
	}

	// Verification des prochaines informations
	char verifTexte[10] = "Matrice=[";
	monFlux >> sOutput;
	i = 0;
	while (i < 9 && sOutput[i] == verifTexte[i]) {
		++i;
	}
	if (i != 9) {
		throw CException(CMatriceWrongSyntax);
	}

	//Recupération de la matrice
	i = 0;
	while (sOutput[0] != ']' && i < eNbLigne*eNbCol) {
		monFlux >> sOutput;
		// Si la donnee recuperee n'est pas un nombre
		if (sOutput[0] != '0' && atoi(sOutput) == 0) {
			throw CException(CMatriceDataError);
		}
		tpptableau[i / eNbCol][i%eNbCol] = (float)atoi(sOutput);
		++i;
	}

	// Si les donnees ne correspondent pas aux dimensions de la matrice
	monFlux >> sOutput;
	if (sOutput[0] != ']' || i != eNbLigne * eNbCol) {
		// On libere la structure de donnees
		for (int cpt = 0; cpt < eNbLigne; ++cpt) {
			free(tpptableau[cpt]);
		}
		free(tpptableau);
		tpptableau = nullptr;
		throw CException(CMatriceGlobalError);
	}
	tppTableau = tpptableau;
}

template <typename T> CMatrice<T>::CMatrice(const CMatrice<T>& m) {
	eNbLigne = m.eNbLigne;
	eNbCol = m.eNbCol;

	// On alloue un tableau de pointeurs de pointeurs pour la matrice
	// et on attribue les valeurs correspondantes
	T ** tppvaleurs;
	tppvaleurs = new T *[eNbLigne];
	for (int i = 0; i < eNbLigne; ++i) {
		tppvaleurs[i] = new T[eNbCol];
		for (int y = 0; y < eNbCol; ++y) {
			tppvaleurs[i][y] = m.tppTableau[i][y];
		}
	}
	tppTableau = tppvaleurs;
}

template <typename T> CMatrice<T>::~CMatrice() {
	// On d�salloue le tableau dynamique de valeur 
	delete(tppTableau);
}


/*
##################
	METHODES
##################
*/

template <typename T> ostream & CMatrice<T>::display(ostream & os) const throw() {
	if (eNbLigne == 0 || eNbCol == 0) {
		throw CException(CMatriceNullAttributes);
	}
	if (tppTableau == NULL) {
		throw CException(CMatriceEmptyDataTab);
	}
	for (int i = 0; i < eNbLigne; ++i) {
		for (int y = 0; y < eNbCol; ++y) {
			os << tppTableau[i][y] << " ";
		}
		os << endl;
	}
	return os;
}

/*
##################
	ACCESSEURS
##################
*/
template <typename T> int CMatrice<T>::getNbLigne() {
	return eNbLigne;
}

template <typename T> int CMatrice<T>::getNbCol() {
	return eNbCol;
}

template <typename T> T ** CMatrice<T>::getMatrice() {
	return tppTableau;
}

/*
##################
	SURCHARGES
##################
*/

template <typename T> CMatrice<T> & CMatrice<T>::operator*(int const c) {
	CMatrice<T> * res = multiply(*this, c);
	return *res;
}

template <typename T> CMatrice<T> & operator*(int const c, CMatrice<T> const M)
{
	CMatrice<T> * res = multiply(*M, c);
	return *res;
}

template <typename T> CMatrice<T> & CMatrice<T>::operator/(int const c) {
	CMatrice<T> * res = divide(*this, c);
	return *res;
}

template <typename T> ostream & operator<<(ostream& os, CMatrice<T> const M) {
	M.display(os);
	return os;
}

template <typename T> CMatrice<T> & CMatrice<T>::operator*(CMatrice<T> const M) {
	CMatrice<T> * res = multiplyMat(*this, M);
	return *res;
}

template <typename T> CMatrice<T> & CMatrice<T>::operator+(CMatrice<T> const M) {
	CMatrice<T> * res = addMat(*this, M);
	return *res;
}

template <typename T> CMatrice<T> & CMatrice<T>::operator-(CMatrice<T> const M) {
	CMatrice<T> * res = subMat(*this, M);
	return *res;
}
