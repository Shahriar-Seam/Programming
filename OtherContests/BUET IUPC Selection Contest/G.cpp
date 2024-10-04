#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, a, b, s, i, j, k;

    cin >> n >> a >> b;

    s = b - a + 1;

    vector <long long> v(n), sub(s, 0), max_subs(s);

    for (i = 0; i < s; i++) {
        max_subs[i] = LONG_LONG_MIN;
    }

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0, k = a; i < s; i++, k++) {
        for (j = 0; j < k; j++) {
            sub[i] += v[j];
        }
    }

    for (i = 0; i < s; i++) {
        max_subs[i] = sub[i];
    }

    for (i = 1; i < n; i++) {
        for (j = 0; j < s; j++) {
            sub[j] -= v[i - 1];
        }

        for (j = 0, k = a; j < s; j++, k++) {
            if (i + k - 1 < n - 1) {
                sub[j] += v[i + k - 1];
            }

            max_subs[j] = max(max_subs[j], sub[j]);
        }
    }

    cout << *max_element(max_subs.begin(), max_subs.end()) << "\n";

    return 0;
}