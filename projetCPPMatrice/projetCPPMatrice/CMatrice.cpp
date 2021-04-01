#include <stdio.h>
#include <iostream>
#include "CMatrice.h"
#using namespace std;



template <typename T> CMatrice::CMatrice() {
	eLigne = NULL;
	eCol = NULL;

	tppTableau = new T* [];
}

template <typename T> CMatrice::CMatrice(int eLigne, int eCol, T ** tppValeurs) {
	eLigne = eLigne;
	eCol = eCol;
	tppTableau = tppValeurs;
}