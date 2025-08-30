#include <bits/stdc++.h>

using namespace std;

int num_len(int n)
{
    int len = 0;

    while (n) {
        len++;

        n /= 10;
    }

    return len;
}

bool unique(string a, string b)
{
    set <char> s;

    if (a.size() == 4) {
        a = '0' + a;
    }

    if (b.size() == 4) {
        b = '0' + b;
    }

    for (auto &it : a) {
        s.insert(it);
    }

    for (auto &it : b) {
        s.insert(it);
    }

    return s.size() == 10;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 0;

    while (true) {
        int n, i, j;
        vector <pair <int, int> > v;

        cin >> n;

        if (n == 0) {
            break;
        }

        if (t > 0) {
            cout << "\n";
        }

        t++;

        for (i = 1000; i < 100000; i++) {
            j = n * i;

            if (num_len(j) > 5) {
                break;
            }

            if (unique(to_string(i), to_string(j))) {
                v.push_back({j, i});
            }
        }

        sort(v.begin(), v.end());

        if (v.size() == 0) {
            cout << "There are no solutions for " << n << ".\n";
        }
        else {
            for (auto &it : v) {
                cout << it.first << " / " << (num_len(it.second) == 5 ? "" : "0") << it.second << " = " << it.first / it.second << "\n";
            }
        }
    }

    return 0;
}