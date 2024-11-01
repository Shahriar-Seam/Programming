#include <bits/stdc++.h>

using namespace std;

void solve()
{
    long long n, a = -1, b = -1, max_val, min_val;

    cin >> n;

    vector <long long> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    max_val = *max_element(v.begin(), v.end());
    min_val = *min_element(v.begin(), v.end());

    sort(v.begin(), v.end());

    long long l = 0, r = n - 2, mid;
    a = n - 2;

    while (l < r) {
        mid = (l + r) / 2;

        if (v[mid] + v[mid + 1] > max_val) {
            a = mid;
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }

    l = 0, r = n - 1, mid;

    while (l < r) {
        mid = (l + r) / 2;

        if (mid > 1 && v[0] + v[1] > v[mid]) {
            b = n - mid - 1;
            l = mid;
        }
        else {
            r = mid - 1;
        }
    }

    cout << (b > -1 ? min(a, b) : a) << "\n";
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