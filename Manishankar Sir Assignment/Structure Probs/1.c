#include <stdio.h>
#include <stdlib.h>

struct Student {
    char name[100];
    int id;
};

int main()
{
    struct Student s[10];
    int i;
    char temp[10];

    for (i = 0; i < 10; i++) {
        gets(s[i].name);
        scanf("%d", &s[i].id);
        getchar();
    }

    printf("\n");

    for (i = 0; i < 10; i++) {
        printf("%s\n", s[i].name);
        printf("%d\n", s[i].id);
    }

    return 0;
}