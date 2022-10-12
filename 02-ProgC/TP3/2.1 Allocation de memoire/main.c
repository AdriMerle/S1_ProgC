#include <stdio.h>
#include "biblio.h"

int main() {
    int N = 3;
    int tab[N];

    for(int i=0; i<N; i++) scanf("%d", &tab[i]);

    int m = max(tab, N);

    printf("\r\nmin=%d max=%d moy=%lf\r\n", min(tab, N), m, moyenne(tab, N));
}