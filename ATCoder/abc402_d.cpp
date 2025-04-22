#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, i, a, b, right_sum = 0;
    int pairs = 0;

    cin >> n >> m;

    vector <int> counter(n, 0);

    for (i = 0; i < m; i++) {
        cin >> a >> b;

        counter[(a + b) % n]++;
    }

    right_sum = accumulate(counter.begin(), counter.end(), 0LL);

    for (auto it : counter) {
        right_sum -= it;

        pairs += right_sum * it;
    }

    cout << pairs << "\n";

    return 0;
}