#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, i, j, k;

    cin >> n >> m;

    vector <int> a(n), b(m), c(n + m);

    for (auto &it : a) {
        cin >> it;
    }

    for (auto &it : b) {
        cin >> it;
    }

    for (i = 0, j = 0, k = 0; k < n + m; k++) {
        c[k] = (i < n && j < m) ? (a[i] < b[j] ? a[i++] : b[j++]) : (i < n ? a[i++] : b[j++]);
    }

    for (auto it : c) {
        cout << it << " ";
    }

    cout << "\n";

    return 0;
}