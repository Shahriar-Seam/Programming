#include <bits/stdc++.h>

using namespace std;

int binary_search(vector <int> &v, int start, int k)
{
    int l = start, r = v.size() - 1, mid, index = 0;

    while (l <= r) {
        mid = (l + r) / 2;

        if (v[mid] < k) {
            index = mid;

            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }

    return index;
}

void solve()
{
    int n, i, ops = int(1e9);

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    sort(v.begin(), v.end());

    for (i = 0; i < n - 1; i++) {
        ops = min(ops, i + n - binary_search(v, i, v[i] + v[i + 1]) - 1);
    }

    cout << ops << "\n";
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