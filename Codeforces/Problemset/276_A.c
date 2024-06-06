#include <stdio.h>
#include <limits.h>

int _max(int a, int b)
{
  return a > b ? a : b;
}

int main()
{
    int n, k, f, t, max_joy = INT_MIN;

    scanf("%d %d", &n, &k);

    while (n--) {
        scanf("%d %d", &f, &t);

        if (t > k) {
            max_joy = _max(max_joy, f - (t - k));
        }
        else {
            max_joy = _max(max_joy, f);
        }
    }

    printf("%d\n", max_joy);

    return 0;
}