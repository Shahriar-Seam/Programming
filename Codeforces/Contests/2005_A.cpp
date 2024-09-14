#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, j = 0, k = 0;
    string s, v = "aeiou";

    cin >> n;
    
    if (n <= 5) {
        while (s.size() < n) {
            s += v[j++ % 5];
        }
    }
    else {
        for (i = 0; i < 5; i++) {
            j = 0;
            while (j < n / 5) {
                s += v[k % 5];
                j++;
            }

            k++;
        }

        for (i = 0, j = 0; s.size() < n; i += n / 5, j++) {
            // s += 'u';
            s.insert(s.begin() + i + j, s[i + j]);
        }
    }

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