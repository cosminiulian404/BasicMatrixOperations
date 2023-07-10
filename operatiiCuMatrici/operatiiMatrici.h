#pragma once

float** transpusa(float** matrix, int n);
float determinant(float** matrix, int n);
float cofactor(float** matrix, int q, int p, int n);
float** adjuncta(float** matrix, int n);
float** invers(float** matrix, int n);
float** scaderea(float**, float**, int);

float** citire(float** matrix, int n);
void afisare(float** matrix, int n);

float** scadereMatrici(float**, float**, int);
float** adunareMatrici(float**, float**, int);

float** inmultireConstanta(float, float**, int);//inmultire cu o constanta;