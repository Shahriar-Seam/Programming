#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fs, *fd;
    char fs_name[256], fd_name[256], ch;

    printf("Enter source file path:\n");
    gets(fs_name);
    printf("Enter destination path:\n");
    gets(fd_name);

    fs = fopen(fs_name, "rb");

    if (fs == NULL) {
        perror("File opening failed");
        return EXIT_FAILURE;
    }

    fd = fopen(fd_name, "wb");

    if (fs == NULL) {
        perror("File opening failed");
        return EXIT_FAILURE;
    }

    while (1) {
        ch = fgetc(fs);

        if (ch == EOF) {
            break;
        }

        fputc(ch, fd);
    }

    fclose(fs);
    fclose(fd);

    return 0;
}