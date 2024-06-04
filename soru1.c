#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Dizi eleman sayýsý
#define SIZE 500

// Rastgele sayý oluþturma aralýðý
#define RANGE 1001

// Birleþtirmeli Sýralama (Insertion Sort) fonksiyonu
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Seçmeli Sýralama (Selection Sort) fonksiyonu
void selectionSort(int arr[], int n) {
    int i, j, min_idx, temp;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

// Rastgele dizi oluþturma fonksiyonu
void generateRandomArray(int arr[], int size, int range) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % range;
    }
}

// Dizi yazdýrma fonksiyonu
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr1[SIZE], arr2[SIZE];

    // Rastgele sayý üreticisini baþlatma
    srand(time(NULL));

    // Rastgele diziyi oluþtur ve iki diziye kopyala
    generateRandomArray(arr1, SIZE, RANGE);
    for (int i = 0; i < SIZE; i++) {
        arr2[i] = arr1[i];
    }

    clock_t start, end;
    double insertionSortTime, selectionSortTime;

    // Birleþtirmeli Sýralama zaman ölçümü
    start = clock();
    insertionSort(arr1, SIZE);
    end = clock();
    insertionSortTime = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Seçmeli Sýralama zaman ölçümü
    start = clock();
    selectionSort(arr2, SIZE);
    end = clock();
    selectionSortTime = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Sonuçlarý ekrana yazdýr
    printf("Birleþtirmeli Sýralama süresi: %f saniye\n", insertionSortTime);
    printf("Seçmeli Sýralama süresi: %f saniye\n", selectionSortTime);

    return 0;
}