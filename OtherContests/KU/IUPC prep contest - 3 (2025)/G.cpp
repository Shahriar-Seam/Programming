#include <bits/stdc++.h>

using namespace std;

vector <int> fact(20);

void factorial()
{
    int i;

    fact[0] = fact[1] = 1;

    for (i = 2; i < 20; i++) {
        fact[i] = fact[i - 1] * i;
    }
}

void solve()
{
    string s;
    int d, num_recipes = 0;

    cin >> s >> d;

    num_recipes = fact[s.size()] / fact[s.size() - d];

    if (s.find('0') != string::npos) {
        num_recipes -= fact[s.size() - 1] / fact[s.size() - d];
    }

    cout << num_recipes << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    factorial();

    int32_t t, i;

    cin >> t;

    for (i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";

        solve();
    }

    return 0;
}