#include <stdio.h>

int global = 100;   /* escopo global, duração: programa inteiro */

int main(void) {
    int x = 1;
    printf("x externo = %d\n", x);
    printf("global    = %d\n", global);

    {
        int x = 2;   /* shadows o x externo */
        int global = 999;  /* shadows a global */
        printf("x interno  = %d\n", x);
        printf("global local = %d\n", global);
    }   /* x=2 e global local desaparecem aqui */

    printf("x apos bloco = %d\n", x);       /* 1 */
    printf("global       = %d\n", global);  /* 100 */
    return 0;
}
