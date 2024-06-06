// Delete doesn't work :(

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char mode;
    char name[33];
    int counter;
} database;

void fill(database *data, int n)
{
    int i;

    for (i = 0; i < n; i++) {
        data[i].counter = 0;
    }
}

int find(char *s, database *data, int size)
{
    int i, index = size;

    for (i = 0; i < size; i++) {
        if (strcmp(s, data[i].name) == 0) {
            index = i;
        }
    }

    return index;
}

int main()
{
    int n, i;
    char ch;
    char name[33];

    scanf("%d", &n);
    getchar();

    database data[n];

    fill(data, n);

    for (i = 0; i < n; i++) {
        scanf(" %c %s", &ch, name);

        data[i].mode = ch;
        strcpy(data[i].name, name);

        if (i == 0) {
            data[i].counter = 1;
        }
        else {
            if (ch == 'a') {
                int index = find(data[i].name, data, i);

                data[i].counter = data[index].counter + 1;
            }
            else {
                data[i].counter = 0;
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
