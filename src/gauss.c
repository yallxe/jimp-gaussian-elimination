#include "gauss.h"

/**
 * Zwraca 0 - eliminacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b)
{
    if (!mat || !b || !mat->data || !b->data)
        return 1;
    
    double m;
    for (int i = 0; i < mat->r; i++)
    {
        if (mat->data[i][i] == 0)
            return 1;

        for (int j = i + 1; j < mat->r; j++)
        {
            if (mat->data[j][i] != 0)
            {
                m = mat->data[j][i] / mat->data[i][i];
                for (int k = i; k < mat->c; k++)
                {
                    mat->data[j][k] -= m * mat->data[i][k];
                }

                if (j < b->r && b->data[j])
                {
                    b->data[j][0] -= m * b->data[i][0];
                }
                else
                {
                    return 1; 
                }
            }
        }
    }

    return 0;
}
