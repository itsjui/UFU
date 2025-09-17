#include <stdio.h>

// Função para ordenar o vetor com Insertion Sort
void insertionSort(int arr[], int n) {
    int i, j, key;

    // Percorre o vetor
    for (i = 1; i < n; i++) {
        key = arr[i];  // Armazena o elemento atual
        j = i - 1;

        // Move os elementos maiores que o key para a direita
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        // Insere o key na posição correta
        arr[j + 1] = key;
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

    // Ordena o vetor com Insertion Sort
    insertionSort(arr, n);

    printf("Vetor ordenado com Insertion Sort: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
