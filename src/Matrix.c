#include "Matrix.h"

struct Matrix {
    void* impl;
    // Empty implementation
};

ErrorCode matrix_create(PMatrix* matrix, uint32_t height, uint32_t width) {
    (void)matrix;
    (void)height;
    (void)width;
    return ERROR_NOT_IMPLEMENTED;
}

ErrorCode matrix_copy(PMatrix* result, CPMatrix source) {
    (void)result;
    (void)source;
    return ERROR_NOT_IMPLEMENTED;
}

void matrix_destroy(PMatrix matrix) { (void)matrix; }

ErrorCode matrix_getHeight(CPMatrix matrix, uint32_t* result) {
    (void)matrix;
    (void)result;
    return ERROR_NOT_IMPLEMENTED;
}

ErrorCode matrix_getWidth(CPMatrix matrix, uint32_t* result) {
    (void)matrix;
    (void)result;
    return ERROR_NOT_IMPLEMENTED;
}

ErrorCode matrix_setValue(PMatrix matrix, uint32_t rowIndex, uint32_t colIndex,
                          double value) {
    (void)matrix;
    (void)rowIndex;
    (void)colIndex;
    (void)value;
    return ERROR_NOT_IMPLEMENTED;
}

ErrorCode matrix_getValue(CPMatrix matrix, uint32_t rowIndex, uint32_t colIndex,
                          double* value) {
    (void)matrix;
    (void)rowIndex;
    (void)colIndex;
    (void)value;
    return ERROR_NOT_IMPLEMENTED;
}

ErrorCode matrix_add(PMatrix* result, CPMatrix lhs, CPMatrix rhs) {
    (void)result;
    (void)lhs;
    (void)rhs;
    return ERROR_NOT_IMPLEMENTED;
}

ErrorCode matrix_multiplyMatrices(PMatrix* result, CPMatrix lhs, CPMatrix rhs) {
    (void)result;
    (void)lhs;
    (void)rhs;
    return ERROR_NOT_IMPLEMENTED;
}

ErrorCode matrix_multiplyWithScalar(PMatrix matrix, double scalar) {
    (void)matrix;
    (void)scalar;
    return ERROR_NOT_IMPLEMENTED;
}