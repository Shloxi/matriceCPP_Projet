#include <stdio.h>
#include <iostream>
#include "CMatrice.h"
#include "CEXception.h"
#include <string>
using namespace std;



template <typename T> CMatrice<T>::CMatrice() {
	eNbLigne = NULL;
	eNbCol = NULL;

	tppTableau = NULL;
}

template <typename T> CMatrice<T>::CMatrice(int eLigne, int eCol, T ** tppValeurs) {
	eNbLigne = eLigne;
	eNbCol = eCol;
	tppTableau = tppValeurs;
}

template <typename T> void CMatrice<T>::display() {
	if (eNbLigne == NULL || eNbCol == NULL) {
		std::cout << "Matrice Vide" << std::endl;
	}
	else {
		for (int i = 0; i < eNbLigne; ++i) {
			for (int y = 0; y < eNbCol; ++y) {
				char* temp = std::to_string(tppTableau[i][y]);
				if (temp != NULL) {
					std:cout << temp + ' ';
				}
				else {
					throw CException();
				}
			}
			std::cout << std::endl;
		}
	}
}