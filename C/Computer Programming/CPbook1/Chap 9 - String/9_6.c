#include <stdio.h>

int main()
{
    char arr[100];

    while (NULL != gets(arr)) {
        printf("%s\n", arr);
    }

    return 0;
}