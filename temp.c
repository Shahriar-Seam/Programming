#include <stdio.h>
#include <stdarg.h>
#include <limits.h>

int max(int a, int b)
{
  return a > b ? a : b;
}

int __max(int count, ...)
{
    int i, max_value = INT_MIN;
    va_list ptr;

    va_start(ptr, count);

    for (i = 0; i < count; i++) {
        max_value = max(max_value, va_arg(ptr, int));
    }

    va_end(ptr);

    return max_value;
}

int main()
{
    int a, b, c, d;

    scanf("%d %d %d %d", &a, &b, &c, &d);

    printf("%d\n", __max(5, -1, a, b, c, d));

    return 0;
}