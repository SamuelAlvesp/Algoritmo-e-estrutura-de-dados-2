#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CRIANCAS 50
#define NOTA_MAXIMA 5

int main() {
    int notas[NUM_CRIANCAS];
    int contagem[NOTA_MAXIMA] = {0};
    
    srand(time(0));
    
    for (int i = 0; i < NUM_CRIANCAS; i++) {
        notas[i] = (rand() % NOTA_MAXIMA) + 1;
    }
    
    for (int i = 0; i < NUM_CRIANCAS; i++) {
        contagem[notas[i] - 1]++;
    }
    
    printf("Distribuição das notas:\n");
    for (int i = 0; i < NOTA_MAXIMA; i++) {
        printf("Nota %d: %d vezes\n", i + 1, contagem[i]);
    }
    
    return 0;
}
