#include <stdio.h>
#include <string.h>

int main()
{
    struct student {
        int id;
        char name[40];
    };

    struct student one;

    one.id = 230201;
    strcpy(one.name, "Ibnul Abrar Shahriar Seam");

    printf("ID: %d\n", one.id);
    printf("Name: %s\n", one.name);

    return 0;
}