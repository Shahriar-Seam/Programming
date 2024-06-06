#include <stdio.h>
#include <stdlib.h>

struct Student {
    char name[100];
    int id;
};

int main()
{
    struct Student s[10];
    int i, key; // Key needs to be found in the structure array
    char temp[10];

    for (i = 0; i < 10; i++) {
        gets(s[i].name);
        scanf("%d", &s[i].id);
        getchar();
    }

    puts("Enter key: ");
    scanf("%d", &key);

    printf("\n");

    for (i = 0; i < 10; i++) {
        if (s[i].id == key) {
            printf("%s\n", s[i].name);
            break;
        }
    }

    return 0;
}