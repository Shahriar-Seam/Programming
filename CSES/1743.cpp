#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s, t;
    int n, i, j, rem, f;

    cin >> s;

    n = s.size();

    vector <int> freq(26, 0);

    for (i = 0; i < n; i++) {
        freq[s[i] - 'A']++;
    }

    while (t.size() < n) {
        bool anything = false;

        for (i = 0; i < 26; i++) {
            if (freq[i] > 0 && (t.empty() || t.back() != ('A' + i))) {
                rem = n - t.size() - 1;
                f = 1;

                for (j = 0; j < 26; j++) {
                    if (i == j) {
                        if (freq[j] - 1 > rem / 2) {
                            f = 0;

                            break;
                        }
                    }
                    else {
                        if (freq[j] > (rem + 1) / 2) {
                            f = 0;

                            break;
                        }
                    }
                }

                if (f) {
                    freq[i]--;

                    t += ('A' + i);

                    anything = true;

                    break;
                }
            }
        }

        if (!anything) {
            break;
        }
    }

    cout << (t.size() == n ? t : "-1") << "\n";

    return 0;
}