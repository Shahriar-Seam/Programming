#include <stdio.h>

int main()
{
    int n, m, i, j, k;

    scanf("%d %d", &n, &m);

    int a[n], b[m], merged[n + m];

    for (i = 0; i < n; i++) {
        scanf("%d", a + i);
    }

    for (i = 0; i < m; i++) {
        scanf("%d", b + i);
    }

    for (i = 0, j = 0, k = 0; k < n + m; ) {
        if (i < n && j < m) {
            if (a[i] < b[j]) {
                merged[k++] = a[i++];
            }
            else {
                merged[k++] = b[j++];
            }
        }
        else if (i < n) {
            while (i < n) {
                merged[k++] = a[i++];
            }
        }
        else {
            while (j < m) {
                merged[k++] = b[j++];
            }
        }
    }

    for (k = 0; k < n + m; k++) {
        printf("%d ", merged[k]);
    }

    return 0;
}