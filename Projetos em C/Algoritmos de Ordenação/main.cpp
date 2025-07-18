#include <iostream>
#include <vector>
#include <string>

// Protótipos das funções
void printArray(const std::string& label, const std::vector<int>& arr);
void troca(int* a, int* b);

// --- Algoritmos de Ordenação ---
void bubbleSort(std::vector<int>& arr);
void selectionSort(std::vector<int>& arr);
void heapSort(std::vector<int>& arr);
void descer(std::vector<int>& arr, int n, int i);


int main() {
    std::vector<int> originalArr = {64, 34, 25, 12, 22, 11, 90, 5};

    std::cout << "--- Comparativo de Algoritmos de Ordenacao ---" << std::endl;
    printArray("Array Original", originalArr);
    std::cout << "-----------------------------------------------" << std::endl;

    // 1. Testando o Bubble Sort
    std::vector<int> bubbleArr = originalArr;
    bubbleSort(bubbleArr);
    printArray("Ordenado com Bubble Sort (O(n^2))", bubbleArr);

    // 2. Testando o Selection Sort
    std::vector<int> selectionArr = originalArr;
    selectionSort(selectionArr);
    printArray("Ordenado com Selection Sort (O(n^2))", selectionArr);
    
    // 3. Testando o HeapSort
    std::vector<int> heapArr = originalArr;
    heapSort(heapArr);
    printArray("Ordenado com HeapSort (O(n log n))", heapArr);
    
    std::cout << "-----------------------------------------------" << std::endl;

    return 0;
}

void printArray(const std::string& label, const std::vector<int>& arr) {
    std::cout << label << ": ";
    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void troca(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                troca(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void selectionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if(min_idx != i) {
            troca(&arr[i], &arr[min_idx]);
        }
    }
}

void heapSort(std::vector<int>& arr) {
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--) {
        descer(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        troca(&arr[0], &arr[i]);
        descer(arr, i, 0);
    }
}

void descer(std::vector<int>& arr, int n, int i) {
    int maior = i;
    int esq = 2 * i + 1;
    int dir = 2 * i + 2;

    if (esq < n && arr[esq] > arr[maior]) {
        maior = esq;
    }

    if (dir < n && arr[dir] > arr[maior]) {
        maior = dir;
    }

    if (maior != i) {
        troca(&arr[i], &arr[maior]);
        descer(arr, n, maior);
    }
}
