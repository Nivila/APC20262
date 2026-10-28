#include <stdio.h>
#include <string.h>

int main(void) {
    char destino[8];

    /* SEGURO: limita a cópia ao tamanho do buffer */
    strncpy(destino, "Brasilia-DF", sizeof(destino) - 1);
    destino[sizeof(destino) - 1] = '\0';   /* garante terminador */

    printf("destino = '%s'\n", destino);   /* "Brasili" */
    printf("strlen  = %zu\n",  strlen(destino));   /* 7 */

    /* ALTERNATIVA SEGURA com snprintf */
    char buf[16];
    int  n = snprintf(buf, sizeof(buf), "valor=%d", 12345);
    if (n >= (int)sizeof(buf)) printf("truncado!\n");
    printf("buf = '%s'\n", buf);
    return 0;
}
