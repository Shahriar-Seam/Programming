#include <bits/stdc++.h>

using namespace std;

bool is_palindrome(string &s)
{
    int i, j;

    for (i = 0, j = s.size() - 1; i < j; i++, j--) {
        if (s[i] != s[j]) {
            return false;
        }
    }

    return true;
}

bool non_dec(string &s)
{
    return s.find("10") == string::npos;
}

bool valid(string &s, vector <int> &p)
{
    int i;
    string t, q;

    for (i = 0; i < s.size(); i++) {
        if (!binary_search(p.begin(), p.end(), i)) {
            t += s[i];
        }
        else {
            q += s[i];
        }
    }

    return is_palindrome(t) && non_dec(q);
}

void recurse(string &s, int i, vector <int> &p, int n, vector <int> &q)
{
    if (i == n) {
        if (p.size() > q.size() && valid(s, p)) {
            q = p;
        }

        return;
    }

    recurse(s, i + 1, p, n, q);
    p.push_back(i);
    recurse(s, i + 1, p, n, q);
    p.pop_back();
}

void solve()
{
    int n;
    string s;
    vector <int> p, q;

    cin >> n >> s;

    recurse(s, 0, p, n, q);

    cout << q.size() << "\n";

    for (auto &it : q) {
        cout << it + 1 << " ";
    }

    cout << "\n";
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