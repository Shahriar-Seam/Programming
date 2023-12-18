#include <stdio.h>

int main()
{
    FILE *f_in, *f_out;
    
    f_in = fopen("c:\\Users\\Seam\\Desktop\\Programming\\input1.txt", "r");
    f_out = fopen("c:\\Users\\Seam\\Desktop\\Programming\\output1.txt", "w");

    if (f_in == NULL || f_out == NULL) {
        perror("Error opening file");
        return 1;
    }

    double sum_f = 0;
    double temp;
    int sum_i = 0;

    while (fscanf(f_in, "%lf", &temp) == 1) {
        if (temp == (int) temp) {
            sum_i += (int) temp;
        }
        else {
            sum_f += temp;
        }
    }

    fprintf(f_out, "Int = %d\nFloat = %lf\n", sum_i, sum_f);

    fclose(f_in);
    fclose(f_out);

    return 0;
}
