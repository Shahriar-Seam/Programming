#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n = 3, c = 6;
    int i, j;
    set <int> s;
    string ss;

    for (i = 0; i <= c; i++) {
        for (j = 0; j <= c; j++) {
            s.insert(i + j);
        }
    }

    cout << s.size() << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;

    //cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}