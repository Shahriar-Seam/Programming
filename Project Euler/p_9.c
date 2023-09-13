#include <stdio.h>

int main() {
    int sum_value = 1000;

    for (int a = 1; a < sum_value; a++) {
        for (int b = a + 1; b < sum_value; b++) {
            int c = sum_value - a - b;
            if (a * a + b * b == c * c) {
                printf("Pythagorean triplet: %d, %d, %d\n", a, b, c);
                printf("The product abc is: %d\n", a * b * c);
                return 0;
            }
        }
    }

    printf("No Pythagorean triplet found that adds up to %d.\n", sum_value);
    return 0;
}

// I cheated