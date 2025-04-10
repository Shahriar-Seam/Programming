#include <stdio.h>
#include <stdint.h>

int read()
{
    int n = 0;
    char c;

    while ((c = getchar()) && (c != '\n' && c != -1 && c != ' ')) {
        n *= 10;
        n += c - '0';
    }

    return n;
}

int32_t main()
{
    int n, k, t, count = 0;

    n = read() + 1;
    k = read();
    
    while (--n) {
        t = read();

        count += !(t % k);
    }

    printf("%d\n", count);

    return 0;
}