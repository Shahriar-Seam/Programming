#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, i, sum = 0;
    deque <int> odd, even;

    cin >> n;

    n *= 2;

    vector <int> v(n);

    for (auto &it : v) {
    	cin >> it;
    }

    for (i = 0; i < n; i++) {
    	if (i & 1) {
    		odd.push_back(v[i]);
    	}
    	else {
    		even.push_back(v[i]);
    	}
    }

    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end());

    while (!odd.empty() && !even.empty()) {
    	if (odd.back() - even.front() > even.back() - odd.front()) {
    		sum += odd.back() - even.front();

    		odd.pop_back();
    		even.pop_front();
    	}
    	else {
    		sum += even.back() - odd.front();

    		even.pop_back();
    		odd.pop_front();
    	}
    }

    cout << sum << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int32_t t, i;

    cin >> t;

    for (i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";

        solve();
    }

    return 0;
}