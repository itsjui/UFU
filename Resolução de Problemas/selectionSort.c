#include <stdio.h>

// Função para ordenar o vetor com Selection Sort
void selectionSort(int arr[], int n) {
    int i, j, minIdx, temp;

    // Percorre o vetor
    for (i = 0; i < n - 1; i++) {
        minIdx = i;

        // Encontra o menor elemento no vetor não ordenado
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }

        // Troca o menor elemento encontrado com o primeiro elemento não ordenado
        if (minIdx != i) {
            temp = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = temp;
        }
    }
}

int main() {
    int arr[] = {30, 10, 20, 50, 15};  // Vetor de inteiros
    int n = sizeof(arr) / sizeof(arr[0]);  // Calcula o número de elementos do vetor

    printf("Vetor original: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Ordena o vetor com Selection Sort
    selectionSort(arr, n);

    printf("Vetor ordenado com Selection Sort: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
