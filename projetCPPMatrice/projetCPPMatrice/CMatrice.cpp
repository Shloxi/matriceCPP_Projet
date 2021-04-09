#include <stdio.h>
#include <iostream>
#include "CMatrice.h"
#include "CException.h"
#include <string>
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

template <typename T> void CMatrice<T>::display() {
	if (eNbLigne == 0 || eNbCol == 0) {
		std::cout << "Matrice Vide" << std::endl;
	}
	else {
		for (int i = 0; i < eNbLigne; ++i) {
			for (int y = 0; y < eNbCol; ++y) {
				T temp = tppTableau[i][y];
				std::cout << tppTableau[i][y] + ' ';
				/*
				if (temp != NULL) {
					
				}
				else {
					throw CException();
				}*/
			}
			std::cout << std::endl;
		}
	}
}