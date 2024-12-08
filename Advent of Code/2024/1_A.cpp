#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i, n = 1000, dist = 0;

    vector <int> a(n), b(n);

    for (i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    for (i = 0; i < n; i++) {
        dist += abs(a[i] - b[i]);
    }

    cout << dist << "\n";

    return 0;
}