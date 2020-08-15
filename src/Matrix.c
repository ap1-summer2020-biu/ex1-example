#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>
#include "Matrix.h"
#include "ErrorCode.h"

struct Matrix {
	uint32_t height;
	uint32_t width;

	//vals is the array of the rows of the matrix, and each row is an array of doubles
	double** vals;
};

ErrorCode matrix_create(PMatrix* matrix, uint32_t height, uint32_t width) {
	if (matrix == NULL) {
		return ERROR_NULL_POINTER;
	}

	//Allocating the matrix and its fields
	*matrix = malloc(sizeof(struct Matrix));
	if (*matrix == NULL) {
		return ERROR_HEAP_MEMORY;
	}
	(*matrix)->height = height;
	(*matrix)->width = width;

	//Allocating the values of the matrix
	(*matrix)->vals = malloc(sizeof(double*) * height);
	if ((*matrix)->vals == NULL) {
		return ERROR_HEAP_MEMORY;
	}

	for (int i = 0; i < height; i++) {
		((*matrix)->vals)[i] = malloc(sizeof(double) * width);
		if (((*matrix)->vals)[i] == NULL) {
			return ERROR_HEAP_MEMORY;
		}
		
		//Initializing all the matrix values to be 0
		for (int j = 0; j < width; j++) {
			matrix_setValue(*matrix, i, j, 0);
		}
	}

	return ERROR_SUCCESS;
}

ErrorCode matrix_copy(PMatrix* result, CPMatrix source) {
	if (result == NULL || source == NULL) {
		return ERROR_NULL_POINTER;
	}

	//Creating the result matrix
	uint32_t height = 0, width = 0;
	matrix_getHeight(source, &height);
	matrix_getWidth(source, &width);
	ErrorCode createEC = matrix_create(result, height, width);
	if (!error_isSuccess(createEC)) {
		return createEC;
	}
	
	//Copying the values of source to result
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			double val = 0;
			matrix_getValue(source, i, j, &val);
			matrix_setValue(*result, i, j, val);
		}
	}

	return ERROR_SUCCESS;
}

void matrix_destroy(PMatrix matrix) {
	if (matrix == NULL) {
		return;
	}

	//Freeing the rows of the matrix
	uint32_t height = 0;
	matrix_getHeight(matrix, &height);
	for (int i = 0; i < height; i++) {
		free((matrix->vals)[i]);
	}

	//Freeing the dynamically allocated fields of the matrix and the matrix itself
	free(matrix->vals);
	free(matrix);
}

ErrorCode matrix_getHeight(CPMatrix matrix, uint32_t* result) {
	if (matrix == NULL || result == NULL) {
		return ERROR_NULL_POINTER;
	}

	*result = matrix->height;
	return ERROR_SUCCESS;
}

ErrorCode matrix_getWidth(CPMatrix matrix, uint32_t* result) {
	if (matrix == NULL || result == NULL) {
		return ERROR_NULL_POINTER;
	}

	*result = matrix->width;
	return ERROR_SUCCESS;
}

ErrorCode matrix_setValue(PMatrix matrix, uint32_t rowIndex, uint32_t colIndex,
	double value) {
	if (matrix == NULL) {
		return ERROR_NULL_POINTER;
	}

	(matrix->vals)[rowIndex][colIndex] = value;
	return ERROR_SUCCESS;
}

ErrorCode matrix_getValue(CPMatrix matrix, uint32_t rowIndex, uint32_t colIndex,
	double* value) {
	if (matrix == NULL || value == NULL) {
		return ERROR_NULL_POINTER;
	}

	*value = (matrix->vals)[rowIndex][colIndex];
	return ERROR_SUCCESS;

}

ErrorCode matrix_add(PMatrix* result, CPMatrix lhs, CPMatrix rhs) {
	if (result == NULL || lhs == NULL || rhs == NULL) {
		return ERROR_NULL_POINTER;
	}

	//Checking if lhs and rhs have the same height and width
	uint32_t lhsHeight = 0, lhsWidth = 0;
	matrix_getHeight(lhs, &lhsHeight);
	matrix_getWidth(lhs, &lhsWidth);

	uint32_t rhsHeight = 0, rhsWidth = 0;
	matrix_getHeight(rhs, &rhsHeight);
	matrix_getWidth(rhs, &rhsWidth);

	if (lhsHeight != rhsHeight || lhsWidth != rhsWidth) {
		return ERROR_UNMATCHING_SIZES;
	}

	//Creating the result matrix
	uint32_t height = lhsHeight, width = lhsWidth;
	ErrorCode createEC = matrix_create(result, height, width);
	if (!error_isSuccess(createEC)) {
		return createEC;
	}

	//Changing all the values of result to be the sum of the matching values of lhs and rhs
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			double lhsVal = 0, rhsVal = 0;
			matrix_getValue(lhs, i, j, &lhsVal);
			matrix_getValue(rhs, i, j, &rhsVal);
			matrix_setValue(*result, i, j, lhsVal + rhsVal);
		}
	}

	return ERROR_SUCCESS;
}

ErrorCode matrix_multiplyMatrices(PMatrix* result, CPMatrix lhs, CPMatrix rhs) {
	if (result == NULL || lhs == NULL || rhs == NULL) {
		return ERROR_NULL_POINTER;
	}

	//Checking if the width of lhs equals to the height of rhs
	uint32_t lhsHeight = 0, lhsWidth = 0;
	matrix_getHeight(lhs, &lhsHeight);
	matrix_getWidth(lhs, &lhsWidth);

	uint32_t rhsHeight = 0, rhsWidth = 0;
	matrix_getHeight(rhs, &rhsHeight);
	matrix_getWidth(rhs, &rhsWidth);

	if (lhsWidth != rhsHeight) {
		return ERROR_UNMATCHING_SIZES;
	}

	//Creating the result matrix
	ErrorCode createEC = matrix_create(result, lhsHeight, rhsWidth);
	if (!error_isSuccess(createEC)) {
		return createEC;
	}

	//Changing every i, j value of result to be the dot product
	//of the i row of lhs with the j column of rhs
	int multlen = lhsWidth;

	for (int i = 0; i < lhsHeight; i++) {
		for (int j = 0; j < rhsWidth; j++) {
			double sum = 0;
			for (int k = 0; k < multlen; k++) {
				double lhsVal = 0, rhsVal = 0;
				matrix_getValue(lhs, i, k, &lhsVal);
				matrix_getValue(rhs, k, j, &rhsVal);
				sum += lhsVal * rhsVal;
			}
			matrix_setValue(*result, i, j, sum);
		}
	}

	return ERROR_SUCCESS;
}

ErrorCode matrix_multiplyWithScalar(PMatrix matrix, double scalar) {
	if (matrix == NULL) {
		return ERROR_NULL_POINTER;
	}

	//Getting the height and the width
	uint32_t height = 0, width = 0;
	matrix_getHeight(matrix, &height);
	matrix_getWidth(matrix, &width);

	//Multiplying all the values of result with scalar
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			double val = 0;
			matrix_getValue(matrix, i, j, &val);
			matrix_setValue(matrix, i, j, val * scalar);
		}
	}

	return ERROR_SUCCESS;
}