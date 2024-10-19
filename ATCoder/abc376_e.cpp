#include <bits/stdc++.h>

using namespace std;

void solve()
{
    long long n, k, i, result = 0;
    multiset <long long> ms;

    cin >> n >> k;

    vector <long long> a(n), b(n), pref(n + 1, 0);

    for (auto &it : a) {
        cin >> it;
    }

    for (auto &it : b) {
        cin >> it;
    }

    for (i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + b[i];
    }

    for (i = 0; i < k; i++) {
        ms.insert(a[i]);
    }

    result = *ms.rbegin() * pref[k];

    cout << result << "\n";

    for (i = k; i < n; i++) {
        ms.insert(a[i]);
        ms.erase(ms.find(a[i - k]));

        cout << *ms.rbegin() * (pref[i + 1] - pref[i - k + 1]) << "\n";

        result = min(result, *ms.rbegin() * (pref[i + 1] - pref[i - k + 1]));
    }

    cout << result << "\n";
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