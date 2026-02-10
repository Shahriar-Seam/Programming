#include <bits/stdc++.h>

using namespace std;

#define int long long

vector <int> pi(const string &s) {
	vector <int> p(s.size());
	int i;

	for (i = 1; i < s.size(); i++) {
		int g = p[i - 1];

		while (g && s[i] != s[g]) {
			g = p[g - 1];
		}

		p[i] = g + (s[i] == s[g]);
	}

	return p;
}

void solve()
{
	int n, i, t, j;
	string s, b;

	cin >> n;

	for (i = 0; i < n; i++) {
		cin >> t;

		s += to_string(t);
		b += to_string(1 - t);
	}

	string ps = s + s;
	string ss = b + "#" + ps;

	ss.pop_back();

	vector <int> p = pi(ss);

     vector <pair <int, int> > _mx;

	int max_v = 0, max_ind = 0;

	for (i = n + 1; i < p.size(); i++) {
		if (p[i] > max_v) {
			max_v = p[i];
			max_ind = i;
		}
	}

	for (i = n + 1; i < p.size(); i++) {
		if (p[i] == max_v) {
			_mx.push_back({i, p[i]});
		}
	}
	
	string c = "";
     
     for (auto &it : _mx) {
          max_ind = it.first;
          max_v = it.second;

          string t_s = "", t_c_s = "";

          for (i = max(n + 1, max_ind - max_v + 1); i < min((int) ss.size(), max(n + 1, max_ind - max_v + 1) + n); i++) {
               t_s += ss[i];
          }

          if (t_s.size() == n) {
               for (i = 0; i < n; i++) {
                    t_c_s += (t_s[i] == s[i] ? "0" : "1");
               }

               c = max(c, t_c_s);
          }
     }

     if (c == "") {
          c = string(n, '0');
     }

	for (i = 0; i < n; i++) {
		cout << c[i] << " ";
	}

	cout << "\n";
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int i, t = 1;

	cin >> t;

	for (i = 1; i <= t; i++) {
		// cout << "Case " << i << ": ";

		solve();
	}

	return 0;
}