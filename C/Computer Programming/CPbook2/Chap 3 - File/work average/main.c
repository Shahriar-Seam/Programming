#include <stdio.h>

int main()
{
    FILE *fp_math, *fp_eng, *fp_ban, *fp_out;
    char *math = "math.txt", *eng = "english.txt", *ban = "bangla.txt", *out = "out.txt";

    fp_math = fopen(math, "r");
    fp_eng = fopen(eng, "r");
    fp_ban = fopen(ban, "r");
    fp_out = fopen(out, "w");

    int roll[10], marks[3][10];
    double average[10];

    for (int i = 0; i < 10; i++) {
        fscanf(fp_math, "%d %d", &roll[i], &marks[0][i]);
    }
    for (int i = 0; i < 10; i++) {
        fscanf(fp_eng, "%d %d", &roll[i], &marks[1][i]);
    }
    for (int i = 0; i < 10; i++) {
        fscanf(fp_ban, "%d %d", &roll[i], &marks[2][i]);
    }

    for (int i = 0; i < 10; i++) {
        average[i] = (marks[0][i] + marks[1][i] + marks[2][i]) / 3.0;
    }

    for (int i = 0; i < 10; i++) {
        fprintf(fp_out, "%d %0.0lf\n", roll[i], average[i]);
    }

    fclose(fp_math);
    fclose(fp_eng);
    fclose(fp_ban);
    fclose(fp_out);

    return 0;
}