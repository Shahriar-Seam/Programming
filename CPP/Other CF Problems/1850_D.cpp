#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, k, i, temp, cnt = 1, problems = 1;
    vector <int> v;

    cin >> n >> k;

    for (i = 0; i < n; i++) {
        cin >> temp;

        v.push_back(temp);
    }

    sort(v.begin(), v.end());

    for (i = 0; i < n - 1; i++) {
        if (v[i + 1] - v[i] > k) {
            cnt = 1;
        }
        else {
            cnt++;
        }

        problems = max (problems, cnt);
    }

    cout << n - problems << "\n";
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