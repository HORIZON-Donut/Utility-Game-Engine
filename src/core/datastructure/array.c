#include "datastructure.h"

float* Array1D(int size)
{
	float* arr = (float*)malloc(size);
	return arr;
}

float** Array2D();
float*** Array3D();

float* Resize1D(float* arr, size_t n);
float** Resize2D(float** arr, size_t n1, size_t n2);
float*** Resize3D(float*** arr, size_t n1, size_t n2, size_t n3);
