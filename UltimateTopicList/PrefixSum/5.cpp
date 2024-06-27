#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("bcount.in", "r", stdin);
    // freopen("bcount.out", "w", stdout);

    int n, q, i, a, b;

    cin >> n >> q;

    vector <int> v(n);
    vector <vector <int > > prefix(n + 1, vector <int> (3));

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < n; i++) {
        prefix[i + 1][0] = prefix[i][0] + (v[i] == 1);
        prefix[i + 1][1] = prefix[i][1] + (v[i] == 2);
        prefix[i + 1][2] = prefix[i][2] + (v[i] == 3);
    }

    while (q--) {
        cin >> a >> b;

        cout << prefix[b][0] - prefix[a - 1][0] << " ";
        cout << prefix[b][1] - prefix[a - 1][1] << " ";
        cout << prefix[b][2] - prefix[a - 1][2] << "\n";
    }

    return 0;
}