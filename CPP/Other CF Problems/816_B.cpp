#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, q, i, a, b;

    cin >> n >> k >> q;

    vector <pair <int, int> > v(n);
    vector <int> diff(200005, 0);
    vector <int> prefix(200005, 0);

    for (i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;

        diff[v[i].first] += 1;
        diff[v[i].second + 1] -= 1;
    }

    for (i = 1; i <= 200003; i++) {
        diff[i] += diff[i - 1];
    }

    for (i = 1; i <= 200003; i++) {
        prefix[i] += prefix[i - 1] + (diff[i] >= k);
    }

    for (i = 0; i < q; i++) {
        cin >> a >> b;

        cout << prefix[b] - prefix[a - 1] << "\n";
    }

    return 0;
}