#include <iostream>
#include "operatiiMatrici.h"

using namespace std;


int main()
{
	int i, n;
	float** matriceaA, ** matriceaB, ** matriceAdunare;
	cout << "introduceti rangul matricii:"; cin >> n;
	matriceaA = new float* [n];
	for (i = 0; i < n; i++) matriceaA[i] = new float[n];
	matriceaB = new float* [n];
	for (i = 0; i < n; i++) matriceaB[i] = new float[n];
	matriceAdunare = new float* [n];
	for (i = 0; i < n; i++) matriceAdunare[i] = new float[n];


	citire(matriceaA, n);
	afisare(matriceaA, n);
	cout << endl;
	citire(matriceaB, n);
	afisare(matriceaB, n);
	cout << endl;
	matriceAdunare = adunareMatrici(matriceaA, matriceaB, n);
	afisare(matriceAdunare, n);

	for (i = 0; i < n; i++) // dealocarea memoriei
		delete[] matriceaA[i];
	delete[] matriceaA;
	for (i = 0; i < n; i++) // dealocarea memoriei
		delete[] matriceaB[i];
	delete[] matriceaB;
	for (i = 0; i < n; i++) // dealocarea memoriei
		delete[] matriceAdunare[i];
	delete[] matriceAdunare;
	return 0;
}

