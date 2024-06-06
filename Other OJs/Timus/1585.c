#include <stdio.h>
#include <string.h>

int _max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    int t, i, arr[3] = {}, max = 0;
    char *penguin[3] = {
        "Emperor Penguin",
        "Little Penguin",
        "Macaroni Penguin",
    };
    char s[20];

    scanf("%d", &t);
    getchar();

    for (i = 0; i < t; i++) {
        gets(s);

        if (strcmp(s, "Emperor Penguin") == 0) {
            arr[0]++;
        }
        else if (strcmp(s, "Little Penguin") == 0) {
            arr[1]++;
        }
        else {
            arr[2]++;
        }

        max = _max(max, _max(arr[0], _max(arr[1], arr[2])));
    }

    for (i = 0; i < 3; i++) {
        if (arr[i] == max) {
            puts(penguin[i]);
        }
    }

    return 0;
}