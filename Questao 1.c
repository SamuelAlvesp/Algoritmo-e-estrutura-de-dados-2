#include <stdio.h>
#include <string.h>

#define MAX_TENTATIVAS 12

void exibirPalavra(char palavra[], int tamanho, int acertos[]) {
    for (int i = 0; i < tamanho; i++) {
        if (acertos[i]) {
            printf("%c ", palavra[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");
}

int main() {
    char palavra[11]; 
    int tamanho, tentativas, vidas;
    int acertos[10] = {0}; 
    char letra;
    int acertou;

     printf("Digite a palavra secreta (até 10 caracteres): ");
    scanf("%10s", palavra);
    tamanho = strlen(palavra);
    vidas = tamanho + 2; 
    
    while (vidas > 0) {
        acertou = 0;
        exibirPalavra(palavra, tamanho, acertos);
        printf("Digite uma letra: ");
        scanf(" %c", &letra);

        for (int i = 0; i < tamanho; i++) {
            if (palavra[i] == letra) {
                acertos[i] = 1;
                acertou = 1;
            }
        }

        if (!acertou) {
            vidas--;
            printf("Letra incorreta! Vidas restantes: %d\n", vidas);
        }

        int todasAcertadas = 1;
        for (int i = 0; i < tamanho; i++) {
            if (!acertos[i]) {
                todasAcertadas = 0;
                break;
            }
        }

        if (todasAcertadas) {
            printf("Parabéns! Você descobriu a palavra: %s\n", palavra);
            break;
        }
    }

    if (vidas == 0) {
        printf("Você perdeu! A palavra era: %s\n", palavra);
    }

    return 0;
}
