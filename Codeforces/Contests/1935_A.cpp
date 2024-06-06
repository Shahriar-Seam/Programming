#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    string s1, s2, s3, s4, s;

    cin >> n >> s1;

    s2 = s1;

    reverse(s2.begin(), s2.end());
    
    s3 = s2 + s1;
    s4 = s1 + s2;

    s = min({s1, s3, s4});

    cout << s << "\n";
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