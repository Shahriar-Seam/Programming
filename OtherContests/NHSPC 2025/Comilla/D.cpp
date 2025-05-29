#include <bits/stdc++.h>

using namespace std;

const int sz = 2e5 + 5;
vector <vector <int> > divisors(sz, vector <int> ());
vector <bool> marked(sz, false);
vector <int> pref(sz + 1, 0);

void get_divisors()
{
    int i, j;

    for (i = 1; i < sz; i++) {
        for (j = i + i; j < sz; j += i) {
            divisors[j].push_back(i);
        }
    }
}

void pre_calc()
{
    int i;

    marked[0] = false;

    for (i = 2; i < sz; i++) {
        for (auto it : divisors[i]) {
            if (!marked[i - it]) {
                marked[i] = true;

                break;
            }
        }
    }

    for (i = 1; i < sz; i++) {
        pref[i] = pref[i - 1] + marked[i];
    }
}

void solve()
{
    int l, r;
    int num, denom, g;

    cin >> l >> r;

    num = pref[r] - pref[l - 1];
    denom = r - l + 1;

    g = gcd(num, denom);

    num /= g;
    denom /= g;

    if (denom == 1 || num == 0) {
        cout << num << "\n";
    }
    else {
        cout << num << "/" << denom << "\n";
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    get_divisors();
    pre_calc();

    int32_t t, i;

    cin >> t;

    for (i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";

        solve();
    }

    return 0;
}