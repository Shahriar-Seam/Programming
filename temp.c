#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char url[200];
    char cmd[500] = "yt-dlp ";
    char version[100];
    int op;

    FILE *fp = popen("yt-dlp --version", "r");

    if (fp == NULL) {
        printf("Error!");
    }
    else {
        int i = 1;
        while (fgets(version, 100, fp) != NULL) {
            i++;
        }

        if (i == 1) {
            system("winget install yt-dlp");

            puts("\nPlease restart shell. Then rerun the program.");

            return 0;
        }
    }
    
    puts("Enter url:\n");
    gets(url);

    strcat(cmd, url);
    strcat(cmd, " -f best -g");

    puts("\nExtracting urls to urls.txt file...\n");
    puts("It might be a lengthy process depending on playlist size.\n");

    freopen("urls.txt", "w", stdout);
    
    system(cmd);

    printf("\n\n---The End---\n");

    freopen("CON", "w", stdout);

    puts("\nExtraction complete\n");

    puts("Press 1 to show the links.\n");
    puts("Press any other key to exit the program.\n");

    scanf("%d", &op);

    if (op == 1) {
        system("type urls.txt");
    }

    return 0;
}