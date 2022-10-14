#include <stdio.h>

int main() {
    int A, B;
    int i=0,j=0;
    int res = 0;

    scanf("%d", &A);
    scanf("%d", &B);

    //&& (i*i+j*j<=A || i*i*i+j*j*j<=B)
    while((i*i+j*j<=A) && (i*i*i+j*j*j<=B)) {
        while((i*i+j*j<=A) && (i*i*i + j*j*j<=B)) {
            if ((i*i + j*j == A) && (i*i*i + j*j*j == B)) {
                printf("%d %d\r\n", i, j);
                res = 1;
            }
            j++;
        }
        j=0;
        i++;    
    }

    if (!res) {
        printf("-\r\n");
    }
    return 0;
}