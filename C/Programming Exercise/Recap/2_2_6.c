#include <stdio.h>
#include <math.h>

int is_square(double n)
{
    double root;

    root = sqrt(n);

    if (pow(floor(root), 2) == n) {
        return 1;
    }

    if (pow(floor(root), 2) != n) {
        return 0;
    }
}

int main()
{
    double n, root;
    int s;

    while (1) {

        printf("Enter a number (Enter 0 to exit): ");
        scanf("%lf", &n);

        if (n == 0) {
            break;
        }

        root = sqrt(n);

        s = is_square(n);

        if (s == 1) {
            printf("%d is a square and it is the square of %d.\n", (int) n, (int) root);
        }

        if (s == 0) {
            printf("%d is not a perfect square but it is the square of %.16lf\n", (int) n, root);
        }
    }

    return 0;
}

// Saum er buddhite extra output dewa hoise.