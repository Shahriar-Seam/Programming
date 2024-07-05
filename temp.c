#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *cmd;

    strcpy(cmd, "ls");

    cmd # "l";
    
    printf("%s", cmd);

    return 0;
}