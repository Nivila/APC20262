#include <stdio.h>

int fatorial(int n) {
    if (n <= 1) return 1;
    return n * fatorial(n - 1);
}

void dobra(int *x) { *x *= 2; }

int main(void) {
    printf("5! = %d\n", fatorial(5));

    int v = 7;
    dobra(&v);
    printf("dobro de 7 = %d\n", v);

    /* ponteiro para função */
    int (*fn)(int) = fatorial;
    printf("fn(4) = %d\n", fn(4));   /* 24 */
    return 0;
}
