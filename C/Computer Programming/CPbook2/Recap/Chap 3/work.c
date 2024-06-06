#include <stdio.h>

int main()
{
    FILE *fp_english, *fp_physics, *fp_math, *fp_result;
    char *fname_english = "english.txt";
    char *fname_physics = "physics.txt";
    char *fname_math = "math.txt";
    char *fname_result = "result.txt";
    int arr_rolls[10], arr_english[10], arr_physics[10], arr_math[10], arr_result[10];
    int i;

    fp_english = fopen(fname_english, "r");
    fp_physics = fopen(fname_physics, "r");
    fp_math = fopen(fname_math, "r");
    fp_result = fopen(fname_result, "w");

    for (i = 0; i < 10; i++) {
        fscanf(fp_english, "%d %d", &arr_rolls[i], &arr_english[i]);
    }

    for (i = 0; i < 10; i++) {
        fscanf(fp_physics, "%d %d", &arr_rolls[i], &arr_physics[i]);
    }

    for (i = 0; i < 10; i++) {
        fscanf(fp_math, "%d %d", &arr_rolls[i], &arr_math[i]);
    }

    for (i = 0; i < 10; i++) {
        arr_result[i] = (arr_english[i] + arr_physics[i] + arr_math[i]) / 3.0;

        fprintf(fp_result, "%d %d\n", arr_rolls[i], arr_result[i]);
    }

    fclose(fp_english);
    fclose(fp_physics);
    fclose(fp_math);
    fclose(fp_result);

    return 0;
}