#include <stdio.h>

int main()
{
    FILE *fp;
    char filename[] = "my_file_3_2.txt";

    fp = fopen(filename, "w");

    fprintf(fp, "This is another file created by my program! ");
    fprintf(fp, "I am so happy.\n");
    fclose(fp);
    fprintf(fp, "Second line.\n");

    return 0;
}