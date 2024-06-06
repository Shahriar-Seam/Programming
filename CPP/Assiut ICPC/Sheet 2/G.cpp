#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long t, n, f;

    cin >> t;

    while (t--) {
        cin >> n;

        f = tgamma(n + 1);

        cout << f << "\n";
    }

    return 0;
}