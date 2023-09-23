#include <stdio.h>
#include <string.h>

struct nametype {
    char first[40];
    char last[40];
};

struct student {
    int id;
    struct nametype name;
};

int main()
{
    struct student one;

    scanf("%d", &one.id);
    getchar();
    gets(one.name.first);
    gets(one.name.last);

    printf("ID: %d\n", one.id);
    printf("Name: %s %s\n", one.name.first, one.name.last);

    return 0;
}