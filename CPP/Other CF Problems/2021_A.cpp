#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i;
    long long a, b;

    cin >> n;

    vector <long long> v(n);

    for (i = 0; i < n; i++) {
        cin >> v[i];
    }

    while (v.size() > 1) {
        sort(v.begin(), v.end(), greater <int> ());

        a = v.back();
        v.pop_back();

        b = v.back();
        v.pop_back();

        v.push_back((a + b) / 2);
    }

    cout << v[0] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}