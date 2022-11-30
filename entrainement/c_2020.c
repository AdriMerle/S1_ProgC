#include <stdio.h>

long set_bit(long bitfield, int numbit) {
    int toadd = 1;
    for(int i=0; i<numbit; i++) {
        toadd *= 10;
    }
    return toadd + bitfield;
}

int main() {
    int tab[] = {3,5,7,9,11,13,15,17,19};
    int *p;
    p = tab;
    printf("&P %p \r\n", p);
    printf("(*p)+2 %d \r\n", (*p)+2);
    printf("tab+3 %p\r\n", tab+3);
    printf("*(p+2) %d\r\n", *(p+2));
    printf("&tab[4]-p %ld\r\n", &tab[4]-p);
    printf("p+3 %p\r\n", p+3);
    printf("p+(*p+4) %p\r\n", p+(*p+4));
    printf("tab[5]-3 %d\r\n", tab[5]-3);

    int *p1, *p2, *p3;
    p1 = tab; p2 = &tab[1]; p2 = &tab[2];
    *p2 = *p1/=*p2;
    printf("%d \r\n", *p1);


    return 0;
}