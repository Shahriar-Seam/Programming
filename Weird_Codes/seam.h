// Created by Ibnul Abrar Shahriar Seam

// Header files
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define
#define yes printf("YES\n")
#define no printf("NO\n")

#define PI 3.141592653589793

#define area_of_circle(r) PI * r * r

// Global Variables
bool *sieve;
int *primes;

// Function for calculating area of triangle from the length of the sides
double area_of_triangle(double a, double b, double c)
{
    double s = (a + b + c) / 2.0;

    double area = sqrt(s * (s - a) * (s - b) * (s - c));

    return area;
}

// Function to calculate length of a integer
int intlen(int n)
{
    int len = 0;

    while (n != 0) {
        len++;
        n /= 10;
    }

    return len;
}

// Function to calculate sum of all the digits of an integer number
int dig_sum_int(int n)
{
    int i, r, sum = 0, len = intlen(n);

    for (i = 0; i < len; i++) {
        r = n % 10;
        sum += r;
        n /= 10;
    }

    return sum;
}

// Function to calculate sum of all the digits of an integer number using string
int dig_sum_str(char *str)
{
    int len = strlen(str);
    int i, sum = 0;

    for (i = 0; i < len; i++) {
        sum += str[i] - '0';
    }

    return sum;
}

// Sieve of Eratosthenes ChatGPT
void sieveOfEratosthenes(int limit, bool *sieve, int *primes) {
    int prime_count = 0;

    for (int i = 0; i <= limit; i++) {
        sieve[i] = true;
    }
    sieve[0] = sieve[1] = false;

    for (int p = 2; p * p <= limit; p++) {
        if (sieve[p]) {
            for (int i = p * p; i <= limit; i += p) {
                sieve[i] = false;
            }
        }
    }

    for (int p = 2; p <= limit; p++) {
        if (sieve[p]) {
            primes[prime_count++] = p;
        }
    }
}

// Check if an integer is prime
int is_prime(int n)
{
    int i, found = 0, limit = 10000002;

    sieve = (bool *) malloc(sizeof(bool) * (limit + 1));
    primes = (int *) malloc(sizeof(int) * limit);

    sieveOfEratosthenes(limit, sieve, primes);

    for (i = 0; i <= n; i++) {
        if (primes[i] == n) {
            found = 1;
            break;
        }
    }

    return found;
}