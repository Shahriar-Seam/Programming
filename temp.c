#include <stdio.h>

struct DateOfBirth
{
    int year, month, day;
};

struct gpas
{
    float ygpas[4];
};

struct Student
{
    char sname[100];
    int sid;
    char dname[100];
    float cgpa;

    struct DateOfBirth dob[2];
    struct gpas v;
} v2;

struct Student v1;

int main()
{
    struct Student s[1000];
    int i = 0;

    scanf("%d", &v2.dob[0].year);
    printf("%d\n", v2.dob[0].year);

    scanf("%f", &s[9].v.ygpas[1]);

    printf("%f\n", s[9].v.ygpas[1]);

    return 0;
}