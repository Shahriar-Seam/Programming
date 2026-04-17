#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt")

#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, f, i;

	cin >> n;

	f = n > 1;

	if (n > 2) {
		for (i = 2; i < n; i++) {
			if (n % i == 0) {
				f = 0;
				break;
			}
		}
	}

	cout << (f ? "YES" : "NO") << "\n";

	return 0;
}