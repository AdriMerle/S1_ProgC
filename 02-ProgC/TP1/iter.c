#include <stdio.h>
int main() {
    int tab[] = {1, 7, 4, 5, 9, 3, 5, 11, 6, 3, 4};
    int i = -1;

    while (i < 10) {
        i++;
        if (tab[i]<5) continue;
        if (tab[i]>10) break;
        printf("%d\n", tab[i]);
    }
    return 0;
}