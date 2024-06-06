#include <stdio.h>
#include <string.h>

char str[102];

void rev_str(int i)
{

    if (i < 0) {
        return;
    }

    printf("%c", str[i]);

    rev_str(i - 1);
}

int main()
{
    scanf("%s", str);

    int len = strlen(str);

    rev_str(len);

    return 0;
}