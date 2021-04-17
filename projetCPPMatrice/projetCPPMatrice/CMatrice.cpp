#include <stdio.h>
#include <iostream>
#include "CMatrice.h"
#include "CException.h"
using namespace std;


// ###### Constructors

template <typename T> CMatrice<T>::CMatrice() {
	eNbLigne = 0;
	eNbCol = 0;

	tppTableau = NULL;
}

template <typename T> CMatrice<T>::CMatrice(int eLigne, int eCol) {
	eNbLigne = eLigne;
	eNbCol = eCol;

	tppTableau = NULL;
}

template <typename T> CMatrice<T>::CMatrice(int eLigne, int eCol, T ** tppValeurs) {
	eNbLigne = eLigne;
	eNbCol = eCol;
	tppTableau = tppValeurs;
}



// ###### Methods

template <typename T> CMatrice<T>::CMatrice(const CMatrice<T>& m) {
	eNbLigne = m.eNbLigne;
	eNbCol = m.eNbCol;

	// On alloue un tableau de pointeurs de pointeurs pour la matrice
	int ** tppvaleurs;
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
	// On désalloue le tableau dynamique de valeur 
	delete(tppTableau);
}

template <typename T> CMatrice<T> * CMatrice<T>::multiply(int eVal) const throw() {
	// On vérifie que les attributs sont initalisés
	if (eNbLigne == NULL || eNbCol == NULL) {
		throw new CException();
	}
	if (tppTableau == NULL) {
		throw new CException();
	}

	// On alloue notre matrice de résultat
	CMatrice<T> * res = new CMatrice<T>(*this);

	for (int i = 0; i < eNbLigne; ++i) {
		for (int y = 0; y < eNbCol; ++y) {
			// Pour chaque valeur dans la matrice, on la multiplie par eVal
			res->tppTableau[i][y] *= eVal;
		}
	}
	return res;
}

template <typename T> CMatrice<T> * CMatrice<T>::divide(int eVal) const throw() {
	// On vérifie que les attributs sont initalisés
	if (eNbLigne == NULL || eNbCol == NULL) {
		throw new CException();
	}
	if (tppTableau == NULL) {
		throw new CException();
	}

	// On alloue notre matrice de résultat
	CMatrice<T> * res = new CMatrice<T>(*this);

	for (int i = 0; i < eNbLigne; ++i) {
		for (int y = 0; y < eNbCol; ++y) {
			// Pour chaque valeur dans la matrice, on la divise par eVal
			res->tppTableau[i][y] /= eVal;
		}
	}
	return res;
}


template <typename T> CMatrice<T> * CMatrice<T>::transpose() {
	CMatrice<T> * res = new Cmatrice<T>(eNbCol, eNbLigne);
	T ** tppTransposVal;
	tppTransposVal = new T *[eNbCol];
	for (int i = 0; i < eNbLigne; i++) {
		for (int j = 0; j < eNbCol; j++) {
			tppTransposVal[j][i] = tppTableau[i][j];
		}
	}
	res->tppTableau = tppTransposVal;
	return res;
}

template <typename T> void CMatrice<T>::display() const throw() {
	if (eNbLigne == NULL || eNbCol == NULL) {
		throw new CException();
	}
	if (tppTableau == NULL) {
		throw new CException();
	}
	for (int i = 0; i < eNbLigne; ++i) {
		for (int y = 0; y < eNbCol; ++y) {
			cout << tppTableau[i][y] << " ";
		}
		cout << endl;
	}
	cout << endl;
}



