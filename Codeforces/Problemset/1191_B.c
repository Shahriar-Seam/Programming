#include <stdio.h>
#include <string.h>

void swap(int *a, int *b)
{
    *a ^= *b ^= *a ^= *b;
}

void sort(int *a, int *b, int *c)
{
    if (*a > *b) {
        swap(a, b);
    }
    if (*b > *c) {
        swap(b, c);
    }
    if (*a > *b) {
        swap(a, b);
    }
}

int shuntsu(char *s1, char *s2, char *s3)
{
    if (s1[1] == s2[1] && s2[1] == s3[1]) {
        int a = s1[0] - '0';
        int b = s2[0] - '0';
        int c = s3[0] - '0';

        sort(&a, &b, &c);

        if (c - b == 1 && b - a == 1) {
            return 1;
        }
        else {
            return 0;
        }
    }
    else {
        return 0;
    }
}

int main()
{
    char s1[3], s2[3], s3[3];

    scanf("%s %s %s", s1, s2, s3);

    // Koutsu
    if ((strcmp(s1, s2) == 0) && (strcmp(s2, s3) == 0)) {
        printf("0");
    }
    // Shuntsu
    else if (shuntsu(s1, s2, s3)) {
        printf("0");
    }
    else if (!strcmp(s1, s2) || !strcmp(s1, s3) || !strcmp(s2, s3)) {
        printf("1");
    }
    else if ((s1[1] == s2[1]) || (s2[1] == s3[1]) || (s1[1] == s3[1])) {
        if (s1[1] == s2[1]) {
            if (s1[0] - '0')
        }
    }
    else {
        printf("2");
    }

    return 0;
}