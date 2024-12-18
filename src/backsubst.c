#include "backsubst.h"
#include <stdio.h>
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int backsubst(Matrix *x, Matrix *A, Matrix *b)
{
	if (A->r != A->c || x->r != A->c || x->r != b->r)
		return 2;
	if (A->data[A->r - 1][A->r - 1] == 0)
		return 1;

	x->data[A->r - 1][0] = b->data[A->r - 1][0] / A->data[A->r - 1][A->r - 1];

	for (int r = A->r - 2; r >= 0; r--)
	{
		for (int c = A->r - 1; c > r; c--)
		{

			b->data[r][0] -= A->data[r][c] * x->data[c][0];

			A->data[r][c] = 0;
		}

		x->data[r][0] = b->data[r][0] / A->data[r][r];
		if (A->data[r][r] == 0)
			return 1;
	}

	return 0;
}
