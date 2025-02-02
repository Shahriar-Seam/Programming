#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i;
    set <int> s1, s2;

    cin >> n;

    vector <int> a(n), b(n), c(n);

    for (auto &it : a) {
        cin >> it;
    }

    for (auto &it : b) {
        cin >> it;
    }

    for (auto it : a) {
        s1.insert(it);
    }

    for (auto it : b) {
        s2.insert(it);
    }

    cout << (((s1.size() >= 2 && s2.size() >= 2) || (s1.size() >= 3 || s2.size() >= 3)) ? "YES" : "NO") << "\n";
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