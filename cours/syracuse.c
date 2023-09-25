#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    printf("Entrez un nombre : ");
    scanf("%d", &n);

    unsigned int tempsDeVol=0;
    int altMax=n;

    while(n!=1){
        if(n%2==0){
            n=n/2;
        }
        else{
            n=3*n+1;
            if (n>altMax){
                altMax=n;
            }
        }
        printf("%d ", n);
        tempsDeVol++;
    }

    printf("\nTemps de vol : %d\n", tempsDeVol);
    printf("Altitude maximale : %d\n", altMax);
}