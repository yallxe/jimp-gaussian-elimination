#include "gauss.h"
#include "backsubst.h"
#include "mat_io.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	int res;
	Matrix *A = readFromFile(argv[1]);
	Matrix *b = readFromFile(argv[2]);
	Matrix *x;

	if (A == NULL)
		return -1;
	if (b == NULL)
		return -2;
	printToScreen(A);
	printToScreen(b);

	res = eliminate(A, b);

	if (res)
	{
		fprintf(stderr, "macierz osobliwa - dzielenie przez 0.\n");
		return 1;
	}

	x = createMatrix(b->r, 1);
	printToScreen(A);
	printToScreen(b);

	if (x != NULL)
	{
		res = backsubst(x, A, b);

		switch (res)
		{
		case 1:
			fprintf(stderr, "Błąd! Dzielenie przez 0. Macierz nie może zawierać elementów zerowych.\n");
			return 1;
		case 2:
			fprintf(stderr, "Błąd! Nieprawidłowy rozmiar macierzy.\n");
			return 2;
		default:
			break;
		}

		printToScreen(x);
		freeMatrix(x);
	}
	else
	{
		fprintf(stderr, "Błąd! Nie mogłem utworzyć wektora wynikowego x.\n");
	}

	freeMatrix(A);
	freeMatrix(b);

	return 0;
}
