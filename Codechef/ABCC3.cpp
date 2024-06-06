#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, a = 0, c = 0, b = 0, b_f, b_l, f = 0;
    int is_a = 0, is_b = 0, abc = 0;
    string s;

    cin >> n >> s;

    // for (i = 0; s[i] != '\0'; i++) {
    //     if (f == 0 && s[i] == 'b') {
    //         b_f = i;
    //         f = 1;
    //     }
    //     if (s[i] == 'b') {
    //         b++;
    //         b_l = i;
    //     }
    // }

    // for (i = 0; i < b_l; i++) {
    //     if (s[i] == 'a') {
    //         a++;
    //     }
    // }

    // for (i = b_f + 1; s[i] != '\0'; i++) {
    //     if (s[i] == 'c') {
    //         c++;
    //     }
    // }

    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] == 'a') {
            is_a++;
        }
        if (s[i] == 'b' && is_a > 0) {
            is_b++;
        }
        if (s[i] == 'c' && is_b > 0) {
            abc++;
            is_a--;
            is_b--;
        }
    }

    // cout << min({a, b, c, abc}) << "\n";

    cout << abc << "\n";
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