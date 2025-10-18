#include <bits/stdc++.h>

using namespace std;

// rotate(s.begin(), s.begin() + min_rotation(s), s.end());
int min_rotation(string s)
{
    int a = 0, N = s.size(), b, k;

    s += s;

    for (b = 0; b < N; b++) {
        for (k = 0; k < N; k++) {
            if (a + k == b || s[a + k] < s[b + k]) {
                b += max(0, k - 1);

                break;
            }

            if (s[a + k] > s[b + k]) {
                a = b;

                break;
            }
        }
    }

    return a;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;

    cin >> s;

    rotate(s.begin(), s.begin() + min_rotation(s), s.end());

    cout << s << "\n";

    return 0;
}