#include <bits/stdc++.h>

using namespace std;

#define int long long

int bit_count(int n)
{
    return n == 0 ? 0 : n * (1LL << (n - 1));
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i, count = 0;

    cin >> n;

    for (i = 60; i >= 0; i--) {
        if (n & (1LL << i)) {
            count += bit_count(i) + 1;

            n &= ~(1LL << i);

            count += n;
        }
    }

    cout << count << "\n";

    return 0;
}