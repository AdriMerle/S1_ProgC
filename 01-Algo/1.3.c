#include <stdio.h>

int main()
{
    int a1, b1, a2, b2;
    scanf("%d", &a1);
    scanf("%d", &b1);
    scanf("%d", &a2);
    scanf("%d", &b2);
    
    // Cas intervalles séparés
    if ((a1 >= b2) || (a2 >= b1)) printf("0\r\n");
    
    else if(a1<a2) {
        if ((a2<b1) && (b1<=b2)) printf("%d\r\n", b1-a2);
        if ((a2<b1) && (b1>b2)) printf("%d\r\n", b2-a2);
    }
    
    else if(a1>a2) {
        if ((a1<b2) && (b2<=b1)) printf("%d\r\n", b2-a1);
        if ((a1<b2) && (b1<b2)) printf("%d\r\n", b1-a1);
    }
    
    else if ((a2<=a1) && (b1<=b2)) {
        printf("%d\r\n", b1-a1);
    }
    
    else if ((a1<=a2) && (b2<=b1)) {
        printf("%d\r\n", b2-a2);
    }
    
    return 0;
}