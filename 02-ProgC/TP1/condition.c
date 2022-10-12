#include <stdio.h>

int main() {
    int val;

    scanf("%d", &val);
    
    if (val==1000) printf("Vous êtes dans le mille !");
    else if (val < 100) printf("Valeur beaucoup trop petite.");
    else if (val > 10000) printf("Valeur beaucoup trop grande.");

    printf("\r\n");
}