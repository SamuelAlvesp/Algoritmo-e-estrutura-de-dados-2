#include <stdio.h>

#define NUM_PRIMOS 25

int busca_binaria(int arr[], int tamanho, int elemento) {
    int esquerda = 0;
    int direita = tamanho - 1;

    while (esquerda <= direita) {
        int meio = (esquerda + direita) / 2;

        if (arr[meio] == elemento) {
            return meio; // Elemento encontrado
        } else if (arr[meio] < elemento) {
            esquerda = meio + 1;
        } else {
            direita = meio - 1;
        }
    }

    return -1; // Elemento não encontrado
}

int main() {
    int primos[NUM_PRIMOS] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    int numero, resultado;

    printf("Digite um número de 1 a 100: ");
    scanf("%d", &numero);

    resultado = busca_binaria(primos, NUM_PRIMOS, numero);

    if (resultado != -1) {
        printf("O número %d é primo e está na posição %d do array.\n", numero, resultado);
    } else {
        printf("O número %d não é primo.\n", numero);
    }

    return 0;
}
