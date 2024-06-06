#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int a;
    int b;
} software;

int compare (const void *a, const void *b)
{
    return ((software *) a) -> a - ((software *) b) -> a;
}

int main()
{
    int t, n, k, i;
    software *s;

    scanf("%d", &t);

    while (t--) {
        scanf("%d %d", &n, &k);

        s = (software *) calloc(n, sizeof(software));

        for (i = 0; i < n; i++) {
            scanf("%d", &s[i].a);
        }
        for (i = 0; i < n; i++) {
            scanf("%d", &s[i].b);
        }

        qsort(s, n, sizeof(software), compare);

        
        for (i = 0; i < n; i++) {
            if (s[i].a <= k) {
                k += s[i].b;
            }
            else {
                break;
            }
        }

        printf("%d\n", k);

        free(s);
    }

    return 0;
}