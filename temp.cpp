#include <bits/stdc++.h>

using namespace std;

void solve()
{
	int n, r, i, j;
	double c = 1;

	cin >> n >> r;

	for (i = n; i > r; i--) {
		c = c * i;
	}

	for (i = 1; i <= n - r; i++) {
		c = c / i;
	}

	cout << (long long) (c + 0.0001) << "\n";
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