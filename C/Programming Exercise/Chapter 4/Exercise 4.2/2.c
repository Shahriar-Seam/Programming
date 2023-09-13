#include <stdio.h>

int main()
{
    int papers[3][7];
    int i, j, k;
    char newspaper[3][100] = {"Ajker Khobor", "Shokal Sondha", "Bangladesh News"};
    int totals[3] = {0};
    int sale[3];

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 7; j++) {
            scanf("%d", &papers[i][j]);
        }
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 7; j++) {
            totals[i] += papers[i][j];
        }
    }

    sale[0] = totals[0] * 6;
    sale[1] = totals[1] * 10;
    sale[2] = totals[2] * 9;

    for (i = 0; i < 3; i++) {
        printf("Name: %s\tTotal sold:\t%d\tIncome:\t%d\n", newspaper[i], totals[i], sale[i]);
    }

    // for (i = 0; i < 3; i++) {
    //     for (j = 0; j < 7; j++) {
    //         printf("%d\t", papers[i][j]);
    //     }

    //     printf("\n");
    // }

    return 0;
}