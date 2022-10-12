#include <stdio.h>
#include <stdlib.h>
#include "biblio.h"

int somme(int *t) {
    int somme = 0;
    size_t n = sizeof(t)/sizeof(t[0]); //Length of an array

    for(int i=0; i<=n; i++) somme += t[i];

    return somme;
}

int produit(int *t) {
    int produit = 1;
    size_t n = sizeof(t)/sizeof(t[0]); //Length of an array

    for(int i=0; i<=n; i++) produit *= t[i];

    return produit;
}

double moyenne(int *t) {
    size_t n = sizeof(t)/sizeof(t[0]); //Length of an array

    int somme = 0;
    for(int i=0; i<=n; i++) somme += t[i];
    double moy = (double)somme/n;

    return moy;
}