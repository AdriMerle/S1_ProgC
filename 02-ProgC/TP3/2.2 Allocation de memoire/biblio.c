#include <stdlib.h>

double moyenne(int *t, int n) {
    int somme = 0;
    for(int i=0; i<n; i++) somme += t[i];
    double moy = (double)somme/n;

    return moy;
}

int min(int *t, int n) {
    int min = t[0];

    for(int i=1; i<n; i++) {
        if(t[i]<min) min = t[i];
    }

    return min;
}

int max(int *t, int n) {
    int m = t[0];

    for(int i=1; i<n; i++) {
        if(t[i]>m) m = t[i];
    }

    return m;
}