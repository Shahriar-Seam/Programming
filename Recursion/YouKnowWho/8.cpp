#include <bits/stdc++.h>

using namespace std;

void collatz(long long n)
{
    if (n == 1) {
        cout << 1;

        return;
    }
    else {
        cout << n << " ";

        n = ((n % 2 == 0) ? n / 2 : 3 * n + 1);

        collatz(n);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    collatz(n);

    return 0;
}