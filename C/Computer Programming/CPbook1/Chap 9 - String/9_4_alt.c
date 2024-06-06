#include <stdio.h>

int main()
{
    char country[] = {'B', 'A', 'N', 'G', 'L', 'A', 'D', 'E', 'S', 'H', '\0'};
    int i = 0, length = 10;

    printf("%s\n", country);

    for (i; i < length; i++) {
        if (country[i] >= 'A' && country[i] <= 'Z') {
            country[i] = 'a' + (country[i] - 'A');
        }
    }

    printf("%s\n", country);

    return 0;
}