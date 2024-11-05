#include <bits/stdc++.h>

using namespace std;

#define mod int(1e9 + 7)

map <long long, long long> fib;

long long fibonacci(long long n)
{
    long long k;
    long long a, b;

    if (n == 0 || n == 1) {
        return n;
    }

    if (n % 2 == 0) {
        k = n / 2;

        if (fib.find(k - 1) != fib.end()) {
            a = fib[k - 1];
        }
        else {
            a = fibonacci(k - 1);
        }

        if (fib.find(k) != fib.end()) {
            b = fib[k];
        }
        else {
            b = fibonacci(k);
        }

        fib[n] = ((2 * a + b) * b) % mod;
    }
    else {
        k = (n + 1) / 2;

        if (fib.find(k - 1) != fib.end()) {
            a = fib[k - 1];
        }
        else {
            a = fibonacci(k - 1);
        }

        if (fib.find(k) != fib.end()) {
            b = fib[k];
        }
        else {
            b = fibonacci(k);
        }

        fib[n] = (a * a + b * b) % mod;
    }

    return fib[n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;

    cin >> n;

    cout << fibonacci(n) << "\n";

    return 0;
}