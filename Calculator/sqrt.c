#include <stdio.h>

double sqrt(double n)
{
    double l = 0, r = n, root = n / 2;
    double precision = 0.000005;

    while (l < r) {
        root = (l + r) / 2;

        if (root * root > n) {
            r = root - precision;
        }
        else if (root * root < n) {
            l = root + precision;
        }
        else {
            return root;
        }
    }

    return root;
}

int main()
{
    double n;

    scanf("%lf", &n);

    printf("%.4lf\n", sqrt(n));

    return 0;
}