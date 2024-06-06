#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, f = 1;
    int sum = 0, average = 0, balance = 0;

    cin >> n;

    vector <int> v(n);

    for (auto &i : v) {
        cin >> i;

        sum += i;
    }

    average = sum / n;

    for (int i = 0; i < n; i++) {
        if (v[i] > average) {
            balance += v[i] - average;
        }
        else {
            balance -= average - v[i];
        }

        if (balance < 0) {
            f = 0;
        }
    }

    puts(f ? "YES" : "NO");
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