#ifndef CMatrice_h
#define CMatrice_h
using namespace std;

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
	CMatrice(const char * filename) throw();
	/*
		Problèmes à identifier :	-) Le fichier n'existe pas
									-) Le fichier est vide
	*/
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
