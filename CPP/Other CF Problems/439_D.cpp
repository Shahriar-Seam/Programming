#include <bits/stdc++.h>

using namespace std;

#define int long long

int f(vector <int> &a, vector <int> &b, int m)
{
    int ops = 0, i;

    for (i = 0; i < a.size(); i++) {
        ops += max(0LL, m - a[i]);
    }

    for (i = 0; i < b.size(); i++) {
        ops += max(0LL, b[i] - m);
    }

    return ops;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    int l = 1e9, r = 1, mid, min_ops = 1e18;

    cin >> n >> m;

    vector <int> a(n), b(m);

    for (auto &it : a) {
        cin >> it;

        l = min(l, it);
        r = max(r, it);
    }
    
    for (auto &it : b) {
        cin >> it;
        
        l = min(l, it);
        r = max(r, it);
    }

    while (r - l > 3) {
        mid = (l + r) / 2;

        auto temp1 = f(a, b, mid);
        auto temp2 = f(a, b, mid + 1);
        
        if (temp1 < temp2) {
            r = mid;
        }
        else {
            l = mid;
        }
    }

    while (l <= r) {
        min_ops = min(min_ops, f(a, b, l++));
    }

    cout << min_ops << "\n";
    
    return 0;
}