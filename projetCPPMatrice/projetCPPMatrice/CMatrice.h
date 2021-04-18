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


// Constantes d'erreurs liees au calculs
#define CMatriceNotSameSize 51
#define CMatriceNotCompatibleSize 52



template <typename T> class CMatrice {

private:
	int eNbLigne;
	int eNbCol;
	T ** tppTableau;

public:
	// Constructors
	CMatrice();
	CMatrice(int eLigne, int eCol);
	CMatrice(int eLigne, int eCol, T ** tppValeurs);
	CMatrice(const CMatrice<T>& m);

	/*
	Problèmes à identifier :	-) Le fichier n'existe pas
								-) Le fichier est vide
	*/
	CMatrice(const char * filename) throw();

	~CMatrice();

	// Methods

	/* #####################
		Problèmes généraux :	-Les opérateurs du type T doivent être surchagés obligatoirement
	   ##################### */

	CMatrice<T> * multiply(int eVal) const throw();

	CMatrice<T> * divide(int eVal) const throw();

	CMatrice<T> * transpose();

	/*
		Problèmes à identifier :	-) Les 2 matrices doivent être du même type
								    -) Les matrices doivent être de même taille
	*/
	CMatrice<T> * addMat(CMatrice<T> CMat) const throw();

	/*
		Problèmes à identifier :	-) Les 2 matrices doivent être du même type
									-) Les matrices doivent être de même taille
	*/
	CMatrice<T> * subMat(CMatrice<T> CMat) const throw();

	/*
		Problèmes à identifier :	-) Les 2 matrices doivent être du même type
									-) Le nombre de colonnes de this doit être égal au nombre
										de ligne de CMat
	*/
	CMatrice<T> * multiplyMat(CMatrice<T> CMat) const throw();

	ostream& display(ostream & os) const throw();

	CMatrice<T> & operator*(int const c);

	CMatrice<T> & operator/(int const c);

	CMatrice<T> & operator+(CMatrice<T> const M);

	CMatrice<T> & operator-(CMatrice<T> const M);

	CMatrice<T> & operator*(CMatrice<T> const M);
};

template <typename T> ostream& operator<<(ostream& os, CMatrice<T> const M);

#endif // !CMatrice_h
