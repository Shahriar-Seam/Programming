#include <stdio.h>

int main()
{
    int n, number, min, max;

    scanf("%d", &n);
    scanf("%d", &number);

    max = min = number;

    for (int i = 1; i < n; i++) {
        scanf("%d", &number);
        if (number > max) {
            max = number;
        }
        if (number < min) {
            min = number;
        }
    }

    printf("Maximum: %d\n", max);
    printf("Minimum: %d\n", min);

    return 0;
}

// Explanation by ChatGPT
// https://chat.openai.com/share/51b86131-c3f6-4f74-a39d-bc72c64ab557 