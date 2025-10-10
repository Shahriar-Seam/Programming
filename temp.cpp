#include <bits/stdc++.h>

using namespace std;

vector <int> create(int n)
{
	vector <int> v(n);

	for (auto &it : v) {
		cin >> it;
	}

	return v;
}

void solve()
{
	int n, m;

	cin >> n >> m;

	vector <int> v = create(n), u = create(m);
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