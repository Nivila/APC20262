#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
    char s[] = "Brasilia";
    printf("Comprimento: %zu\n", strlen(s));

    for (int i = 0; s[i] != '\0'; i++)
        printf("s[%d]='%c' ASCII=%d\n", i, s[i], (int)s[i]);

    /* comparação */
    printf("strcmp: %d\n", strcmp(s, "Brasilia"));    /* 0 */
    printf("strcmp: %d\n", strcmp(s, "Curitiba"));    /* negativo */

    /* busca */
    char *pos = strchr(s, 'i');
    if (pos) printf("Primeiro 'i' na posição %td\n", pos - s);  /* 5 */

    /* conversão */
    int n = atoi("1234");
    printf("atoi(\"1234\") = %d\n", n);
    return 0;
}
