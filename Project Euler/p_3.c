#include <stdio.h>
#include <math.h>

int is_prime(int n)
{
    int i, root;

    if (n == 2) {
        return 1;
    }

    else if (n < 2) {
        return 0;
    }

    else {
        root = sqrt(n);

        for (i = 3; i <= root; i += 2) {
            if (n % i == 0) {
                return 0;
                break;
            }
        }

        return 1;
    }
}

int main()
{
    int i, root;

    long long int n = 600851475143;

    root = sqrt(n);

    for (i = root; i > 1; i--) {
        if (n % i == 0 && is_prime(i)) {
            printf("%d\n", i);
            break;
        }
    }    

    return 0;
}