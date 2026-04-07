#include <stdio.h>

#define TAM 10

// Função para verificar se a matriz é identidade
int ehIdentidade(int matriz[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if (i == j) {
                if (matriz[i][j] != 1) {
                    return 0; // Não é identidade
                }
            } else {
                if (matriz[i][j] != 0) {
                    return 0; // Não é identidade
                }
            }
        }
    }
    return 1; // É identidade
}

int main() {
    int matriz1[TAM][TAM];
    int matriz2[TAM][TAM];
    int somaDiag1 = 0, somaDiag2 = 0;

    // Entrada da primeira matriz (valores >= 0)
    printf("Digite os valores da matriz 1 (apenas valores >= 0):\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            do {
                printf("matriz1[%d][%d]: ", i, j);
                scanf("%d", &matriz1[i][j]);
                if (matriz1[i][j] < 0) {
                    printf("Valor invalido! Digite apenas valores positivos ou zero.\n");
                }
            } while (matriz1[i][j] < 0);
        }
    }

    // Entrada da segunda matriz (valores < 0)
    printf("\nDigite os valores da matriz 2 (apenas valores negativos):\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            do {
                printf("matriz2[%d][%d]: ", i, j);
                scanf("%d", &matriz2[i][j]);
                if (matriz2[i][j] >= 0) {
                    printf("Valor invalido! Digite apenas valores negativos.\n");
                }
            } while (matriz2[i][j] >= 0);
        }
    }

    // a) Soma das diagonais principais
    for (int i = 0; i < TAM; i++) {
        somaDiag1 += matriz1[i][i];
        somaDiag2 += matriz2[i][i];
    }

    printf("\nSoma da diagonal principal da matriz 1: %d\n", somaDiag1);
    printf("Soma da diagonal principal da matriz 2: %d\n", somaDiag2);

    // b) Matrizes opostas
    printf("\nMatriz oposta da matriz 1:\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if (matriz1[i][j] != 0)
                printf("%d ", -matriz1[i][j]);
            else
                printf("0 ");
        }
        printf("\n");
    }

    printf("\nMatriz oposta da matriz 2:\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if (matriz2[i][j] != 0)
                printf("%d ", -matriz2[i][j]);
            else
                printf("0 ");
        }
        printf("\n");
    }

    // c) Verificar se a matriz 1 é identidade
    if (ehIdentidade(matriz1)) {
        printf("\nA matriz 1 é uma matriz identidade.\n");
    } else {
        printf("\nA matriz 1 NÃO é uma matriz identidade.\n");
    }

    return 0;
}