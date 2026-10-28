
#include <stdio.h>

#define TAMANHO 10

/*
 * Projeto: Organizador de Precos de Supermercado
 * Objetivo: Ordenar dez precos utilizando Bubble Sort
 * e Quick Sort, apresentando os resultados.
 */

// Bubble Sort compara elementos vizinhos e os troca
// quando estao fora de ordem.
void bubbleSort(int vetor[], int tamanho) {
    int i, j, temp;

    for (i = 0; i < tamanho - 1; i++) {
        for (j = 0; j < tamanho - 1 - i; j++) {
            if (vetor[j] > vetor[j + 1]) {
                temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}

// Particiona o vetor usando o ultimo elemento como pivo.
// Os valores menores ou iguais ao pivo ficam a esquerda,
// e os maiores ficam a direita.
int particionar(int vetor[], int inicio, int fim) {
    int pivo = vetor[fim];
    int i = inicio - 1;
    int j, temp;

    for (j = inicio; j < fim; j++) {
        if (vetor[j] <= pivo) {
            i++;

            temp = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = temp;
        }
    }

    // Posiciona o pivo em seu lugar definitivo.
    temp = vetor[i + 1];
    vetor[i + 1] = vetor[fim];
    vetor[fim] = temp;

    return i + 1;
}

// Quick Sort divide o vetor em particoes ao redor
// de um pivo e ordena cada parte recursivamente.
void quickSort(int vetor[], int inicio, int fim) {
    if (inicio < fim) {
        int pivo = particionar(vetor, inicio, fim);

        quickSort(vetor, inicio, pivo - 1);
        quickSort(vetor, pivo + 1, fim);
    }
}

// Exibe os precos armazenados em centavos como reais.
void mostrarPrecos(int vetor[], int tamanho) {
    int i;

    for (i = 0; i < tamanho; i++) {
        printf("R$ %d,%02d\n",
               vetor[i] / 100,
               vetor[i] % 100);
    }
}

int main(void) {
    // Dez precos ficticios de produtos de supermercado.
    // Os valores sao armazenados em centavos.
    int precos[TAMANHO] = {
        4500, 1299, 7890, 350, 2999,
        5690, 899, 9190, 1750, 3400
    };

    int vetorBubble[TAMANHO];
    int vetorQuick[TAMANHO];
    int i;

    // Os dois algoritmos recebem os mesmos dados.
    for (i = 0; i < TAMANHO; i++) {
        vetorBubble[i] = precos[i];
        vetorQuick[i] = precos[i];
    }

    printf("====================================\n");
    printf(" ORGANIZADOR DE PRECOS DE SUPERMERCADO\n");
    printf("====================================\n");

    printf("\nPrecos originais:\n");
    mostrarPrecos(precos, TAMANHO);

    bubbleSort(vetorBubble, TAMANHO);

    printf("\nPrecos ordenados - Bubble Sort:\n");
    mostrarPrecos(vetorBubble, TAMANHO);

    quickSort(vetorQuick, 0, TAMANHO - 1);

    printf("\nPrecos ordenados - Quick Sort:\n");
    mostrarPrecos(vetorQuick, TAMANHO);

    return 0;
}
