#include <stdio.h>

int main()
{
    struct student {
        int id;
        char name[40];
    };

    struct student one;

    scanf("%d", &one.id);
    getchar();
    gets(one.name);

    printf("ID: %d\n", one.id);
    printf("Name: %s\n", one.name);

    return 0;
}