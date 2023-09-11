# Pointeurs

Un pointeur est une **variable** qui contient l'adresse une variable dans la mémoire, en particulier une variable allouée dynamiquement (dans le tas)

## Déclaration

* ```Type *nom;```
* Opérateur d'adressage ```&``` : ```&nom``` est l'adresse de la variable nom

--------------------

### Exemple de pointeur  

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

### Exemple avec un tableau

Soit P un pointeur sur un tableau A:
```int A[]= {1,2,3,4,5, 6, 7, 8, 9};```  
```int *P;```  
```P = A;```  

a) ```*P+2 = valeur de A[0]+2 = 1+2 = 3```
b) ```*(P+2) = valeur de A[2] = 3```
c) ```&P+1 = adresse de P + 1 = adresse pas très intéressante```
d) ```A[4]- 3 = 5-3 = 2```   
e) ```A+3 = **adresse** de A[3] (donc la quatrième case du tableau)```
f) ```&A[7] - P = adresse de A[7] - adresse de A[0] = 7*4 = 28```

--------------------

## Passage de paramètres  

Deux types de passage : par valeur et par adresse

* Passage par valeur : la valeur de la variable est **copiée** dans la fonction, on ne peut pas modifier la variable vu qu'on travaille sur une copie
* Passage par adresse : on passe **l'adresse de la variable**, vu qu'on travaille sur l'adresse, on peut modifier la variable

### structs

type de variable qui permet de regrouper plusieurs variables de types différents

```struct nom {```
```type1 nom1```
```type2 nom2;```
```...```
```typeN nomN;```
```};```

--------------------

### Exemple de struct et de passage de paamètres:

```void Proc (Noeud n)``` // Passage par valeur d'un élément de type Noeud  
```{```  
```n.valeur = 5;```   // On ne modifie pas la valeur de l'élément, vu que c'est une copie
```}```  

```void Proc (Noeud *n)``` // Passage par adresse d'un élément de type Noeud  
```{```  
```n->valeur = 5;```  
```}```

### Types de pointeurs

* Pointeur sur un type de base : ```int *p;```
* Pointeur sur un tableau : ```int *p[10];```
* Pointeur sur un char : ```char *p;```

Soit l'écriture suivante:

*pointeur sur un tableau de 10 entiers*  
```int *p[10];```  
*tableau de 10 pointeurs sur des entiers*  
```int (*p)[10];```
*pointeur sur un char (chaine de caractères)*  
```char *p;```

Taille des **objets** en C:

**int** : 4 octets
**char** : 1 octet
**float** : 4 octets
**double** : 8 octets

**On ne fait pas *p++* sur un tableau de pointeurs, mais sur un pointeur sur un tableau**

### Pointeur de fonctions

En soit, une fonction peut prendre en argument un pointeur sur une fonction pour pouvoir l'appeler

```void f(int (*p)(int, int))```  
```{```  
```int a = 5;```  
```int b = 6;```  
```int c = (*p)(a, b);```  
```}```

--------------------

## Pile et Tas

### Tas

* Le **Heap** (tas en francais mais péférez la notation anglaise) est une zone de la mémoire qui est allouée dynamiquement (on utilise malloc pour allouer de la mémoire dans le tas)
* Permets de stocker des données de taille variable
* **On doit libérer la mémoire manuellement** (avec free or delete)

### Pile

* Le **Stack** (pile en francais mais péférez la notation anglaise) est une zone de la mémoire qui est allouée statiquement (on utilise des variables globales ou des variables locales pour allouer de la mémoire dans la pile)
* Permets de stocker des données de taille fixe

