#ifndef CException_h
#define CException_h

#include <exception>
using namespace std;

class CException: public exception
{
	private :
		int eIndexError;
		char* msgErreur;

	public :
		// Constructors
		CException();
		CException(char * msg);
		virtual ~CException() throw();
		// Methods 
		virtual const char* what() const throw();
		void ExceptModifErrorType(int eErrorType);
		int ExceptGetIndexError();
};	

#endif // !CException_h
