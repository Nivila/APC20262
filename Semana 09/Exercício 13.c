#include <stdio.h>

int main(void) {
    int    i = 255;
    double f = 3.14159;
    char   s[] = "Brasilia";

    printf("Decimal:     %d\n",    i);
    printf("Hex:         %x\n",    i);      /* ff */
    printf("Octal:       %o\n",    i);      /* 377 */
    printf("Float:       %.4f\n",  f);
    printf("Cientifico:  %e\n",    f);
    printf("Alinhado:    %10.2f\n",f);      /* "      3.14" */
    printf("String:      %-10s|\n",s);      /* "Brasilia  |" */
    printf("Ponteiro:    %p\n",    (void*)s);

    /* Escrever e ler arquivo */
    FILE *fw = fopen("/tmp/teste.txt", "w");
    if (fw) {
        fprintf(fw, "%d %.2f %s\n", i, f, s);
        fclose(fw);
    }

    FILE *fr = fopen("/tmp/teste.txt", "r");
    if (fr) {
        int n; double d; char t[50];
        fscanf(fr, "%d %lf %49s", &n, &d, t);
        printf("lido: %d %.2f %s\n", n, d, t);
        fclose(fr);
    }
    return 0;
}
