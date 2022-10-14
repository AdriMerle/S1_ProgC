#include <stdio.h>

int main()
{
    int a,i,j;
    int X[1000];
    int pal = 1; //si pal=True -> X est un palindrome 
    i=0;
    
    scanf("%d", &a);
    while((a>=0) && (i<1000)) {
        X[i] = a;
        scanf("%d", &a);
        i++;
    }
    
    for(j=0; j<i/2; j++) {
        pal = (pal && (X[j]==X[i-j-1]));
    }
    
    printf("%d\r\n", pal);
    
    return 0;
}