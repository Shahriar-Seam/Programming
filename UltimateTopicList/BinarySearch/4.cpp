#include <bits/stdc++.h>

using namespace std;

int left(vector <int> &v, int key)
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

int right(vector <int> &v, int key)
{
    int l = 0, r = v.size() - 1, m, index = -1;

    while (l <= r) {
        m = l + (r - l) / 2;

        if (v[m] <= key) {
            index = m;

            l = m + 1;
        }
        else {
            r = m - 1;
        }
    }

    return index;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, l, r;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    sort(v.begin(), v.end());

    cin >> k;

    while (k--) {
        cin >> l >> r;

        cout << max(0, right(v, r) - left(v, l) + 2) << " ";
    }

    return 0;
}