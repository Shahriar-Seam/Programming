#include <stdio.h>

int main()
{
    char name[100];
    double salary_i, sales, salary_f;

    scanf("%s %lf %lf", name, &salary_i, &sales);

    salary_f = salary_i + sales * 0.15;

    printf("TOTAL = R$ %0.2lf\n", salary_f);

    return 0;
}