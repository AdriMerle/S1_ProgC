#include <stdio.h>

int main() {
    int d = 13;
    int *ptr_d;
    // ptr_d = &d;

    printf("d   : val=%d | adr=%p\r\n", d, &d);
    printf("ptr : val=%d | adr=%p\r\n", *ptr_d, ptr_d);

    printf("Changing value\r\n");
    *ptr_d=25;

    printf("d   : val=%d | adr=%p\r\n", d, &d);
    printf("ptr : val=%d | adr=%p\r\n", *ptr_d, ptr_d);

    return 0;
}