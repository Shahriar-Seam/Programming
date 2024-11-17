#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i;
    map <int, vector <int> > mp;
    
    mp[5] = {1, 3, 5, 4, 2};
    mp[6] = {1, 3, 5, 4, 6, 2};
    mp[7] = {1, 3, 5, 4, 6, 2, 7};
    mp[8] = {1, 3, 5, 4, 2, 6, 8, 7};

    cin >> n;

    if (n < 5) {
        cout << -1 << "\n";
    }
    else if (n <= 8) {
        for (auto it : mp[n]) {
            cout << it << " ";
        }

        cout << "\n";
    }
    else {
        cout << "1 3 5 4 2 6 ";

        for (i = 10; i <= n; i += 2) {
            cout << i << " ";
        }

        cout << 8 << " ";

        for (i = 7; i <= n; i += 2) {
            cout << i << " ";
        }

        cout << "\n";
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