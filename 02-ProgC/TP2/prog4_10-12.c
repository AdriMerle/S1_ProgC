#include <stdio.h>

int main() {
    int tab1[10];
    int tab2[10];

    for(int i=0; i<10; i++) {
        tab1[i] = i + 1 ;
        tab2[i] = 101 + i;
    }


    int *pt = tab1;

    for(int i=0; i<20; i++) {
        printf("%d\r\n", *(pt+i));
    }

    
    return 0;
}