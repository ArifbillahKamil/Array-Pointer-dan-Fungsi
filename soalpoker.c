#include <stdio.h>
#include <string.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printCard(int number) {
    if (number == 1) printf("1 ");
    else if (number == 2) printf("2 ");
    else if (number == 3) printf("3 ");
    else if (number == 4) printf("4 ");
    else if (number == 5) printf("5 ");
    else if (number == 6) printf("6 ");
    else if (number == 7) printf("7 ");
    else if (number == 8) printf("8 ");
    else if (number == 9) printf("9 ");
    else if (number == 10) printf("10 ");
    else if (number == 11) printf("J ");
    else if (number == 12) printf("Q ");
    else if (number == 13) printf("K ");
    else printf("%d ", number);
}

void sortCards(int n, int *arr) {
    int swaps = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swaps++;

                printf("Langkah %d: Pertukaran antara kartu %d (%c) dan kartu %d (%c)\n", swaps, j+1, arr[j], j+2, arr[j+1]);

                printf("Kartu setelah pertukaran %d: ", swaps);
                for (int k = 0; k < n; k++) {
                    printCard(arr[k]);
                }
                printf("\n");
            }
        }
    }

    printf("Jumlah pertukaran yang dilakukan : %d\n", swaps);
}

int main() {
    int n;
    printf("Masukkan jumlah kartu : ");
    scanf("%d", &n);
    
    int arr[n];
    char temp[3];
    printf("Masukkan angka kartu (1-10, J/Q/K) : ");
    for (int i = 0; i < n; i++) {
        scanf("%s", temp);
        if (strcmp(temp, "J") == 0) {
            arr[i] = 11;
        } else if (strcmp(temp, "Q") == 0) {
            arr[i] = 12;
        } else if (strcmp(temp, "K") == 0) {
            arr[i] = 13;
        } else {
            sscanf(temp, "%d", &arr[i]);
        }
    }

    sortCards(n, arr);

    return 0;
}