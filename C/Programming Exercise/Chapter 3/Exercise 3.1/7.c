#include <stdio.h>
#include <math.h>

int main()
{
    char c;
    int num = 0;

    for (int i = 1; ; i++) {
        scanf(" %c", &c);
        if (c == '0') {
            break;
        }
        num = num + (c - '0') * pow(10, i);
    }
    
    printf("%d", num % 6);

    return 0;
}