#include <stdio.h>
#include <stdlib.h>

int cmp_int_asc(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

int cmp_int_desc(const void *a, const void *b) {
    return *(int*)b - *(int*)a;
}

void print_array(int *v, int n) {
    for (int i = 0; i < n; i++) printf("%d ", v[i]);
    printf("\n");
}

int main(void) {
    int v[] = {40, 10, 30, 50, 20};
    int n   = sizeof(v) / sizeof(v[0]);

    qsort(v, n, sizeof(int), cmp_int_asc);
    printf("Crescente:  "); print_array(v, n);

    qsort(v, n, sizeof(int), cmp_int_desc);
    printf("Decrescente:"); print_array(v, n);

    /* Array de ponteiros para função */
    int (*ops[])(const void*, const void*) = { cmp_int_asc, cmp_int_desc };
    qsort(v, n, sizeof(int), ops[0]);
    printf("Crescente:  "); print_array(v, n);
    return 0;
}
