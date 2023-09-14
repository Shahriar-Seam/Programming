#include <stdio.h>

int main()
{
    FILE *fp;
    char filename[] = "3_1_o.txt";

    fp = fopen(filename, "w");

    fprintf(fp, "This is a file created by a program\n");
    fprintf(fp, "This is just another line");

    fclose(fp);

    return 0;
}