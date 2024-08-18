#include <bits/stdc++.h>

using namespace std;

int binary_search(vector <int> &v, int key)
{
    int low = 0, high = v.size(), mid, pos = -1;

    while (low <= high) {
        mid = low + (high - low) / 2;

        if (v[mid] >= key) {
            high = mid - 1;
            if (v[mid] == key) {
                pos = mid;
            }
        }
        else {
            low = mid + 1;
        }
    }

    return pos;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q, key;

    cin >> n >> q;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    while (q--) {
        cin >> key;

        cout << binary_search(v, key) << "\n";
    }

    return 0;
}