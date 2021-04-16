#include <stdio.h>
#include <iostream>
#include "CMatrice.h"
#include "CException.h"
using namespace std;



template <typename T> CMatrice<T>::CMatrice() {
	eNbLigne = 0;
	eNbCol = 0;

	tppTableau = NULL;
}

template <typename T> CMatrice<T>::CMatrice(int eLigne, int eCol, T ** tppValeurs) {
	eNbLigne = eLigne;
	eNbCol = eCol;
	tppTableau = tppValeurs;
}

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
	
}

template <typename T> CMatrice<T> * CMatrice<T>::multiply(int eVal) const throw() {
	// On v�rifie que les attributs sont initalis�s
	if (eNbLigne == NULL || eNbCol == NULL) {
		throw new CException();
	}
	if (tppTableau == NULL) {
		throw new CException();
	}

	// On alloue notre matrice de r�sultat
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
	// On v�rifie que les attributs sont initalis�s
	if (eNbLigne == NULL || eNbCol == NULL) {
		throw new CException();
	}
	if (tppTableau == NULL) {
		throw new CException();
	}

	// On alloue notre matrice de r�sultat
	CMatrice<T> * res = new CMatrice<T>(*this);

	for (int i = 0; i < eNbLigne; ++i) {
		for (int y = 0; y < eNbCol; ++y) {
			// Pour chaque valeur dans la matrice, on la divise par eVal
			res->tppTableau[i][y] /= eVal;
		}
	}
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
