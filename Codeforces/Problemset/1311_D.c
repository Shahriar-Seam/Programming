#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

void solve()
{
    int a, b, c;
    int A, B, C;
    int i, j;
    int c1, c2;
    int count = INT_MAX;

    scanf("%d %d %d", &a, &b, &c);

    for (i = 1; i <= 2 * a; i++) {
        for (j = i; j <= 2 * b; j += i) {
            c1 = (c / j) * j;
            c2 = c1 + j;

            if (c1 >= j) {
                if (count > abs(i - a) +  abs(j - b) + abs(c1 - c)) {
                    count = abs(i - a) +  abs(j - b) + abs(c1 - c);

                    A = i;
                    B = j;
                    C = c1;
                }
            }
            
            if (c2 >= j) {
                if (count > abs(i - a) +  abs(j - b) + abs(c2 - c)) {
                    count = abs(i - a) +  abs(j - b) + abs(c2 - c);
                    
                    A = i;
                    B = j;
                    C = c2;
                }
            } // Always true
        }
    }

    printf("%d\n", count);
    printf("%d %d %d\n", A, B, C);
}

int main()
{
    int t;

    scanf("%d", &t);

    while (t--) {
        solve();
    }

    return 0;
}