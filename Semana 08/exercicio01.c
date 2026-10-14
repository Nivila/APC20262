#include <stdio.h>

// Funcao que recebe dois numeros inteiros e retorna a multiplicacao.
int mult(int a, int b) {
    return a * b;
}

// Funcao que soma o primeiro numero ao resultado da multiplicacao.
int soma_mult(int a, int b, int c) {
    return a + mult(b, c);
}

int main(void) {

    // Chama soma_mult, que tambem chama a funcao mult.
    int resultado = soma_mult(1, 5, 3);

    // Exibe o resultado da operacao na tela.
    printf("%d\n", resultado); // Resultado: 16

    // Encerra o programa.
    return 0;
}
