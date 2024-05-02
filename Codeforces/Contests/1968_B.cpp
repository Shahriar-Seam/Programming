#include <bits/stdc++.h>

using namespace std;

bool is_subsequence(string& s1, string& s2)
{
    int n = s1.length(), m = s2.length();
    int i = 0, j = 0;

    while (i < n && j < m) {
        if (s1[i] == s2[j]) {
            i++;
        }

        j++;
    }
    
    return i == n;
}

void solve()
{
    int n, m, l, r, mid, k = 0;
    string s1, s2;

    cin >> n >> m;
    cin >> s1 >> s2;

    l = 0;
    r = min(s1.size(), s2.size());

    while (l <= r) {
        mid = (l + r) / 2;
        string s = s1.substr(0, mid);

        if (is_subsequence(s, s2) == true) {
            l = mid + 1;
            k = mid;
        }
        else {
            r = mid - 1;
        }
    }

    cout << k << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}