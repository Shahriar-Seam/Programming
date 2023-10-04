#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

#define yes printf("YES\n")
#define no printf("NO\n")

bool sieve[1000001];
int primes[78500] = {0};

void _sieve()
{
    int prime_count = 0;
    
    memset(sieve, true, sizeof(sieve));
    
    sieve[0] = sieve[1] = false;
    
    for (int p = 2; p * p <= 1000001; p++) {
        if (sieve[p]) {
            for (int i = p * p; i <= 1000001; i += p) {
                sieve[i] = false;
            }
        }
    }
    
    for (int p = 2; p <= 1000001; p++) {
        if (sieve[p]) {
            primes[prime_count++] = p;
        }
    }
}

int T_Prime(unsigned long long int n)
{
    unsigned long long int root = sqrt(n);
    int low_index = 0;
    int high_index = 78499;
    int mid_index;

    while (low_index <= high_index) {
        mid_index = (low_index + high_index) / 2;

        if (root == primes[mid_index]) {
            break;
        }
        if (root < primes[mid_index]) {
            high_index = mid_index - 1;
        }
        else {
            low_index = mid_index + 1;
        }
    }

    if (low_index > high_index) {
        return 0;
    }
    else {
        return 1;
    }

    
}

int is_square(unsigned long long int n)
{
    unsigned long long int r = sqrt(n);
    
    if (r * r == n) {
        return 1;
    }
    else {
        return 0;
    }
}

int main() {
    int t;
    unsigned long long n;
    
    _sieve();
    
    scanf("%d", &t);
    
    while (t--) {
        scanf ("%llu", &n);
        
        if (n < 4) {
            no;
        }
        
        else if (n == 1000000000000) {
            no;
        }
        
        else if (is_square(n) == 0) {
            no;
        }
        
        else {
            if (T_Prime(n)) {
                yes;
            }
            else {
                no;
            }
        }
    }

    return 0;
}