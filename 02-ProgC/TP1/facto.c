#include <stdio.h>
int main() {
    int tab[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    /* utiliser une boucle for pour calculer la factorielle de 10 */
    int fact=1, i;

    for(i=0; i<10; i++) fact*=tab[i];

    printf("10! = %d\r\n", fact);

    return 0;
}