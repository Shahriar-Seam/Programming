#include <bits/stdc++.h>

using namespace std;

string bin_search(vector <int> &v, int key)
{
    int l = 0, r = v.size() - 1, m;

    while (l <= r) {
        m = l + (r - l) / 2;

        if (v[m] == key) {
            return "YES";
        }
        else if (v[m] < key) {
            l = m + 1;
        }
        else {
            r = m - 1;
        }
    }

    return v[m] == key ? "YES" : "NO";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, key;

    cin >> n >> k;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    while (k--) {
        cin >> key;

        cout << bin_search(v, key) << "\n";
    }

    return 0;
}