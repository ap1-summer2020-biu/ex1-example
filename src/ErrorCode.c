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
}