#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, m;
    int i, j, sum = 0, temp, prev = 0, total = 0;
    unordered_map <int, vector <int> > row, col;

    cin >> n >> m;

    vector <vector <int> > v(n, vector <int> (m));

    for (i = 0; i < n; i++) {
    	for (j = 0; j < m; j++) {
    		cin >> v[i][j];
    	}
    }

    for (i = 0; i < n; i++) {
    	for (j = 0; j < m; j++) {
    		row[v[i][j]].push_back(i + 1);
    		col[v[i][j]].push_back(j + 1);
    	}
    }

    for (auto &it : row) {
    	sum = prev = 0;

    	sort(it.second.begin(), it.second.end());

	    for (i = 1; i < (int) it.second.size(); i++) {
	    	temp = sum;

	    	sum += prev + i * (it.second[i] - it.second[i - 1]);

	    	prev = sum - temp;
	    }

	    total += sum * 2;
    }

    for (auto it : col) {
    	sum = prev = 0;

    	sort(it.second.begin(), it.second.end());

	    for (i = 1; i < (int) it.second.size(); i++) {
	    	temp = sum;

	    	sum += prev + i * (it.second[i] - it.second[i - 1]);

	    	prev = sum - temp;
	    }

	    total += sum * 2;
    }

    cout << total << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}