#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, q, i, a, b;

    cin >> n >> q;

    vector <long long> v(n), prefix(n + 1, 0);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] ^ v[i];
    }

    while (q--) {
        cin >> a >> b;

        cout << (prefix[b] ^ prefix[a - 1]) << "\n";
    }

    return 0;
}