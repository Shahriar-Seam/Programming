#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *cmd;

    strcpy(cmd, "ls");

    system(cmd);

    return 0;
}