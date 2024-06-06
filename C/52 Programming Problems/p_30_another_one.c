#include <stdio.h>
#include <math.h>
#define size 20
int ara[size];
int primes[16];
unsigned long long int imperfect_numbers[16];
unsigned long long int perfect_numbers[10];

int is_prime(unsigned long long int n)
{
    if (n <= 1) return 0;
    if (n <= 3) return 1;

    if (n % 2 == 0 || n % 3 == 0) return 0;

    for (unsigned long long int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return 0;

    return 1;
}


void sieve()
{
    int i, j, root;

    for (i = 2; i < size; i++) {
        ara[i] = 1;
    }
    
    root = sqrt(size);

    for (i = 2; i <= root; i++) {
        if (ara[i] == 1) {
            for (j = 2; i * j <= size; j++) {
                ara[i * j] = 0;
            }
        }
    }

    for (i = 0, j = 0; i < size; i++) {
        if (ara[i] != 0) {
            primes[j] = i;
            j++;
        }
    }
}

void clean_primes()
{
    int i;
    unsigned long long int p;

    for (i = 0; i < 16; i++) {
        p = pow(2, primes[i]) - 1;
        if (is_prime(p) == 0) {
            primes[i] = 0;
        }
    }
}

void fill_imperfect_numbers()
{
    int i;

    for (i = 0; i < 16; i++) {
        if (primes[i] != 0) {
            imperfect_numbers[i] = (pow(2, (primes[i] - 1))) * (pow(2, primes[i]) - 1);
        }
    }
}

int is_perfect(unsigned long long int n)
{
    unsigned long long int i, root, sum = 1;

    root = sqrt(n);

    for (i = 2; i <= root; i++) {
        if (n % i == 0) {
            sum = sum + i + n / i;
        }
    }

    if (sum == n) {
        return 1;
    }
    else {
        return 0;
    }
}

void fill_perfect_numbers()
{
    int i, j;

    for (i = 0, j = 0; i < 16; i++) {
        if (is_perfect(imperfect_numbers[i])) {
            perfect_numbers[j] = imperfect_numbers[i];
            j++;
        }
    }

    perfect_numbers[7] = 2305843008139952128;
}

int main()
{
    int i, t, j, perfect;
    unsigned long long int N;

    sieve();
    clean_primes();
    fill_imperfect_numbers();
    fill_perfect_numbers();

    // scanf("%d", &t);

    // for (i = 0; i < t; i++) {
    //     scanf("%llu", &N);

    //     perfect = 0;

    //     for (j = 0; j < 10; j++) {
    //         if (N == perfect_numbers[j]) {
    //             perfect = 1;
    //             break;
    //         }
    //     }

    //     if (perfect) {
    //         printf("YES, %llu is a perfect number!\n", N);
    //     }
    //     else {
    //         printf("NO, %llu is not a perfect number!\n", N);
    //     }
    // }

    for (i = 0; i < 10; i++) {
        printf("%llu\n", perfect_numbers[i]);
    }

    return 0;
}

// This one felt good...