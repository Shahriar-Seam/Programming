#include <stdio.h>
#include <string.h>

void move(char *str, int n, int len)
{
    int i;
    
    for (i = n; i < len; i++) {
        str[i] = str[i + 1];
    }
}

int main() {
    char str[100];
    
    gets(str);
    
    int i, j = 0, len = strlen(str);
    
    for (i = 0; i < len; i++) {
        if (str[i] == 'a' && str[i + 1] == 'b' && str[i + 2] == 'c') {
            str[i] = 'c';
            str[i + 1] = 'd';
            
            i++;
            
            move(str, i + 1, len--);
        }
    }

    str[++len] = '\0';
    
    puts(str);

    return 0;
}