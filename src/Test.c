#include<stdio.h>

#include"ErrorCode.h"
#include"Matrix.h"

void matrix_print(CPMatrix matrix) {
	printf("\n");
	uint32_t height, width;
	matrix_getHeight(matrix, &height);
	matrix_getWidth(matrix, &width);
	for (uint32_t i = 0; i < height; i++) {
		for (uint32_t j = 0; j < width; j++) {
			double temp;
			matrix_getValue(matrix, i, j, &temp);
			printf("%f\t", temp);
		}
		printf("\n");
	}
	printf("\n");
}

PMatrix matrix_createWithValues() {
	PMatrix matrix;
	uint32_t width, height;
	printf("enter matrix width: ");
	scanf("%u", &width);
	printf("enter matrix height: ");
	scanf("%u", &height);
	printf("%s\n", error_getErrorMessage(matrix_create(&matrix, height, width)));
	for (uint32_t i = 0; i < height; i++) {
		for (uint32_t j = 0; j < width; j++) {
			double value;
			printf("enter element %d %d: ", j, i);
			scanf("%lf", &value);
			printf("%s\n", error_getErrorMessage(matrix_setValue(matrix, i, j, value)));
		}
	}
	matrix_print(matrix);
	return matrix;
}

int main() {
	PMatrix mat  = matrix_createWithValues();
	PMatrix mat2 = matrix_createWithValues();

	printf("addition:\n");
	PMatrix addition;
	matrix_add(&addition, mat, mat2);
	matrix_print(addition);

	printf("multiplication:\n");
	PMatrix mult;
	matrix_multiplyMatrices(&mult, mat, mat2);
	matrix_print(mult);

	printf("multiplication with scalar:\n");
	matrix_multiplyWithScalar(mat, 3);
	matrix_print(mat);

	matrix_destroy(mat);
	matrix_destroy(mat2);
}
