#include <stdio.h>

void hanoi(int n, char kaynak, char hedef, char yardimci) {
    if (n == 1) {
        printf("Disk 1: %c -> %c\n", kaynak, hedef);
        return;
    }
    hanoi(n - 1, kaynak, yardimci, hedef);
    printf("Disk %d: %c -> %c\n", n, kaynak, hedef);
    hanoi(n - 1, yardimci, hedef, kaynak);
}

int main() {
    int n;
    printf("Disk sayisini girin: ");
    scanf("%d", &n);
    
    hanoi(n, 'A', 'C', 'B');
    
    return 0;
}
