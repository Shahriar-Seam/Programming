#include <stdio.h>

int count_points(char mat[10][10])
{
    int i, j, count = 0;

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            if (mat[i][j] == 'X') {
                if ((i == 0) || (i == 9) || (j == 0) || (j == 9)) {
                    count++;
                }
                else if ((i == 1) || (i == 8) || (j == 1) || (j == 8)) {
                    count += 2;
                }
                else if ((i == 2) || (i == 7) || (j == 2) || (j == 7)) {
                    count += 3;
                }
                else if ((i == 3) || (i == 6) || (j == 3) || (j == 6)) {
                    count += 4;
                }
                else if ((i == 4) || (i == 5) || (j == 4) || (j == 5)) {
                    count += 5;
                }
            }
        }
    }

    return count;
}

int main()
{
    int t;
    char mat[10][10];
    int i, j;

    scanf("%d", &t);

    while (t--) {
        for (i = 0; i < 10; i++) {
            scanf(" %s", mat[i]);
        }

        printf("%d\n", count_points(mat));
    }
    

    return 0;
}