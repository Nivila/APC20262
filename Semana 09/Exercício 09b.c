#include <stdio.h>
#include <stddef.h>

int main(void) {
    int v[4] = {10, 20, 30, 40};
    int *p = v;

    printf("*p     = %d\n", *p);
    printf("*(p+1) = %d\n", *(p+1));
    printf("*(p+2) = %d\n", *(p+2));

    int *q = v + 3;
    ptrdiff_t diff = q - p;
    printf("q - p  = %td\n", diff);   /* 3 */

    p++;
    printf("apos p++: *p = %d\n", *p);   /* 20 */
    return 0;
}
