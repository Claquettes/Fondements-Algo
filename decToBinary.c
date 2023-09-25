#include stdio.h
#include stdlib.h

void bin(int n)
{
    //we define the tab that will contain the binary number
    int tab[100];
    if (n > 1)
        bin(n/2);
    else if (n == 1)
    
    printf("%d", n % 2);
}

void main (
    int x = 29;
    bin(x);
)