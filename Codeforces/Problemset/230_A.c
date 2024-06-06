#include <stdio.h>
#include <stdlib.h>

#define yes printf("YES")
#define no printf("NO")

typedef struct {
    int strength;
    int bonus_strength;
} array_type;

int compare(const void *a, const void *b)
{
    return ((array_type *)a)->strength - ((array_type *) b)->strength;
}

int main()
{
    int n, s, i, f = 1;

    scanf("%d %d", &s, &n);

    array_type dragons[n];

    for (i = 0; i < n; i++) {
        scanf("%d %d", &dragons[i].strength, &dragons[i].bonus_strength);
    }

    qsort(dragons, n, sizeof(array_type), compare);

    for (i = 0; i < n; i++) {
        if (dragons[i].strength < s) {
            s += dragons[i].bonus_strength;
        }
        else {
            f = 0;
            break;
        }
    }

    f ? yes : no;

    return 0;
}