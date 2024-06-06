#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char mode;
    char name[33];
    int counter;
} database;

int max(int a, int b)
{
    return a > b ? a : b;
}

int find(char *s, database *data, int size)
{
    int i;

    for (i = size - 1; i >= 0; i--) {
        if (strcmp(s, data[i].name) == 0) {
            return data[i].counter;
        }
    }

    return 0;
}

int main()
{
    int n, i;
    char ch;
    char name[33];

    scanf("%d", &n);
    getchar();

    database data[n];

    for (i = 0; i < n; i++) {
        scanf(" %c %s", &ch, name);

        data[i].mode = ch;
        strcpy(data[i].name, name);

        if (i == 0) {
            data[i].counter = 1;
        }
        else {
            if (ch == 'a') {
                data[i].counter = find(data[i].name, data, i) + 1;
            }
            else {
                data[i].counter = max(0, find(data[i].name, data, i) - 1);
            }
        }
    }

    for (i = 0; i < n; i++) {
        if (data[i].mode == 'a') {
            if (data[i].counter == 1) {
                printf("OK\n");
            }
            else {
                printf("%s%d\n", data[i].name, data[i].counter - 1);
            }
        }
        else {
            printf("DELETED\n");
        }
    }
}
