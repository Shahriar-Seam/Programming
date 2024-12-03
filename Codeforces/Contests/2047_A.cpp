#include <bits/stdc++.h>

using namespace std;

#define sz 1275

vector <int> blocks;
vector <int> pref(sz + 1, 0);

void fill()
{
    int n, k, i;

    blocks.push_back(1);

    for (n = 2; n <= 1275; n++) {
        k = 2 * (n - 1) - 1;
        blocks.push_back((k + 2) * 2 + k * 2);
    }

    for (i = 0; i < sz; i++) {
        pref[i + 1] = pref[i] + blocks[i];
    }
}

void solve()
{
    int n, i, count = 0, sum = 0;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    for (auto it : v) {
        sum += it;

        if (binary_search(pref.begin(), pref.end(), sum)) {
            count++;
        }
    }

    cout << count << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    fill();

    int t;

    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}