#include <stdio.h>

int main() {
    int tab[10];
    int *pt;

    // printf("adr=%p, adr=%p\r\n", tab, &tab); //?????????

    for(int i=0;i<10;i++){
        tab[i] = i+1;
    }
    
    pt = &tab[8];
    for(int i=0;i<5;i++){
        printf("tab[i]=%d\r\n", *pt);
        pt -= 2;
    }
    return 0;
}