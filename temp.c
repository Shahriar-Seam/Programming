#include <stdio.h>

void printPattern(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int min = i < j ? i : j;
            int value = n - min + 1;
            printf("%d ", value);
        }
        for (int j = n - 1; j >= 1; j--) {
            int min = i < j ? i : j;
            int value = n - min + 1;
            printf("%d ", value);
        }
        printf("\n");
    }

    for (int i = n - 1; i >= 1; i--) {
        for (int j = 1; j <= n; j++) {
            int min = i < j ? i : j;
            int value = n - min + 1;
            printf("%d ", value);
        }
        for (int j = n - 1; j >= 1; j--) {
            int min = i < j ? i : j;
            int value = n - min + 1;
            printf("%d ", value);
        }
        printf("\n");
    }
}

int main() {
    int n = 5;  // You can change this value to adjust the size of the pattern
    printPattern(n);

    return 0;
}
