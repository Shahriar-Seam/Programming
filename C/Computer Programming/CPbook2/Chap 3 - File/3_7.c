#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp = fopen("in_3_7.txt", "r");
    if (fp == NULL) {
        perror("Can't open file");
        return EXIT_FAILURE;
    }

    int ch;

    ch = fgetc(fp);
    printf("%c\n", (char) ch);
    ch = fgetc(fp);
    printf("%c\n", (char) ch);

    fseek(fp, 0, SEEK_CUR);
    ch = fgetc(fp);
    printf("%c\n", (char) ch);

    fclose(fp);

    return 0;
}

// SEEK_CUR, SEEK_END doesn't work. Dunno why. :(