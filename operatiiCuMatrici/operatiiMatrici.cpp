#include <iostream>
#include <math.h>
#include "operatiiMatrici.h"
using namespace std;

float** citire(float** matrix, int n)
{
	int i, j;

	cout << "Introduceti elementele matricii: " << endl;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cout << "matrix[" << i << "]" << "[" << j << "]="; cin >> matrix[i][j];
		}
	}
	return matrix;
}
void afisare(float** matrix, int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
}

float** transpusa(float** matrix, int n)
{
	int i, j;
	float** transpusa_matrice;
	transpusa_matrice = new float* [n];
	for (i = 0; i < n; i++) transpusa_matrice[i] = new float[n];
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			transpusa_matrice[j][i] = matrix[i][j];


		}
	}

	return transpusa_matrice;

	for (int i = 0; i < n; i++) // dealocarea memoriei
		delete[] transpusa_matrice[i];
	delete[] transpusa_matrice;
}


float determinant(float** matrix, int n)
{
	int i, j, x;
	int subi, subj;
	float det = 0;
	float** submatrix;
	submatrix = new float* [n - 1];
	for (i = 0; i < n; i++) submatrix[i] = new float[n - 1];

	if (n == 2)
		return ((matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]));
	else {
		for (x = 0; x < n; x++) {
			subi = 0;
			for (i = 1; i < n; i++) {
				subj = 0;
				for (j = 0; j < n; j++) {
					if (j == x)
						continue;
					submatrix[subi][subj] = matrix[i][j];
					subj++;
				}
				subi++;
			}
			det = det + (pow(-1.0, x) * matrix[0][x] * determinant(submatrix, n - 1));
		}
	}

	return det;
	for (i = 0; i < n; i++) // dealocarea memoriei
		delete[] submatrix[i];
	delete[] submatrix;
}

float cofactor(float** matrix, int q, int p, int n)
{
	float** cofactor_matrice;
	int i, j, lin = 0, col = 0;
	cofactor_matrice = new float* [n - 1];
	for (i = 0; i < n - 1; i++) cofactor_matrice[i] = new float[n - 1];//alocare memorie

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			if (i != p && j != q)
			{
				cofactor_matrice[lin][col++] = matrix[i][j];
				if (col == n - 1)
				{
					col = 0;
					lin++;
				}
			}
	}


	return determinant(cofactor_matrice, n - 1);

	for (i = 0; i < n - 1; i++) // dealocarea memoriei
		delete[] cofactor_matrice[i];
	delete[] cofactor_matrice;
}


float** adjuncta(float** matrix, int n)
{
	int i, j;
	float** adjuncta_matrice;
	adjuncta_matrice = new float* [n];
	for (i = 0; i < n; i++) adjuncta_matrice[i] = new float[n];
	float** temporar;
	temporar = new float* [n];
	for (i = 0; i < n; i++) temporar[i] = new float[n];

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			adjuncta_matrice[i][j] = pow(-1, i + j) * cofactor(matrix, i, j, n);

	}
	return adjuncta_matrice;

	for (int i = 0; i < n; i++) // dealocarea memoriei
		delete[] adjuncta_matrice[i];
	delete[] adjuncta_matrice;
}


float** invers(float** matrix, int n)
{
	int i, j;
	float** inversa_matrice;
	inversa_matrice = new float* [n];
	for (i = 0; i < n; i++) inversa_matrice[i] = new float[n];

	float det = determinant(matrix, n);
	inversa_matrice = adjuncta(matrix, n);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			inversa_matrice[i][j] = inversa_matrice[i][j] / ((float)det);
	}
	return inversa_matrice;
	for (i = 0; i < n; i++) // dealocarea memoriei
		delete[] inversa_matrice[i];
	delete[] inversa_matrice;
}


float** scadereMatrici(float** matrixA, float** matrixB, int n)
{
	int i, j;
	float** scaderea;
	scaderea = new float* [n];
	for (i = 0; i < n; i++) scaderea[i] = new float[n];

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			scaderea[i][j] = matrixA[i][j] - matrixB[i][j];
		}
	}
	return scaderea;
	for (i = 0; i < n; i++) // dealocarea memoriei
		delete[] scaderea[i];
	delete[] scaderea;
}

float** adunareMatrici(float** matrixA, float** matrixB, int n)
{
	int i, j;
	float** adunare;
	adunare = new float* [n];
	for (i = 0; i < n; i++) adunare[i] = new float[n];

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			adunare[i][j] = matrixA[i][j] + matrixB[i][j];
		}
	}
	return adunare;
	for (i = 0; i < n; i++) // dealocarea memoriei
		delete[] adunare[i];
	delete[] adunare;
}

float** inmultireConstanta(float constanta, float** matrix, int n)
{
	int i, j;
	float** inmultire = nullptr;
	inmultire = new float* [n];
	for (i = 0; i < n; i++) inmultire[i] = new float[n];

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			inmultire[i][j] = constanta * matrix[i][j];
		}
	}
	return inmultire;
	for (i = 0; i < n; i++)
		delete[]inmultire[i];
	delete[] inmultire;
}