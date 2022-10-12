#include <stdio.h>

int facto(int n) {
    if (n<=1) return n;
    else return facto(n-1)*n;
}

int main() {
    int i;
    for(i=0; i<11; i++) printf("%i! = %i\n", i, facto(i));
    return 0;
}