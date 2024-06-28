#include <bits/stdc++.h>

using namespace std;

void solve()
{
    long long n, k, i, sum = 0;

    cin >> n >> k;

    vector <long long> prefix(k), v;

    for (auto &it : prefix) {
        cin >> it;
    }

    for (i = k - 1; i > 0; i--) {
        v.push_back(prefix[i] - prefix[i - 1]);
    }

    if (k == 1) {
        cout << "YES\n";

        return;
    }

    for (i = k; i < n; i++) {
        sum += v.back();

        v.push_back(v.back());
    }

    v.push_back(prefix[0] - sum);
    
    cout << (is_sorted(begin(v), end(v), greater <long long>()) ? "YES\n" : "NO\n");
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