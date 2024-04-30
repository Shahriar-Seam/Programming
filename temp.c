#include <bits/stdc++.h>

using namespace std;

int phi(int n)
{
    int ret = n, i;

    for (i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0) {
                n /= i;
            }

            ret -= ret / i;
        }
    }

    if (n > 1) {
        ret -= ret / n;
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    cout << phi(n);

    return 0;
}