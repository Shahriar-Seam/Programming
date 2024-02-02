#include <stdio.h>
#include <string.h>

void solve()
{
    char str[200005];
    int i, one = 0, zero = 0, len = 0;

    gets(str);

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == '0') {
            zero++;
        }
        else {
            one++;
        }
    }

    len = i;

    for (i = 0; i < len; i++) {
        if ((zero > 0) && (str[i] == '1')) {
            zero--;
        }
        else if ((one > 0) && (str[i] == '0')) {
            one--;
        }
        else {
            break;
        }
    }

    printf("%d\n", len - i);
}

int main()
{
    int t;

    scanf("%d", &t);
    getchar();

    while (t--) {
        solve();
    }

    return 0;
}