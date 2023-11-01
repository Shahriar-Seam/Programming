#include <stdio.h>
#include <string.h>

void move(char *str, int n)
{
    int i, len = strlen(str);
    
    for (i = len; i > n; i--) {
        str[i] = str[i - 1];
    }
}

int main() {
    char str[100];
    
    gets(str);
    
    int i, j = 0;
    
    for (i = 0; i < strlen(str); i++) {
        if (str[i] == 'c' && str[i + 1] == 'd') {
            move(str, i);
            
            str[i++] = 'a';
            str[i++] = 'b';
            str[i] = 'c';
        }
    }
    
    puts(str);

    return 0;
}