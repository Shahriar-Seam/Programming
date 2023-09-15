#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp = fopen("3_7_i.txt", "r");

    if (fp == NULL) {
        perror("Can't open file");
        return EXIT_FAILURE;
    }

    int ch;

    ch = fgetc(fp);
    printf("%c\n", ch);
    ch = fgetc(fp);
    printf("%c\n", ch);

    fseek(fp, sizeof(char) * 3, SEEK_CUR);
    ch = fgetc(fp);
    printf("%c\n", ch);

    fclose(fp);

    return 0;
}