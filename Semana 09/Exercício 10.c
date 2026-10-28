#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n = 4;
    int *v = calloc(n, sizeof(int));   /* heap, inicializado com 0 */
    if (!v) { perror("calloc"); return 1; }

    for (int i = 0; i < n; i++) v[i] = (i + 1) * 10;
    for (int i = 0; i < n; i++) printf("v[%d]=%d\n", i, v[i]);

    /* expandir para 6 elementos */
    n = 6;
    int *tmp = realloc(v, n * sizeof(int));
    if (!tmp) { free(v); perror("realloc"); return 1; }
    v = tmp;
    v[4] = 50; v[5] = 60;
    for (int i = 0; i < n; i++) printf("v[%d]=%d\n", i, v[i]);

    free(v);
    v = NULL;
    return 0;
}
