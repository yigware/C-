#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 500
#define RANGE 1001

// Dizi elemanlarýný en büyükten en küçüðe doðru sýralayan bir yardýmcý fonksiyon
void sortDescending(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Diziyi istenen biçimde sýralayan fonksiyon
void specialSort(int arr[], int n) {
    sortDescending(arr, n);

    int* temp = (int*)malloc(n * sizeof(int));
    int i, j = 0, k = n - 1;

    for (i = 0; i < n; i++) {
        if (i % 2 == 0) {
            temp[i] = arr[j++];
        }
        else {
            temp[i] = arr[k--];
        }
    }

    // Temp dizisini orijinal diziye kopyalama
    for (i = 0; i < n; i++) {
        arr[i] = temp[i];
    }

    free(temp);
}


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
    int arr[SIZE];

    srand(time(NULL));

    generateRandomArray(arr, SIZE, RANGE);

    printf("Orijinal dizi:\n");
    printArray(arr, SIZE);

    specialSort(arr, SIZE);

    printf("Özel sýralanmýþ dizi:\n");
    printArray(arr, SIZE);

    return 0;
}