#include <stdio.h>

union Dado { int i; float f; char c; };

int main(void) {
    union Dado d;
    d.i = 65;
    printf("d.i='%d'  d.c='%c'\n", d.i, d.c);   /* 65 e 'A' — mesmos bytes */
    d.f = 3.14f;
    printf("d.f=%.2f\n", d.f);   /* d.i agora tem valor indefinido */
    return 0;
}
