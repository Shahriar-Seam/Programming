#include <stdio.h>

int main()
{
    FILE *fp;
    char *fname = "Input.txt";
    char c;

    printf("Data Input\n\n");

    fp = fopen(fname, "w");

    while ((c = getchar()) != EOF) {
        putc(c, fp);
    }

    fclose(fp);

    printf("Data Output\n\n");

    fp = fopen(fname, "r");

    while ((c = getc(fp)) != EOF) {
        printf("%c", c);
    }

    fclose(fp);

    return 0;
}