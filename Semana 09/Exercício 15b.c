#include <stdio.h>

void contador(void) {
    static int n = 0;   /* inicializado UMA VEZ; persiste entre chamadas */
    n++;
    printf("chamada %d\n", n);
}

int main(void) {
    contador(); contador(); contador();   /* 1, 2, 3 */
    return 0;
}
