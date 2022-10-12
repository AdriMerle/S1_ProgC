#include <stdio.h>
#include "biblio.h"

int main() {
    Complex z1, z2;
    scanf("%f", &z1.re);
    scanf("%f", &z1.im);

    scanf("%f", &z2.re);
    scanf("%f", &z2.im);

    affiche(z1);
    affiche(z2);

    printf("\r\nSOMME : ");
    affiche(ajoute(z1,z2));

    printf("\r\nPRODUIT : ");
    affiche(multiplie(z1,z2));

    Complex i; i.re=0; i.im=1;
    Complex un; un.re=1; un.im=0;
    Complex moins_un; moins_un.re=-1; moins_un.im=0;

    // affiche(multiplie(ajoute(un, i), ajoute(i, moins_un)));

    
    return 0;
}