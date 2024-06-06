#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, cnt = 0;
    string s;
    bool *swapped;

    cin >> n >> s;

    swapped = new bool[n]();

    reverse(s.begin(), s.end());

    for (int i = 0; i < n - 1; i++) {
        if (s[i] == 'B' && s[i + 1] == 'A' && swapped[i] == false) {
            swap(s[i], s[i + 1]);

            cnt++;

            swapped[i] = true;

            i -= 2;
        }
    }

    cout << cnt << "\n";
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
}