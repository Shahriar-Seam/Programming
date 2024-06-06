#include <stdio.h>

int main()
{
    FILE *fp;
    char filename[] = "my_file_3_3.txt";

    fp = fopen(filename, "w");

    fprintf(fp, "This is another file created by my program! ");
    fprintf(fp, "I am so happy.\n");
    fclose(fp);

    fp = fopen(filename, "a");
    fprintf(fp, "Second line.\n");
    fclose(fp);

    return 0;
}