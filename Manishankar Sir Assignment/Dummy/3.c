#include <stdio.h>
#include <string.h>

void rmv(char *str, int count)
{
    int i, len = strlen(str);
    
    for (i = 0; i <= strlen(str); i++) {
        str[i] = str[i + count];
    }
    
    for (i = strlen(str) - 1; i > 0; i--) {
        if (str[i] != '0') {
            str[i + 1] = '\0';
            break;
        }
    }
}

int main() {
    char str[100];
    
    gets(str);
    
    int i, count = 0;
    
    for (i = 0; i < strlen(str); i++) {
        if (str[i] != '0') {
            break;
        }
        else{
            count++;
        }
    }
    
    rmv(str, count);
    
    puts(str);

    return 0;
}