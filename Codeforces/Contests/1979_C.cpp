#include <bits/stdc++.h>

using namespace std;

int LCM(int a, int b)
{
    return (a * b) / __gcd(a, b);
}

void solve()
{
    int n, i, temp, bound, mi = INT_MAX, ma = INT_MIN;
    int lcm, cnt = 1, f = 1, sum;
    vector <int> v, vv;

    cin >> n >> temp;

    v.push_back(temp);

    mi = min(mi, temp);
    ma = max(ma, temp);

    for (i = 1; i < n; i++) {
        cin >> temp;

        cnt += (temp == v[0]);

        v.push_back(temp);

        mi = min(mi, temp);
        ma = max(ma, temp);
    }

    if (cnt == n && cnt == v[0]) {
        cout << -1 << "\n";

        return;
    }

    bound = 18044195;
    sum = mi = INT_MAX;
    cnt = 0;

    // while (sum >= mi) {
        vv.clear();
        mi = INT_MAX;
        sum = 0;
        bound++;
        cnt++;

        // if (cnt == lcm) {
        //     f = 0;

        //     break;
        // }

        for (i = 0; i < n; i++) {
            temp = ceil((bound + 1) / (1.0 * v[i]));

            mi = min(mi, temp * v[i]);

            sum += temp;

            vv.push_back(temp);
        }
    // }

    if (sum < mi) {
        for (auto it : vv) {
            cout << it << " ";
        }
    }
    else {
        cout << -1;
    }

    cout << "\n";
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