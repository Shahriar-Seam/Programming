#include <stdio.h>

int string_length(char str[])
{
    int i = 0;

    // for (i = 0; str[i] != '\0' ; i++);

    while (str[i] != '\0') i++;
    
    return i;
}

int main()
{
    char str[100];
    int len;

    while (NULL != gets(str)) {
        len = string_length(str);
        printf("Length: %d\n", len);
    }
    

    return 0;
}