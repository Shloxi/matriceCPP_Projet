#ifndef CException_h
#define CException_h

class CException
{
private:
	int eIndexError;

public:
	// Constructors
	CException();
	CException(int eError);
	// Methods 
	void ExceptModifErrorType(int eErrorType);
	int ExceptGetIndexError();
};

#endif // !CException_h
