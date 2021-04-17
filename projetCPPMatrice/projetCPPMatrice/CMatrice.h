#ifndef CMatrice_h
#define CMatrice_h

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
		Probl�mes � identifier :	-) Le fichier n'existe pas
									-) Le fichier est vide
	*/
	~CMatrice();

	// Methods

	/* #####################
		Probl�mes g�n�raux :	-Les op�rateurs du type T doivent �tre surchag�s obligatoirement
	   ##################### */

	CMatrice<T> * multiply(int eVal) const throw();

	CMatrice<T> * divide(int eVal) const throw();

	CMatrice<T> * transpose();

	/*
		Probl�mes � identifier :	-) Les 2 matrices doivent �tre du m�me type
								-) Les matrices doivent �tre de m�me taille
	*/
	CMatrice<T> addMat(CMatrice<T> CMat);

	/*
		Probl�mes � identifier :	-) Les 2 matrices doivent �tre du m�me type
									-) Les matrices doivent �tre de m�me taille
	*/
	CMatrice<T> subMat(CMatrice<T> CMat);

	/*
		Probl�mes � identifier :	-) Les 2 matrices doivent �tre du m�me type
									-) Le nombre de colonnes de this doit �tre �gal au nombre
										de ligne de CMat
	*/
	CMatrice<T> multiplyMat(CMatrice<T> CMat);

	void display() const throw();

};

#endif // !CMatrice_h