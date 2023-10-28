#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n, fib[50] = {0}, i;

    cin >> n;

    fib[0] = 0;
    fib[1] = 1;

    for (i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    cout << fib[n - 1];

    return 0;
}