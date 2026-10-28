#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int        valor;
    struct No *proximo;   /* ponteiro para o próprio tipo — struct recursiva */
} No;

No *criar_no(int valor) {
    No *n = malloc(sizeof(No));
    if (!n) { perror("malloc"); exit(1); }
    n->valor    = valor;
    n->proximo  = NULL;
    return n;
}

void inserir_frente(No **cabeca, int valor) {
    No *novo    = criar_no(valor);
    novo->proximo = *cabeca;
    *cabeca     = novo;
}

void imprimir(const No *cabeca) {
    for (const No *p = cabeca; p; p = p->proximo)
        printf("%d -> ", p->valor);
    printf("NULL\n");
}

void liberar(No *cabeca) {
    while (cabeca) {
        No *prox = cabeca->proximo;
        free(cabeca);
        cabeca = prox;
    }
}

int main(void) {
    No *lista = NULL;
    inserir_frente(&lista, 30);
    inserir_frente(&lista, 20);
    inserir_frente(&lista, 10);
    imprimir(lista);   /* 10 -> 20 -> 30 -> NULL */
    liberar(lista);
    lista = NULL;
    return 0;
}
