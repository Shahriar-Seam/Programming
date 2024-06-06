#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, k, i, temp;
    vector <pair <int, int> > v;
    vector <int> dead;

    cin >> n >> k;

    for (i = 0; i < n; i++) {
        cin >> temp;

        v.push_back(make_pair(temp, i));
    }

    sort(v.begin(), v.end());

    
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