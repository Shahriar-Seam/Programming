#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, k, i, temp;

    cin >> n >> k;

    vector <int> v(n, 0), arr(k);

    for (auto &it : arr) {
        cin >> it;

        v[*it - 1] = *it;
    }

    if (arr[0] == 1) {
        v[0] = 1;
    }
    else {
        v[0] = 2;
        v[1] = 1;
    }

    for (i = 1; i < k; i++) {
        if (arr[i] - arr[i - 1] == 1) {
            v[i] = arr[i];
        }
        else {
            temp = arr[i - 1];

            while (temp != arr[i]) {
                v[]
            }
        }
    }
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