# Pointeurs

Un pointeur est une variable qui contient l'adresse une variable dans la mémoire, en particulier une variable allouée dynamiquement (dans le tas)

## Déclaration

* ```Type *nom;```
* Opérateur d'adressage ```&``` : ```&nom``` est l'adresse de la variable nom

--------------------
### Exemple : 
```int *A; int B;```  
```A = &B;```  
```*A = 5;```  
```printf("%d", B);```

--------------------
## Pointeurs et tableau

Considérons un tableau d'int A[10] et un pointeur int *p;
* A[i] est équivalent à *(A+i)
* *p est équivalent à A[0] (le pointeur pointe sur le premier élément du tableau)

--------------------
### Exemple:
Soit P un pointeur sur un tableau A:
```int A[]= {1,2,3,4,5, 6, 7, 8, 9};```  
```int *P;```  
```P = A;```  

a) ```*P+2 = valeur de A[0]+2 = 1+2 = 3```
b) ```*(P+2) = valeur de A[2] = 3```
c) ```&P+1 = adresse de P + 1 = adresse pas très intéressante```
d) ```A[4]- 3 = 5-3 = 2```
e) ```A+3 = **adresse** de A[3] (donc la quatrième case du tableau) ```
f) ``` &A[7] - P = adresse de A[7] - adresse de A[0] = 7*4 = 28```
