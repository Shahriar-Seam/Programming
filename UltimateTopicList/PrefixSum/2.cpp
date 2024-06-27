#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q, i, a, b;

    cin >> n >> q;

    vector <long long> v(n), prefix(n + 1, 0);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + v[i - 1];
    }

    while (q--) {
        cin >> a >> b;

        cout << prefix[b] - prefix[a] << "\n";
    }

    return 0;
}