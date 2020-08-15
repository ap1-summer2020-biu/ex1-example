#include"Matrix.h"
#include<stdlib.h>
#include<stddef.h>

typedef struct Matrix {
	uint32_t rows, cols;
	double* data;
} Matrix;


ErrorCode matrix_create(PMatrix* matrix, uint32_t height, uint32_t width) {
	*matrix = malloc(sizeof(Matrix));
	if (matrix == NULL) { return ERROR_NO_MEMORY; }
	(*matrix)->rows = height;
	(*matrix)->cols = width;
	(*matrix)->data = malloc(sizeof(double) * height * width);
	if ((*matrix)->data == NULL) {
		free(*matrix);
		return ERROR_NO_MEMORY;
	}
	return ERROR_SUCCESS;
}

ErrorCode matrix_copy(PMatrix* result, CPMatrix source) {
	ErrorCode err = matrix_create(result, source->rows, source->cols);
	if (!error_isSuccess(err)) {
		return err;
	}

	for (uint32_t i = 0; i < source->rows; ++i) {
	for (uint32_t j = 0; j < source->cols; ++j) {
		double temp;
		matrix_getValue(source, i, j, &temp);
		matrix_setValue(*result, i, j, temp);
	}
	}

	return ERROR_SUCCESS;
}

void matrix_destroy(PMatrix matrix) {
	free(matrix->data);
	free(matrix);
}

ErrorCode matrix_getHeight(CPMatrix matrix, uint32_t* result) {
	*result = matrix->rows;
	return ERROR_SUCCESS;
}

ErrorCode matrix_getWidth(CPMatrix matrix, uint32_t* result) {
	*result = matrix->cols;
	return ERROR_SUCCESS;
}

ErrorCode matrix_setValue(PMatrix matrix, uint32_t rowIndex, uint32_t colIndex,
                          double value) {

	matrix->data[rowIndex * matrix->cols + colIndex] = value;
	return ERROR_SUCCESS;
}

ErrorCode matrix_getValue(CPMatrix matrix, uint32_t rowIndex, uint32_t colIndex,
                          double* value) {

	*value = matrix->data[rowIndex * matrix->cols + colIndex];
	return ERROR_SUCCESS;
}

ErrorCode matrix_add(PMatrix* result, CPMatrix lhs, CPMatrix rhs) {
	if (lhs->rows != rhs->rows || lhs->cols != rhs->cols) {
		return ERROR_MATRIX_SIZE;
	}

	ErrorCode err = matrix_create(result, lhs->rows, rhs->cols);
	if (!error_isSuccess(err)) {
		return err;
	}

	for (uint32_t i = 0; i < lhs->rows; ++i) {
	for (uint32_t j = 0; j < lhs->cols; ++j) {
		double temp1;
		matrix_getValue(lhs, i, j, &temp1);
		double temp2;
		matrix_getValue(rhs, i, j, &temp2);
		matrix_setValue(*result, i, j, temp1 + temp2);
	}
	}

	return ERROR_SUCCESS;
}

ErrorCode matrix_multiplyMatrices(PMatrix* result, CPMatrix lhs, CPMatrix rhs) {
	ErrorCode err = matrix_create(result, lhs->rows, rhs->cols);
	if (!error_isSuccess(err)) {
		return err;
	}

	for (uint32_t i = 0; i < lhs->rows; ++i) {
	for (uint32_t j = 0; j < rhs->cols; ++j) {
		double innerMult = 0;
		for (uint32_t it = 0; it < lhs->cols; ++it) {
			double lv, rv;
			matrix_getValue(lhs, i, it, &lv);
			matrix_getValue(rhs, it, j, &rv);
			innerMult += lv * rv;
		}
		matrix_setValue(*result, i, j, innerMult);
	}
	}

	return ERROR_SUCCESS;
}

ErrorCode matrix_multiplyWithScalar(PMatrix matrix, double scalar) {
	for (uint32_t i = 0; i < matrix->rows; ++i) {
	for (uint32_t j = 0; j < matrix->cols; ++j) {
		double temp;
		matrix_getValue(matrix, i, j, &temp);
		temp *= scalar;
		matrix_setValue(matrix, i, j, temp);
	}
	}

	return ERROR_SUCCESS;
}
