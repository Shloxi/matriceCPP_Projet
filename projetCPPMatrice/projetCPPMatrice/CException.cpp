#include <stdio.h>
#include "CException.h"

// Construction
CException::CException() {
	eIndexError = 0;

	errors = new const char *[100];
	for (int i = 0; i < 100; ++i) {
		errors[i] = new char[100];
	}
	errors[1] = "Erreur : Le fichier est vide";
	errors[2] = "Erreur : Fichier inexistant";
	errors[3] = "Erreur : Le fichier indique un type de matrice non pris en charge";
	errors[4] = "Erreur : Le fichier possede une syntaxe non pris en charge";
	errors[5] = "Erreur : Le fichier indique un caractere de nombre de lignes incorrect";
	errors[6] = "Erreur : Le fichier indique un caractere de nombres de colonnes incorrect";
	errors[7] = "Erreur : Le fichier possede des données non prises en charge";
	errors[8] = "Erreur : Le fichier indique des dimensions non compatibles avec les donnees";
	errors[11] = "Erreur : Nombre de colonnes ou nombre de lignes nul";
	errors[12] = "Erreur : Tableau de donnees vide ou inexistant (null)";
	errors[51] = "Erreur : Les dimensions des matrices ne sont pas egales";
	errors[52] = "Erreur : Les dimensions des matrices ne sont pas compatibles pour cette operation";
}

CException::CException(int eError) {
	eIndexError = eError;

	errors = new const char *[100];
	for (int i = 0; i < 100; ++i) {
		errors[i] = new char[100];
	}
	errors[1] = "Erreur : Le fichier est vide";
	errors[2] = "Erreur : Fichier inexistant";
	errors[3] = "Erreur : Le fichier indique un type de matrice non pris en charge";
	errors[4] = "Erreur : Le fichier possede une syntaxe non pris en charge";
	errors[5] = "Erreur : Le fichier indique un caractere de nombre de lignes incorrect";
	errors[6] = "Erreur : Le fichier indique un caractere de nombres de colonnes incorrect";
	errors[7] = "Erreur : Le fichier possede des données non prises en charge";
	errors[8] = "Erreur : Le fichier indique des dimensions non compatibles avec les donnees";
	errors[11] = "Erreur : Nombre de colonnes ou nombre de lignes nul";
	errors[12] = "Erreur : Tableau de donnees vide ou inexistant (null)";
	errors[51] = "Erreur : Les dimensions des matrices ne sont pas egales";
	errors[52] = "Erreur : Les dimensions des matrices ne sont pas compatibles pour cette operation";
}

// Methods
void CException::ExceptModifErrorType(int eError) {
	eIndexError = eError;
}

int CException::ExceptGetIndexError() {
	return eIndexError;
}