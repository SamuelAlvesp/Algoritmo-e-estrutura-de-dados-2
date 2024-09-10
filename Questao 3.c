#include <stdio.h>

#define NUM_CONTAS 100

int busca_binaria(int contas[], int tamanho, int conta_procurada, int *comparacoes) {
    int esquerda = 0;
    int direita = tamanho - 1;
    *comparacoes = 0;

    while (esquerda <= direita) {
        (*comparacoes)++;
        int meio = (esquerda + direita) / 2;

        if (contas[meio] == conta_procurada) {
            return meio; // Conta encontrada
        } else if (contas[meio] < conta_procurada) {
            esquerda = meio + 1;
        } else {
            direita = meio - 1;
        }
    }

    return -1; // Conta não encontrada
}

int main() {
    int contas[NUM_CONTAS];
    int conta_procurada, comparacoes;

    // Inicializa o vetor de contas com números de conta em ordem crescente
    for (int i = 0; i < NUM_CONTAS; i++) {
        contas[i] = i + 1; // Exemplo: contas de 1 a 100
    }

    printf("Digite o número da conta a ser procurada: ");
    scanf("%d", &conta_procurada);

    int posicao = busca_binaria(contas, NUM_CONTAS, conta_procurada, &comparacoes);

    if (posicao != -1) {
        printf("Conta %d encontrada na posição %d.\n", conta_procurada, posicao);
    } else {
        printf("Conta %d não encontrada.\n", conta_procurada);
    }

    printf("Número de comparações: %d\n", comparacoes);

    return 0;
}
