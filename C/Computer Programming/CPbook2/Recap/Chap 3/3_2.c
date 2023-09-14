#include <stdio.h>

int main()
{
    FILE *fp;
    char filename[] ="3_2_o.txt";

    fp = fopen(filename, "w");

    fprintf(fp, "1st line before closing file\n");
    fprintf(fp, "2nd line before closing file\n");

    fclose(fp);

    fprintf(fp, "Something after closing file\n");

    return 0;
}