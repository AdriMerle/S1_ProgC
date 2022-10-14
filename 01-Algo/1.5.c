#include <stdio.h>

int collatz(int n) {
    if(n%2==0) return n/2;
    else return 3*n+1;
}

int main()
{
    int nb;
    scanf("%d", &nb);
    
    while(nb!=1) {
        printf("%d\r\n", nb);
        nb = collatz(nb);
    }
    
    printf("1\r\n");

    return 0;
}