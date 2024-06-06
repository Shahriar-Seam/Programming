#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp_data, *fp_even, *fp_odd;
    char *fname_data = "data.txt";
    char *fname_even = "even.txt";
    char *fname_odd = "odd.txt";
    int num;

    fp_data = fopen(fname_data, "w");

    if (fp_data == NULL) {
        perror("Error opening data file for writing");
        return EXIT_FAILURE;
    }

    printf("Enter data (Enter -1 to stop)\n\n");

    while (1) {
        if (scanf("%d", &num) == 1) {
            if (num == -1) {
                break;
            }

            fprintf(fp_data, "%d ", num);
        }
    }

    fclose(fp_data);

    fp_data = fopen(fname_data, "r");
    fp_even = fopen(fname_even, "w");
    fp_odd = fopen(fname_odd, "w");

    while (1) {
        if ((fscanf(fp_data, "%d", &num)) == EOF) break;

        if (num % 2 == 0) {
            fprintf(fp_even, "%d\n", num);
        }
        else {
            fprintf(fp_odd, "%d\n", num);
        }
    }

    printf("\nCheck even.txt and odd.txt for result\n");

    fclose(fp_data);
    fclose(fp_even);
    fclose(fp_odd);

    return 0;
}