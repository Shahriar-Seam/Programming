#include <bits/stdc++.h>

using namespace std;

#define int long long

struct item {
    int p, a, b;
};

vector <int> create_chain(vector <item> &v, int n, int mood)
{
    int i;
    vector <int> t;

    t.push_back(mood);

    for (i = 0; i < n; i++) {
        if (mood <= v[i].p) {
            mood += v[i].a;
        }
        else {
            mood -= v[i].b;

            if (mood < 0) {
                mood = 0;
            }
        }

        t.push_back(mood);
    }

    return t;
}

void solve(int n, vector <item> &v, vector <vector <int> > &chains)
{
    int x, i, c;

    cin >> x;

    for (i = -1; i < n; i++) {
        if (i == -1) {
            for (c = 0; c < chains.size(); c++) {
                if (x == chains[c][0]) {
                    cout << chains[c].back() << "\n";

                    return;
                }
            }

            continue;
        }

        if (x <= v[i].p) {
            x += v[i].a;
        }
        else {
            x -= v[i].b;

            if (x < 0) {
                x = 0;
            }
        }

        for (c = 0; c < chains.size(); c++) {
            if (x == chains[c][i + 1]) {
                cout << chains[c].back() << "\n";

                return;
            }
        }
    }

    cout << x << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, mood, q;

    cin >> n;

    vector <item> v(n);
    vector <vector <int> > chains;

    for (auto &it : v) {
        cin >> it.p >> it.a >> it.b;
    }

    for (mood = 0; mood <= 505; mood++) {
        chains.push_back(create_chain(v, n, mood));
    }

    cin >> q;

    while (q--) {
        solve(n, v, chains);
    }

    return 0;
}