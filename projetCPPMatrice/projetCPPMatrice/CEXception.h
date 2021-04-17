#ifndef CException_h
#define CException_h

class CException
{
private:
	int eIndexError;

public:
	// Constructors
	CException();
	// Methods 
	void ExceptModifErrorType(int eErrorType);
	int ExceptGetIndexError();
};

#endif // !CException_h
