#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[30];
    int  x, y;
} Ponto;

float dist2(const Ponto *a, const Ponto *b) {
    int dx = a->x - b->x, dy = a->y - b->y;
    return (float)(dx*dx + dy*dy);
}

int main(void) {
    Ponto origem = {"origem", 0, 0};
    Ponto p      = {"p",      3, 4};

    printf("%s: (%d,%d)\n", p.nome, p.x, p.y);

    Ponto *ptr = &p;
    ptr->x = 10;
    printf("apos ptr->x=10: p.x=%d\n", p.x);

    printf("dist2(origem,p)=%.0f\n", dist2(&origem, &p));

    /* struct como valor — cópia independente */
    Ponto q = p;
    q.x = 99;
    printf("p.x=%d  q.x=%d\n", p.x, q.x);   /* 10 e 99 */
    return 0;
}
