/**
 *    author:  Anonymous_HF
 *    created: 24/05/2024
**/

#include <stdio.h>
#include <stdarg.h>
#include <limits.h>

int min(int a, int b)
{
  return a < b ? a : b;
}

int _min(int count, ...)
{
    int i, min_value = INT_MAX;
    va_list ptr;

    va_start(ptr, count);

    for (i = 0; i < count; i++) {
        min_value = min(min_value, va_arg(ptr, int));
    }

    va_end(ptr);

    return min_value;
}

int main()
{
    int b = 0, s = 0, c = 0, i, cnt = 0;
    int nb, ns, nc, pb, ps, pc;
    long long int r, count = 0;
    int x, y, z;
    char str[102];

    gets(str);
    scanf("%d %d %d", &nb, &ns, &nc);
    scanf("%d %d %d", &pb, &ps, &pc);
    scanf("%lld", &r);

    for (i = 0; str[i] != '\0'; i++) {
        b += (str[i] == 'B');
        s += (str[i] == 'S');
        c += (str[i] == 'C');
    }

    if (b == 0) {
        x = 0;
    }
    else {
        x = nb / b;
    }
    if (s == 0) {
        y = 0;
    }
    else {
        y = ns / s;
    }
    if (c == 0) {
        z = 0;
    }
    else {
        z = nc / c;
    }

    if (b == 0 && s == 0) {
        count += nc / c;
    }
    if (s == 0 && c == 0) {
        count += nb / b;
    }
    if (c == 0 && b == 0) {
        count += ns / s;
    }

    if (b == 0) {
        count += min(y, z);
    }
    if (s == 0) {
        count += min(x, z);
    }
    if (c == 0) {
        count += min(x, y);
    }
    
    nb -= b * count;
    ns -= s * count;
    nc -= c * count;

    x = y = z = 0;

    while ((nb != 0 || ns != 0 || nc != 0) && (r > 0)) {
        if (b == 0 || s == 0 || c == 0) {
            break;
        }
        if (nb != 0 || ns != 0 || nc != 0) {
            if (nb < b) {
                if (r >= (b - nb) * pb) {
                    r -= (b - nb) * pb;

                    nb = b;
                }
            }
            if (ns < s) {
                if (r >= (s - ns) * ps) {
                    r -= (s - ns) * ps;

                    ns = s;
                }
            }
            if (nc < c) {
                if (r >= (c - nc) * pc) {
                    r -= (c - nc) * pc;

                    nc = c;
                }
            }
        }

        if (nb == x && ns == y && nc == z) {
            break;
        }

        if (b == 0) {
            x = 0;
        }
        else {
            x = nb / b;
        }
        if (s == 0) {
            y = 0;
        }
        else {
            y = ns / s;
        }
        if (c == 0) {
            z = 0;
        }
        else {
            z = nc / c;
        }
        
        cnt = _min(3, x, y, z);
        
        nb -= b * cnt;
        ns -= s * cnt;
        nc -= c * cnt;

        count += cnt;

        x = nb;
        y = ns;
        z = nc;
    }

    count += r / (1LL * (b * pb + s * ps + c * pc));

    printf("%lld\n", count);

    return 0;
}

// Dumb Dumb