#include <stdio.h>
#include "biblio.h"

void affiche(Complex z) {
    if (z.im>0)       printf("%f +%f i\r\n", z.re, z.im);
    else if (z.im<0)  printf("%f %f i\r\n", z.re, z.im);
    else printf("%d", z.re);
}

Complex ajoute(Complex z1, Complex z2) {
    Complex a;
    a.re = z1.re + z2.re;
    a.im = z1.im + z2.im;

    return a;
}

Complex multiplie(Complex z1, Complex z2) {
    Complex a;
    a.re = z1.re * z1.re + z2.re * z2.re;
    a.im = z1.re * z2.im - z1.im * z2.re;

    return a;
}