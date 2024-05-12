#include <stdio.h>

int __max(int a, int b)
{
  return a > b ? a : b;
}

int main()
{
    int n, k, cars = 0, temp;

    scanf("%d %d", &n, &k);

    while (k--) {
        scanf("%d", &temp);

        cars += temp - n;

        cars = __max(0, cars);
    }

    printf("%d\n", cars);

    return 0;
}