#include <stdio.h>
#include <stdlib.h>

struct Marks {
    char name[100];
    int m1, m2, m3;
};

int main()
{
    struct Marks m[10];
    int i, max, max_i = 0;

    for (i = 0; i < 4; i++) {
        gets(m[i].name);
        scanf("%d %d %d", &m[i].m1, &m[i].m2, &m[i].m3);
        getchar();
    }

    printf("\n");

    max = m[0].m1 + m[0].m2 + m[0].m3;

    for (i = 0; i < 4; i++) {
        if (m[i].m1 + m[i].m2 + m[i].m3 > max) {
            max = m[i].m1 + m[i].m2 + m[i].m3;
            max_i = i;
        }
    }

    printf("name = %s\nmarks = %d\n", m[max_i].name, max);

    return 0;
}