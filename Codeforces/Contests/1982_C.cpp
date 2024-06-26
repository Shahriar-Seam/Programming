#include <bits/stdc++.h>

using namespace std;

void solve()
{
    long long n, l, r, temp, cnt = 0;
    int i, j;
    long long sum;

    cin >> n >> l >> r;

    vector <long long> v, prefix(1, 0);

    for (i = 0; i < n; i++) {
        cin >> temp;

        v.push_back(temp);
        prefix.push_back(prefix[i] + temp);
    }
    
    for (i = 0; i < n; i++) {
        sum = 0;
        j = i;

        auto bleh = lower_bound(begin(prefix) + i, end(prefix), prefix[i] + l);

        if (bleh == end(prefix)) {
            break;
        }

        sum = *bleh - prefix[i];

        if (sum >= l && sum <= r) {
            cnt++;
            i = distance(begin(prefix), bleh) - 1;
        }
    }

    cout << cnt << "\n";
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