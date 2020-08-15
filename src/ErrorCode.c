<<<<<<< HEAD
#include <stdbool.h>
#include "ErrorCode.h"

bool error_isSuccess(ErrorCode code) {
	return code == ERROR_SUCCESS;
}

const char* error_getErrorMessage(ErrorCode code) {
	if (code == ERROR_NOT_IMPLEMENTED) {
		return "Not implemented";
	}
	else if (code == ERROR_HEAP_MEMORY) {
		return "Heap memory error";
	}
	else if (code == ERROR_NULL_POINTER) {
		return "Null pointer error";
	}
	else if (code == ERROR_UNMATCHING_SIZES) {
		return "Matrix sizes don't match";
	}
	else {
		return "Success";
	}
=======
#include "ErrorCode.h"

bool error_isSuccess(const ErrorCode code) { return code == ERROR_SUCCESS; }

const char* error_getErrorMessage(const ErrorCode code) {
    switch (code) {
        case ERROR_SUCCESS:
            return "The operation completed successfully";
        case ERROR_NOT_IMPLEMENTED:
            return "The procedure was not implemented";
        default:
            return "Unexpected error";
    }
>>>>>>> aee745b52d52ae6154f8bd82e5c95bb93675b207
}