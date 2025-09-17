#include <stdio.h>

// Função para ordenar o vetor com Bubble Sort
void bubbleSort(int arr[], int n) {
    int i, j, temp;

    // Percorre o vetor
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            // Se o elemento atual for maior que o próximo, troca
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr[] = {30, 10, 20, 50, 15};  // Vetor de inteiros
    int n = sizeof(arr) / sizeof(arr[0]);  // Calcula o número de elementos do vetor

    // Exibe o vetor original
    printf("Vetor original: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Ordena o vetor com Bubble Sort
    bubbleSort(arr, n);

    // Exibe o vetor ordenado
    printf("Vetor ordenado: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
