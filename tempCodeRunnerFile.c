#include <stdio.h>
#include <string.h>

struct person {
    char add[100];
};

int main()
{
    struct person stu[10];
    int i, d, count = 0;

    for (i = 0; i < 3; i++) {
        gets(stu[i].add);
    }

    for (i = 1; i < 3; i++) {
        d = strcmp(stu[0].add, stu[i].add);

        if (d == 0) {
            count++;
        }
    }

    printf("Count = %d\n", count);

    return 0;
}