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

int main()
{
    Matrix leo = newMatrix();
    set(&leo, 1, 2, 1);
    printf("%d", get(&leo, 1, 2));
    return 1;
}