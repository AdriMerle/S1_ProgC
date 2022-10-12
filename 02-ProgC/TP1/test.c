#include <stdio.h>
#include <limits.h>

int main() {
    printf("INT: Size=%d, Min=%d, Max=%d.\r\n", sizeof(int), INT_MIN, INT_MAX);
    printf("CHAR: Size=%d, Min=%d, Max=%d.\r\n", sizeof(char), CHAR_MIN, CHAR_MAX);
    printf("LONG: Size=%d, Min=%ld, Max=%ld.\r\n", sizeof(long), LONG_MIN, LONG_MAX);
    printf("LONG Size=%d, LONG: Min=%lld, Max=%lld.\r\n", sizeof(long long), LLONG_MIN, LLONG_MAX);
    return 0;
}