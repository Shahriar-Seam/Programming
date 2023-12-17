#include <stdio.h>

struct student {
    char name[50];
    int roll;
    float cgpa;
};

int main()
{
    struct student saadiq;

    gets(saadiq.name);
    scanf("%d", &saadiq.roll);
    scanf("%f", &saadiq.cgpa);

    puts(saadiq.name);
    printf("%d\n", saadiq.roll);
    printf("%f\n", saadiq.cgpa);

    return 0;
}