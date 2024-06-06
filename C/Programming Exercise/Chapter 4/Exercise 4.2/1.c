// IT WORKS 
// Took 1 hour and 15 minutes... -_-

#include <stdio.h>

void transpose(int arr1[12][2], int arr2[2][12])
{
    int i, j;

    for (i = 0; i < 12; i++) {
        for (j = 0; j < 2; j++) {
            arr2[j][i] = arr1[i][j];
        }
    }
}

void totals(int noodles[12][2], int total[2])
{
        int i;

    for (i = 0; i < 12; i++) {
        total[0] += noodles[i][0];
    }

    for (i = 0; i < 12; i++) {
        total[1] += noodles[i][1];
    }

    return;
}

void most_sales(int noodles[12][2])
{
    int total[2];

    totals(noodles, total);

    if (total[0] > total[1]) {
        printf("Vishon Moja noodles was sold most.\n");
    }
    else if (total[0] < total[1]) {
        printf("Ekhoni Khabo noodles was sold most.\n");
    }
    else {
        printf("Both were sold equally.\n");
    }

    return;
}

void best_selling_month(int noodles[12][2])
{
    char month[12][100] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int i, j, sum, max_sold = 0, max_index;
    int trans_noodles[2][12];

    transpose(noodles, trans_noodles);

    for (i = 0; i < 12; i++) {
        sum = 0;

        for (j = 0; j < 2; j++) {
            sum += trans_noodles[j][i];
        }

        if (sum > max_sold) {
            max_sold = sum;
            max_index = i;
        }
    }

    printf("Best selling month: %s\n", month[max_index]);

    return;
}

void total_sale(int noodles[12][2])
{
    int total[2] = {0};

    totals(noodles, total);

    printf("Vishon Moja: %d\n", total[0] * 37);
    
    printf("Ekhoni Khabo: %d\n", total[1] * 34);
}

void sales_in_three_months(int noodles[12][2])
{
    int i, j, sum = 0, k = 0, thirds[4] = {0};

    for (i = 0; i < 12; i++) {
        
        sum += (noodles[i][0] * 37) + (noodles[i][1] * 34);

        if ((i + 1) % 3 == 0) {
            thirds[k] = sum;
            sum = 0;
            k++;
        }
    }

    for (k = 0; k < 4; k++) {
        printf("period %d: %d\n", k + 1, thirds[k]);
    }

    return;
}

int main()
{
    int noodles[12][2];
    int i, j;

    for (i = 0; i < 12; i++) {
        for (j = 0; j < 2; j++) {
            scanf("%d", &noodles[i][j]);
        }
    }

    printf("\n");
    
    for (i = 0; i < 12; i++) {
        for (j = 0; j < 2; j++) {
            printf("%d ", noodles[i][j]);
        }

        printf("\n");
    }

    most_sales(noodles);

    best_selling_month(noodles);

    total_sale(noodles);

    sales_in_three_months(noodles);

    return 0;
}