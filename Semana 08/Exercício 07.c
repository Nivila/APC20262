#include <stdio.h>
#include <string.h>

int main(void) {
    int v[5] = {10, 20, 30, 40, 50};
    int soma = 0;
    for (int i = 0; i < 5; i++) soma += v[i];
    printf("soma = %d\n", soma);

    /* cópia de array com memcpy */
    int w[5];
    memcpy(w, v, sizeof(v));
    w[0] = 99;
    printf("v[0]=%d  w[0]=%d\n", v[0], w[0]);   /* 10 e 99 — independentes */

    /* matriz */
    int m[2][3] = {{1, 2, 3}, {4, 5, 6}};
    printf("m[1][2] = %d\n", m[1][2]);   /* 6 */

    /* row-major: elementos consecutivos na memória */
    int *p = &m[0][0];
    for (int i = 0; i < 6; i++) printf("%d ", p[i]);   /* 1 2 3 4 5 6 */
    printf("\n");
    return 0;
}
