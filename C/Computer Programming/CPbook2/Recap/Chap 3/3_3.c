#include <stdio.h>

int main()
{
    FILE *fp;
    char filename[] = "3_3_o.txt";

    fp = fopen(filename, "w");

    fprintf(fp, "Something before closing the file\n");
    fprintf(fp, "Something else before closing the file\n\n");

    fclose(fp);

    fp = fopen(filename, "a");

    fprintf(fp, "Something totally different after closing and reopening the file\n");

    fclose(fp);

    return 0;
}