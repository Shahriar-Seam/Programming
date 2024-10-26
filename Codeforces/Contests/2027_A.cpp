#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;

    cin >> n;

    vector <int> h(n), w(n);

    for (int i = 0; i < n; i++) {
        cin >> h[i] >> w[i];
    }

    cout << (*max_element(h.begin(), h.end()) + *max_element(w.begin(), w.end())) * 2 << "\n";
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