#include <stdio.h>

int max(int a, int b) {
    if (a>b) return a;
    else return b;
}

int main()
{   
    int n,i;
    
    //Input
    scanf("%d", &n);
    int t[n], res[n];
    for(i=0;i<n;i++) scanf("%d", &t[i]);

    // Init 0
    res[0] = t[0];
    
    // On prend la plus grande valeur entre la somme jusqu'à la valeur
    // Et la somme à partir de la valeur (nouvelle somme)
    for(i=1; i<n; i++) res[i] = max(res[i-1]+t[i],t[i]);
    
    // Recherche du max
    int val_end = res[0];
    for(i=1;i<n;i++) val_end = max(val_end, res[i]);
    
    printf("%d\r\n", val_end);

    return 0;
}
