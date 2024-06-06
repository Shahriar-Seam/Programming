#include <stdio.h>
#include <string.h>

int power (int b, int p)
{
    int i, ans = 1;

    for (i = 0; i < p; i++) {
        ans *= b;
    }

    return ans;
}

int main()
{
    int i;
    char n[100002];
    
    gets(n);

    int len = strlen(n);

    int num = (n[len - 2] -'0') * 10 + (n[len - 1] - '0');

    puts(num % 4 == 0 ? "4" : "0");

    return 0;
}