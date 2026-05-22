#include <bits/stdc++.h>

using namespace std;

map <string, int> mp = {
    {"RBBB", 1},
    {"RBBR", 2},
    {"RBRB", 0},
    {"RBRR", 1},
    {"RRBB", 0},
    {"RRBR", 1},
    {"RRRB", 1},
    {"RRRR", 0},
    {"BBBB", 0},
    {"BBBR", 1},
    {"BBRB", 1},
    {"BBRR", 0},
    {"BRBB", 1},
    {"BRBR", 0},
    {"BRRB", 2},
    {"BRRR", 1}
};

map <string, string> mp2 = {
    {"RBBB", "BBBB"},
    {"RBBR", "BBBB"},
    {"RBRB", "RBRB"},
    {"RBRR", "RBRB"},
    {"RRBB", "RRBB"},
    {"RRBR", "RRBB"},
    {"RRRB", "RRRR"},
    {"RRRR", "RRRR"},
    {"BBBB", "BBBB"},
    {"BBBR", "BBBB"},
    {"BBRB", "BBBB"},
    {"BBRR", "BBRR"},
    {"BRBB", "BBBB"},
    {"BRBR", "BRBR"},
    {"BRRB", "BBBB"},
    {"BRRR", "RRRR"}
};

void solve()
{
    int n, i, count = 0;
    string s, t, temp;

    cin >> n >> s >> t;

    if (n & 1) {
        count += s[n - 1] != t[n - 1];
    }

    for (i = 0; i < n - 1; i += 2) {
        count += mp[string({s[i], s[i + 1], t[i], t[i + 1]})];

        temp = mp2[string({s[i], s[i + 1], t[i], t[i + 1]})];

        s[i] = temp[0];
        s[i + 1] = temp[1];
        t[i] = temp[2];
        t[i + 1] = temp[3];
    }

    cout << count << "\n";
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