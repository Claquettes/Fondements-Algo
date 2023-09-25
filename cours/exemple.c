#include <stdio.h>
#include <stdlib.h>

int* Fusion(int* A, int* B, int n1, int n2){
    int *c;
    //ON ALLOUR UN tableau de taille n1+n2 x la taille d'un int
    c = (int*)malloc((n1+n2)*sizeof(int));

    int i=0, j=0, k=0;
    //On parcourt les deux tableaux, on compare les valeurs et on les ajoute dans le tableau c
    while(i<n1 && j<n2){
        if(A[i]<B[j]){
            c[k]=A[i];
            i++;
        }
        else{
            c[k]=B[j];
            j++;
        }
        k++;
    }
    //une fois qu'un des deux tableaux est fini, on regarde lequel est fini et on ajoute le reste du tableau dans c
    if(i==n1){
        while(j<n2){
            c[k]=B[j];
            j++;
            k++;
        }
    }
    else{
        while(i<n1){
            c[k]=A[i];
            i++;
            k++;
        }
    }
    return c;
}

int main(){
    int A[5]={1,3,5,7,9};
    int B[5]={2,4,6,8,10};
    int *C;
    C = Fusion(A,B,5,5);
    for(int i=0; i<10; i++){
        printf("%d ", C[i]);
    }
    printf("\n");
    return 0;
}

