#include <bits/stdc++.h>

using namespace std;

int bin_search(vector <int> &v, int key)
{
    int l = 0, r = v.size() - 1, m, index = -1;

    while (l <= r) {
        m = l + (r - l) / 2;

        if (v[m] < key) {
            index = m;

            l = m + 1;
        }
        else {
            r = m - 1;
        }
    }

    return v[index] == key ? index + 1 : index + 2;
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