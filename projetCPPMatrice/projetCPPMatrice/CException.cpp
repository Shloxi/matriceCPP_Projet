#include <stdio.h>
#include "CException.h"

// Construction
CException::CException() {
	eIndexError = 0;
}

CException::CException(char * msg) {
	eIndexError = 0;
	msgErreur = (char *)malloc(100 * sizeof(char*));
	msgErreur = msg;
}

CException::~CException() throw()
{
	free(msgErreur);
}

// Methods

const char * CException::what() const throw()
{
	return msgErreur;
}

void CException::ExceptModifErrorType(int eError) {
	eIndexError = eError;
}

int CException::ExceptGetIndexError() {
	return eIndexError;
}