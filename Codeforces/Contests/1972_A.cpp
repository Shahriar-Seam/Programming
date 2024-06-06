#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, j, temp, cnt = 0;
    vector <int> a, b;

    cin >> n;

    for (i = 0; i < n; i++) {
        cin >> temp;

        a.push_back(temp);
    }
    
    for (i = 0; i < n; i++) {
        cin >> temp;

        b.push_back(temp);
    }

    for (i = 0, j = 0; i < n; i++) {
        if (b[i] < a[j]) {
            cnt++;
        }
        else {
            j++;
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

    return 0;
}