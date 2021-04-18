#ifndef CMatrice_h
#define CMatrice_h
using namespace std;

// Constantes d'erreurs liees a la creation de matrice via fichier
#define CMatriceEmptyFile 1
#define CMatriceFileNotExist 2
#define CMatriceWrongTypeFile 3
#define CMatriceWrongSyntax 4
#define CMatriceWrongLine 5
#define CMatriceWrongCol 6
#define CMatriceDataError 7
#define CMatriceGlobalError 8

// Constantes d'erreurs liees aux attributs
#define CMatriceNullAttributes 11
#define CMatriceEmptyDataTab 12


template <typename T> class CMatrice {

private:
	int eNbLigne; // Nombre de lignes
	int eNbCol; // Nombre de colonnes
	T ** tppTableau; // Structure de la matrice

public:
	// Constructors
	CMatrice(); // Par défaut
	CMatrice(int eLigne, int eCol);
	CMatrice(int eLigne, int eCol, T ** tppValeurs);
	CMatrice(const CMatrice<T>& m); // Par recopie
	/*
	Problèmes à identifier :	-) Le fichier n'existe pas
								-) Le fichier est vide
	*/
	CMatrice(const char * filename) throw();
	~CMatrice(); // Destructeur

	//Accesseurs
	int getNbLigne();
	int getNbCol();
	T ** getMatrice();

	// Methods

	// Utilisé par la surcharge <<
	ostream& display(ostream & os) const throw();

	// Surcharge par int
	CMatrice<T> & operator*(int const c);
	CMatrice<T> & operator/(int const c);

	// Surcharge par CMatrice
	CMatrice<T> & operator+(CMatrice<T> const M);
	CMatrice<T> & operator-(CMatrice<T> const M);
	CMatrice<T> & operator*(CMatrice<T> const M);
};

// Surcharge pour afficher
template <typename T> ostream& operator<<(ostream& os, CMatrice<T> const M);

#endif // !CMatrice_h
