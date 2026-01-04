#include <stdio.h>

void inorder(int tree[], int n, int index) {
    if (index < n && tree[index] != -1) {
        inorder(tree, n, 2 * index + 1);
        printf("%d ", tree[index]);
        inorder(tree, n, 2 * index + 2);
    }
}

int main() {
    int n;
    printf("Agac toplam kac elemanli olacak (bos yerler icin -1): ");
    scanf("%d", &n);

    int tree[n];
    printf("%d adet elemani sirayla girin:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &tree[i]);
    }

    printf("Inorder: ");
    inorder(tree, n, 0);
    printf("\n");

    return 0;
}
