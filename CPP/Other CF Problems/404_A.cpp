#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i, j, f = 1;
    set <char> x, not_x;

    cin >> n;

    string s[n];

    for (i = 0; i < n; i++) {
        cin >> s[i];
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i == j || i == n - j - 1 || j == n - i - 1) {
                x.insert(s[i][j]);
            }
            else {
                not_x.insert(s[i][j]);
            }
        }
    }

    if (x.size() == 1 && not_x.size() == 1) {
        x.merge(not_x);

        if (x.size() == 2) {
            puts("YES");
        }
        else {
            puts("NO");
        }
    }
    else {
        puts("NO");
    }

    return 0;
}