#include "backsubst.h"
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int backsubst(Matrix *x, Matrix *A, Matrix *b)
{
	x->data[A->r][0] = b->data[A->r][0] / A->data[A->r][A->r];
	for (int r = A->r - 1; r >= 0; r--)
	{
		for (int c = A->r; c > r; c--)
		{
			b->data[r][0] -= A->data[r][c] * x->data[c][0];
			A->data[r][c] = 0;
		}
		x->data[r][0] = b->data[r][0] / A->data[r][r];
	}

	return 0;
}
