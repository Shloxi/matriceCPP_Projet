#include <stdio.h>
#include <iostream>
#include <fstream>
#include "CMatrice.h"
#include "CException.h"
using namespace std;

// Constantes d erreurs liees aux attributs
#define CMatriceNullAttributes 11
#define CMatriceEmptyDataTab 12


// Constantes d erreurs liees aux calculs
#define CMatriceNotSameSize 51
#define CMatriceNotCompatibleSize 52
#define CMatriceDividedBy0 53

template <typename T> static CMatrice<T> * multiply(CMatrice<T> M, int eVal) throw() {
	// On verifie que les attributs sont initalises
	if (M.getNbLigne() == 0 || M.getNbCol() == 0) {
		throw CException(CMatriceNullAttributes);
	}
	if (M.getMatrice() == NULL) {
		throw CException();
	}

	// On alloue notre matrice de r�sultat
	CMatrice<T> * res = new CMatrice<T>(M);

	for (int i = 0; i < M.getNbLigne(); ++i) {
		for (int y = 0; y < M.getNbCol(); ++y) {
			// Pour chaque valeur dans la matrice, on la multiplie par eVal
			res->getMatrice()[i][y] *= eVal;
		}
	}
	return res;
}

template <typename T> static CMatrice<T> * multiplyMat(CMatrice<T> M1, CMatrice<T> M2) throw() {
	if (M1.getNbLigne() == 0 || M1.getNbCol() == 0 || M2.getNbLigne() == 0 || M2.getNbCol() == 0) {
		throw CException(CMatriceNullAttributes);
	}
	if (M1.getMatrice() == NULL || M2.getMatrice() == NULL) {
		throw CException(CMatriceEmptyDataTab);
	}

	if (M2.getNbLigne() != M1.getNbCol()) {
		throw CException(CMatriceNotCompatibleSize);
	}

	CMatrice<T> * res = new CMatrice<T>(M1.getNbLigne(), M2.getNbCol());

	for (int i = 0; i < M1.getNbLigne(); i++) {
		for (int j = 0; j < M2.getNbCol(); j++) {
			for (int x = 0; x < M1.getNbCol(); x++) {
				res->getMatrice()[i][j] += M1.getMatrice()[i][x] * M2.getMatrice()[x][j];
			}
		}
	}
	return res;
}



template <typename T> static CMatrice<T> * divide(CMatrice<T> M, int eVal) throw() {
	// On verifie que les attributs sont initalises
	if (M.getNbLigne() == 0 || M.getNbCol() == 0) {
		throw CException(CMatriceNullAttributes);
	}
	if (M.getMatrice() == NULL) {
		throw CException(CMatriceEmptyDataTab);
	}
	if (eVal == 0) {
		throw CException(CMatriceDividedBy0);
	}

	// On alloue notre matrice de resultat
	CMatrice<T> * res = new CMatrice<T>(M);

	for (int i = 0; i < M.getNbLigne(); ++i) {
		for (int y = 0; y < M.getNbCol(); ++y) {
			// Pour chaque valeur dans la matrice, on la divise par eVal
			res->getMatrice()[i][y] /= eVal;
		}
	}
	return res;
}


template <typename T> static CMatrice<T> * transpose(CMatrice<T> M) {
	CMatrice<T> * res = new CMatrice<T>(M.getNbCol(), M.getNbLigne());

	for (int i = 0; i < M.getNbLigne(); i++) {
		for (int j = 0; j < M.getNbCol(); j++) {
			res->getMatrice()[j][i] = M.getMatrice()[i][j];
		}
	}
	return res;
}

template <typename T> static CMatrice<T> * addMat(CMatrice<T> M1, CMatrice<T> M2) throw() {
	if (M1.getNbLigne() == 0 || M1.getNbCol() == 0 || M2.getNbLigne() == 0 || M2.getNbCol() == 0) {
		throw CException(CMatriceNullAttributes);
	}
	if (M1.getMatrice() == NULL || M2.getMatrice() == NULL) {
		throw CException(CMatriceEmptyDataTab);
	}

	if (M1.getNbLigne() != M2.getNbLigne()) {
		throw CException(CMatriceNotSameSize);
	}
	if (M1.getNbCol() != M2.getNbCol()) {
		throw CException(CMatriceNotSameSize);
	}
	CMatrice<T> * res = new CMatrice<T>(M1.getNbLigne(), M1.getNbCol());
	for (int i = 0; i < M1.getNbLigne(); ++i) {
		for (int y = 0; y < M1.getNbCol(); ++y) {
			res->getMatrice()[i][y] = M1.getMatrice()[i][y] + M2.getMatrice()[i][y];
		}
	}

	return res;
}

template <typename T> static CMatrice<T> * subMat(CMatrice<T> M1, CMatrice<T> M2) throw() {
	if (M1.getNbLigne() == 0 || M1.getNbCol() == 0 || M2.getNbLigne() == 0 || M2.getNbCol() == 0) {
		throw CException(CMatriceNullAttributes);
	}
	if (M1.getMatrice() == NULL || M2.getMatrice() == NULL) {
		throw CException(CMatriceEmptyDataTab);
	}
	if (M1.getNbLigne() != M2.getNbLigne()) {
		throw CException(CMatriceNotSameSize);
	}
	if (M1.getNbCol() != M2.getNbCol()) {
		throw CException(CMatriceNotSameSize);
	}
	CMatrice<T> * res = new CMatrice<T>(M1.getNbLigne(), M1.getNbCol());
	for (int i = 0; i < M1.getNbLigne(); ++i) {
		for (int y = 0; y < M1.getNbCol(); ++y) {
			res->getMatrice()[i][y] = M1.getMatrice()[i][y] - M2.getMatrice()[i][y];
		}
	}

	return res;
}