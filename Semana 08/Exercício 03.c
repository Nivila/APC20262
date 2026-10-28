#include <stdio.h>

int global = 0;   /* variáveis globais são inicializadas com 0 automaticamente */

int main(void) {
    int a = 42;
    int b;          /* valor lixo — NUNCA use antes de atribuir */
    b = a + 8;

    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("global = %d\n", global);

    const int N = 100;
    /* N = 200; */   /* erro de compilação: assignment of read-only variable */
    printf("N = %d\n", N);
    return 0;
}
