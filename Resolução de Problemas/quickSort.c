#include <stdio.h>

// Função auxiliar para o Quick Sort (partição)
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Pivô é o último elemento
    int i = low - 1;
    int temp;

    // Organiza os elementos com relação ao pivô
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            // Troca arr[i] com arr[j]
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Troca o pivô com o elemento arr[i+1]
    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

// Função para ordenar o vetor com Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Encontra o ponto de partição
        int pi = partition(arr, low, high);

        // Ordena recursivamente as duas metades
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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

    // Ordena o vetor com Quick Sort
    quickSort(arr, 0, n - 1);

    printf("Vetor ordenado com Quick Sort: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
