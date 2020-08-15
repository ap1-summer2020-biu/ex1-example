#pragma once

#include <stdbool.h>
#include <stdint.h>

typedef enum {
<<<<<<< HEAD
	// DON'T CHANGE THIS VALUE!
	ERROR_SUCCESS = 0,
	ERROR_HEAP_MEMORY,
	ERROR_NULL_POINTER,
	ERROR_UNMATCHING_SIZES,
=======
    // DON'T CHANGE THIS VALUE!
    ERROR_SUCCESS = 0,

>>>>>>> aee745b52d52ae6154f8bd82e5c95bb93675b207
    ERROR_NOT_IMPLEMENTED = 0x1000,
} ErrorCode;

/**
 * @brief Checks if a given error code indicates a success or not.
 *
 * @param[in] code the error code.
 * @return whether the error code indicates a success or not.
 */
bool error_isSuccess(ErrorCode code);

/**
 * @brief gets a textual error message for a given error code.
 *
 * @param[in] code the error code.
 * @return const char* the textual representation of the error code.
 */
const char* error_getErrorMessage(ErrorCode code);