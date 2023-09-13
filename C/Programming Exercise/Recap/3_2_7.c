#include <stdio.h>
#include <string.h>

void encrypt(char str[], int n)
{
    int i, len;
    len = strlen(str);

    for (i = 0; i < len; i++) {
        if (str[i] >= 'a' && str[i] <= 'z' - n) {
            str[i] += n;
        }
        else {
            str[i] -= 26 - n;
        }
    }

    printf("%s", str);

    return;
}

int main()
{
    char msg[100];
    int n;

    printf("Enter message:\n");
    gets(msg);

    printf("Enter a number: ");
    scanf("%d", &n);

    encrypt(msg, n);

    return 0;
}