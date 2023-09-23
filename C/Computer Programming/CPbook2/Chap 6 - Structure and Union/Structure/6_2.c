#include <stdio.h>

int main()
{
    struct student {
        int id;
        char *name;
    };

    struct student one;

    one.id = 230201;
    one.name = "Ibnul Abrar Shahriar Seam";

    printf("ID: %d\n", one.id);
    printf("Name: %s\n", one.name);

    return 0;
}