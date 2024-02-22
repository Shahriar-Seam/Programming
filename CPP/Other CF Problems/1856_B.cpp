#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, temp, sum = 0;
    set <int> s;

    cin >> n;

    for (i = 0; i < n; i++) {
        cin >> temp;

        sum += temp;

        s.insert(temp);
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