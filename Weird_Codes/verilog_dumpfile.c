#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void clean_dump(char *dump, char *filename)
{
    char temp_dump[500], temp_file[500];
    int i, j, len = strlen(filename);

    for (i = 0, j = 0; dump[i] != '\0'; i++) {
        if (dump[i] == '\"') {
            i++;

            while (dump[i] != '\0' && dump[i] != '\"') {
                temp_dump[j++] = dump[i++];
            }

            break;
        }
    }

    temp_dump[j] = '\0';

    strcpy(temp_file, filename);

    for (i = len - 1; i >= 0; i--) {
        if (temp_file[i] == '\\') {
            break;
        }
        else {
            temp_file[i] = '\0';
        }
    }

    strcat(temp_file, temp_dump);

    strcpy(dump, temp_file);
}

int main(int argc, char *argv[])
{
    char s[500];
    char filename[500], dumpfile[500];

    strcpy(filename, argv[1]);

    FILE *fp = fopen(filename, "r");

    while (fgets(s, 500, fp) != NULL) {
        printf("%s", s);

        if (strstr(s, "$dumpfile") != NULL) {
            strcpy(dumpfile, s);

            break;
        }
    }

    printf("\n\ndump = %s\n", dumpfile);

    clean_dump(dumpfile, filename);

    printf("\n\ndump = %s\n", dumpfile);

    return 0;
}