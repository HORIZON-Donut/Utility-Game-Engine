#ifndef DATASTRUCTURE_H
#define DATASTRUCTURE_H

float* Array1D(int size);
float** Array2D(int row, int col);
float*** Array3D(int row, int col, int dep);

float* Resize1D(float* arr, size_t n);
float** Resize2D(float** arr, size_t n1, size_t n2);
float*** Resize3D(float*** arr, size_t n1, size_t n2, size_t n3);

#endif
