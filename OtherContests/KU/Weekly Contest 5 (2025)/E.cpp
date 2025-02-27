#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i;

    cin >> n;

    vector <pair <int, int> > v(n);

    for (i = 0; i < n; i++) {
        cin >> v[i].first;

        v[i].second = i;
    }

    sort(v.begin(), v.end());

    cout << v[n - 2].second + 1 << "\n";

    return 0;
}