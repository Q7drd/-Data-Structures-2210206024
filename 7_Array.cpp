#include <stdio.h>

void printArray(int arr[], int n) {
    printf("Dizi: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[100], n, pos, val, i;

    printf("Dizi boyutunu girin: ");
    scanf("%d", &n);

    printf("%d eleman girin:\n", n);
    for (i = 0; i < n; i++) scanf("%d", &arr[i]);
    printArray(arr, n);

 
    printf("\nEklenecek deger: ");
    scanf("%d", &val);
    printf("Hangi indekse eklensin (0-%d): ", n);
    scanf("%d", &pos);

    for (i = n; i > pos; i--) {
        arr[i] = arr[i - 1]; 
    }
    arr[pos] = val;
    n++;
    printArray(arr, n);

   
    printf("\nSilinecek indeks (0-%d): ", n - 1);
    scanf("%d", &pos);

    if (pos < n) {
        for (i = pos; i < n - 1; i++) {
            arr[i] = arr[i + 1]; 
        }
        n--;
    }
    printArray(arr, n);

    return 0;
}
