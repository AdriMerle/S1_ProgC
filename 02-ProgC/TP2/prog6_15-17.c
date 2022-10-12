#include <stdio.h>

void swap(int *a, int *b) {
    int c=*b;
    *b=*a;
    *a=c;
}

int main() {
    int a=10;
    int b=20;
    printf("%d %d\r\n", a, b);
    
    swap(&a,&b);
    printf("%d %d\r\n", a, b);
    return 0;
}