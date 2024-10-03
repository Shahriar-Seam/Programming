#include <bits/stdc++.h>

using namespace std;

#define mod int(1e9 + 7)

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, i, j;

    cin >> n;

    vector <long long> v(n + 10, 0);

    v[0] = 1;

    for (i = 0; i < n; i++) {
        for (j = 1; j <= 6; j++) {
            v[i + j] = (v[i + j] + v[i]) % mod;
        }
    }

    cout << v[n] << "\n";

    return 0;
}