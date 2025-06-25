#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i;

    vector <int> v;

    for (i = 1; i <= 100000; i++) {
        string s = to_string(i);
        string t = s;

        reverse(t.begin(), t.end());

        v.push_back(stoll(s + t));
    }

    int k, p, sum = 0;

    cin >> k >> p;

    for (i = 0; i < k; i++) {
        sum = (sum + v[i]) % p;
    }

    cout << sum << "\n";

    return 0;
}