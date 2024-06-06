#include <bits/stdc++.h>

using namespace std;

#define max_size 200005

vector <long long> v(max_size, 0);

void fill_array()
{
    int i;

    for (i = 1; i < max_size; i++) {
        v[i] = v[i - 1] + i;
    }
}

void solve()
{
    int n, k, x;

    cin >> n >> k >> x;

    if (x > v[k - 1]) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    fill_array();

    int t;

    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}