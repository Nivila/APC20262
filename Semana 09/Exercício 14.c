#include <stdio.h>

#define PI            3.14159
#define QUADRADO(x)   ((x)*(x))
#define MAX(a,b)      ((a)>(b)?(a):(b))

#define DEBUG 1
#ifdef DEBUG
    #define LOG(msg)  printf("[%s:%d] %s\n", __FILE__, __LINE__, msg)
#else
    #define LOG(msg)
#endif

int main(void) {
    double r = 5.0;
    printf("Área r=5: %.2f\n", PI * QUADRADO(r));

    int a = 7, b = 3;
    printf("MAX(%d,%d) = %d\n", a, b, MAX(a,b));

    LOG("iniciando cálculo");   /* só aparece se DEBUG estiver definido */

    printf("Compilado em %s às %s\n", __DATE__, __TIME__);
    return 0;
}
