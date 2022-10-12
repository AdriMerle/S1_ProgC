#include <stdio.h>

int main() {
    float f = 2.1;
    float *ptf = &f;
    void *ptgen;
    printf("VAL  : f=%f, adr=%p\r\n", f, &f);
    printf("SIZE : f=%d, pt=%d, ptgen=%d\r\n", sizeof(f), sizeof(ptf), sizeof(ptgen));
    return 0;
}