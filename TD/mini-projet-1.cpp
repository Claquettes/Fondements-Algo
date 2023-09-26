#include <stdio.h>
#include <stdlib.h>

// we define the constant MAX_TAILLE
#define MAX_TAILLE 100

typedef struct
{
    int tab[MAX_TAILLE];
    unsigned int nbLignes;
    unsigned int nbColonnes;
} Matrix;

Matrix newMatrix()
{
    Matrix mat;
    int nbLignes = 0;
    int nbColonnes = 0;

    printf("Entrez le nombre de lignes : ");
    scanf("%d", &nbLignes);
    printf("Entrez le nombre de colonnes : ");
    scanf("%d", &nbColonnes);

    if (nbColonnes * nbLignes > MAX_TAILLE)
    {
        printf("Erreur : la matrice est trop grande");
        nbColonnes = 0;
        nbLignes = 0;
    }
    else
    {
        mat.nbLignes = nbLignes;
        mat.nbColonnes = nbColonnes;
    }

    return mat;
}

int set(Matrix *M, int i, int j, int val)
{
    if (i < 0 || i >= M->nbLignes || j < 0 || j >= M->nbColonnes)
    {
        printf("Erreur : les indices sont hors limites");
        return 0;
    }
    else
    {
        // on accède à la case i,j de la matrice, sauf que vu que la matrice est un tableau à une dimension, on doit faire i*nbColonnes + j
        M->tab[i * M->nbColonnes + j] = val;
        return 1;
    }
}

int get(Matrix *M, int i, int j)
{
    if (i < 0 || i >= M->nbLignes || j < 0 || j >= M->nbColonnes)
    {
        printf("Erreur : les indices sont hors limites");
        return 0;
    }
    else
    {
        // on accède à la case i,j de la matrice, sauf que vu que la matrice est un tableau à une dimension, on doit faire i*nbColonnes + j
        return M->tab[i * M->nbColonnes + j];
    }
}

int Diag(Matrix *M)
{
    // on vérifie si le nombre de lignes est égal au nombre de colonnes, car une matrice diagonale doit être carrée
    if (M->nbLignes != M->nbColonnes)
    {
        printf("Erreur : la matrice n'est pas carrée");
        return 0;
    }
    else
    {
        // on parcourt la matrice
        for (int i = 0; i < M->nbLignes; i++)
        {
            for (int j = 0; j < M->nbColonnes; j++)
            {
                // si on est sur la diagonale, on vérifie que la valeur est différente de 0
                if (i == j && get(M, i, j) != 0)
                {
                    return 0;
                }
                else if (i != j && get(M, i, j) == 0)
                {
                    return 0;
                }
            }
        }
        return 1;
    }
}

int Symmetric(Matrix *M)
{
    printf("BONJOUR SYMMETRIQUE OU PAS CHEF");
    return 1;
}

void putValuesToMakeDiag(Matrix *M)
{
    for (int i = 0; i < M->nbLignes; i++)
    {
        for (int j = 0; j < M->nbColonnes; j++)
        {
            if (i == j)
            {
                set(M, i, j, 0);
            }
            else
            {
                set(M, i, j, 1);
            }
        }
    }
}

int main()
{
    Matrix leo = newMatrix();
    putValuesToMakeDiag(&leo);

    int isDiag = Diag(&leo);
    printf("\n");
    if (isDiag == 1)
    {
        printf("La matrice est diagonale");
    }
    else
    {
        printf("La matrice n'est pas diagonale");
    }
    printf("\n");
    int isSym = Symmetric(&leo);
    printf("\n");
    printf("%d", get(&leo, 1, 2));
    return 1;
}