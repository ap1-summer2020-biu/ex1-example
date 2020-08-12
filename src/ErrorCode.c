#include"ErrorCode.h"
#include<stddef.h>

bool error_isSuccess(ErrorCode code) {
	return code == ERROR_SUCCESS;
}

const char* error_getErrorMessage(ErrorCode code) {
	switch (code) {
		case ERROR_SUCCESS: return "ERROR_SUCCESS";
		case ERROR_FAILURE: return "ERROR_FAILURE";
		case ERROR_NO_MEMORY: return "ERROR_NO_MEMORY";
		case ERROR_MATRIX_SIZE: return "ERROR_MATRIX_SIZE";
		//should never happen:
		default: return NULL;
	}
}
