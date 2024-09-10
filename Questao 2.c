#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CRIANCAS 50
#define NOTA_MAXIMA 5

int main() {
    int notas[NUM_CRIANCAS];
    int contagem[NOTA_MAXIMA] = {0};
    
    // Inicializa o gerador de números aleatórios
    srand(time(0));
    
    // Gera notas aleatórias entre 1 e 5
    for (int i = 0; i < NUM_CRIANCAS; i++) {
        notas[i] = (rand() % NOTA_MAXIMA) + 1;
    }
    
    // Conta a frequência de cada nota
    for (int i = 0; i < NUM_CRIANCAS; i++) {
        contagem[notas[i] - 1]++;
    }
    
    // Exibe o resultado
    printf("Distribuição das notas:\n");
    for (int i = 0; i < NOTA_MAXIMA; i++) {
        printf("Nota %d: %d vezes\n", i + 1, contagem[i]);
    }
    
    return 0;
}
