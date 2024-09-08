#include <bits/stdc++.h>

using namespace std;

#define print(s) cout << (s) << "\n"

int possible(string s, string a, string b)
{
    int i, j, k, f = 0;

    for (i = 0, j = 0; i < s.size(); i++) {
        if (s[i] == a[j]) {
            k = i;

            while (k < s.size() && j < a.size() && s[k] == a[j]) {
                k++;
                j++;
            }

            if (j == a.size()) {
                f = 1;

                i = k;

                break;
            }
            else {
                j = 0;
            }
        }
    }

    if (f) {
        for (i, j = 0; i < s.size(); i++) {
            if (s[i] == b[0]) {
                k = i;

                while (k < s.size() && j < b.size() && s[k] == b[j]) {
                    k++;
                    j++;
                }

                if (j == b.size()) {
                    return 1;
                }
                else {
                    j = 0;
                }
            }
        }
    }

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int fwd = 0, bwd = 0;
    string s, a, b;

    cin >> s >> a >> b;

    fwd = possible(s, a, b);

    reverse(s.begin(), s.end());

    bwd = possible(s, a, b);

    if (fwd && bwd) {
        print("both");
    }
    else if (fwd) {
        print("forward");
    }
    else if (bwd) {
        print("backward");
    }
    else {
        print("fantasy");
    }

    return 0;
}