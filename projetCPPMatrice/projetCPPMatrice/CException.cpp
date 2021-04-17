#include <stdio.h>
#include "CException.h"

// Construction
CException::CException() {
	eIndexError = 0;
}

// Methods
void CException::ExceptModifErrorType(int eError) {
	eIndexError = eError;
}

int CException::ExceptGetIndexError() {
	return eIndexError;
}