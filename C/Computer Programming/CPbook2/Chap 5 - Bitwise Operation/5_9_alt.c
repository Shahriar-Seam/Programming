#include <stdio.h>
#include <string.h>

void dec_to_bin(int n, char str[])
{
    int i, r;

    str[8] = '\0';
    for (i = 7; i >= 0; i--) {
        r = n % 2;
        str[i] = r + '0';
        n /= 2;
    }
}

int count_1(char str[]) {
    int i, count = 0;

    for (i = 0; i < 8; i++) {
        if (str[i] == '1') {
            count++;
        }
    }

    return count;
}

int main()
{
    int n, count;
    char str[9];

    scanf("%d", &n);

    dec_to_bin(n, str);

    count = count_1(str);

    printf("Binary of %d is %s\n", n, str);
    printf("Total 1's in %d's binary: %d\n", n, count);

    return 0;
}