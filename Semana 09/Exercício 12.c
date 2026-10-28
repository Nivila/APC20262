#include <stdio.h>

typedef enum { DOM=0, SEG, TER, QUA, QUI, SEX, SAB } DiaSemana;

const char *nome_dia(DiaSemana d) {
    switch (d) {
        case DOM: return "Domingo";
        case SEG: return "Segunda";
        case TER: return "Terca";
        case QUA: return "Quarta";
        case QUI: return "Quinta";
        case SEX: return "Sexta";
        case SAB: return "Sabado";
        default:  return "???";
    }
}

typedef enum { LEITURA=1, ESCRITA=2, EXECUCAO=4 } Permissao;

int main(void) {
    for (DiaSemana d = DOM; d <= SAB; d++)
        printf("%d = %s\n", d, nome_dia(d));

    Permissao p = LEITURA | EXECUCAO;   /* 5 */
    printf("\nPermissões: leitura=%s escrita=%s execução=%s\n",
           (p & LEITURA)  ? "sim" : "não",
           (p & ESCRITA)  ? "sim" : "não",
           (p & EXECUCAO) ? "sim" : "não");
    return 0;
}
