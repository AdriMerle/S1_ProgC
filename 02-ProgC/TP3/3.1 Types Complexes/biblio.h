#ifndef BIBLIO_H
#define BIBLIO_H

typedef struct {float re; float im;} Complex;

extern void affiche(Complex z);
Complex ajoute(Complex z1, Complex z2);
Complex multiplie(Complex z1, Complex z2);

#endif