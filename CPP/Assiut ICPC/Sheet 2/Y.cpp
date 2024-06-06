#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n, *fib;
    
    cin >> n;

    fib = (long long *) calloc(n, sizeof(long long));

    fib[0] = 0;
    fib[1] = 1;

    if (n == 0) {
        return 0;
    }
    else if (n == 1) {
        cout << 0;
    }
    else {
        cout << 0 << " " << 1 << " ";
    }

    for (int i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];

        cout << fib[i] << " ";
    }

    return 0;
}