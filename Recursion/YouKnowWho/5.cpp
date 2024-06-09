#include <bits/stdc++.h>

using namespace std;

long long fibonacci(long long n)
{
    if (n == 2 || n == 1) {
        return n - 1;
    }
    else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    cout << fibonacci(n);

    return 0;
}