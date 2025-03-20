#include <bits/stdc++.h>

using namespace std;

#define int long long

bool contains_abc(string s, string t)
{
    string ss = s + t;

    return ss.find('A') != string::npos && ss.find('B') != string::npos && ss.find('C') != string::npos;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, a = 1e9, b = 1e9, c = 1e9, abc = 1e9, price = 1e9, i, j;

    cin >> n;

    vector <pair <int, string> > v(n);

    for (auto &it : v) {
        cin >> it.first >> it.second;
    }

    for (i = 0; i < n; i++) {
        sort(v[i].second.begin(), v[i].second.end());

        if (v[i].second == "A") {
            a = min(a, v[i].first);
        }
        else if (v[i].second == "B") {
            b = min(b, v[i].first);
        }
        else if (v[i].second == "C") {
            c = min(c, v[i].first);
        }
        else if (v[i].second == "ABC") {
            abc = min(abc, v[i].first);
        }
    }

    price = min(a + b + c, abc);

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (contains_abc(v[i].second, v[j].second) && v[i].first + v[j].first <= price) {
                price = min(price, v[i].first + v[j].first);
            }
        }
    }

    cout << (price == 1e9 ? -1 : price) << "\n";

    return 0;
}