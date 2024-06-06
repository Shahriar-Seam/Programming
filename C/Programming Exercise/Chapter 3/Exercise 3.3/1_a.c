#include <stdio.h>

int main()
{
    int n, i, j, k;
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        for (j = i; j <= n - 1; j++) {
            printf(" ");
        }
        for (k = 1; k <= i; k++) {
            printf("*");
        }

        printf("\n");
    }

    return 0;
}

/*
When n = 4;
Primary loop:
    i = 1, Hence, i <= 4, Hence program will go into loop. (i indicates row.)
    secondary loop 1:
        j = 1, i = 1, n = 4,
            1 <= 4 - 1 = 3, Hence j <= 3. program will go into loop. (j indicates number os spaces)
        print 1 space.
        j = j + 1 = 1 + 1 = 2

        2 <= 3 Hence program will go into loop
        print another space. {total 2 spaces.}
        j = j + 1 = 2 + 1 = 3

        3 <= 3 Hence program will go into loop
        print another space. {total 3 spaces.}
        j = j + 1 = 3 + 1 = 4
        4 !<= 3. Break loop.
    
    secondary loop 2:
        k = 1, i = 1
            1 <= 1, k <= i. program will go into loop. (k indicates number of *)
        print *
        k = k + 1 = 1 + 1 = 2
        2 !<= 1, k !<= i. Break loop.

    program prints 3 spaces and 1 * and a newline in 1st line. "   *\n"

    i = i + 1 = 1 + 1 = 2;
    2 <= 4. Program goes into primary loop again.
        REPEAT... until i !<= n.
so, for n = 4, the pattern is
   *
  **
 ***
****

*/