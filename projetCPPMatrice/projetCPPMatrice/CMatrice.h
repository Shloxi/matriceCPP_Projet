#ifndef CMatrice_h
#define CMatrice_h

template <typename T> class CMatrice {

private:
	int eNbLigne;
	int eNbCol;
	T** tppTableau;

public:
	// Constructors
	CMatrice();
	CMatrice(int eLigne, eCol, T** tppValeurs);
	CMatrice(char * filename);
	~CMatrice();

	// Methods

};

#endif // !CMatrice_h