#include <stdio.h>

int main() {
    double tab1[10][2];
    double tab2[20];
    int a=0;
    for(int i=0; i<10; i++) {
        for(int j=0; j<2; j++) {
            printf("i=%d, j=%d, %p, %p\r\n", i, j, &tab1[i][j], &tab2[a]);
            a++;
        }
    }
    return 0;
}