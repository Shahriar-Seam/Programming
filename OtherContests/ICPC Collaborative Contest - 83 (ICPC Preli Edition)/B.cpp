#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i, j, k, l;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    if (n > 75) {
        cout << "Yes\n";
    }
    else {
        for (i = 0; i < n; i++) {
            for (j = i + 1; j < n; j++) {
                for (k = j + 1; k < n; k++) {
                    for (l = k + 1; l < n; l++) {
                        if ((v[i] ^ v[j] ^ v[k] ^ v[l]) == 0) {
                            cout << "Yes\n";

                            return 0;
                        }
                    }
                }
            }
        }

        cout << "No\n";
    }

    return 0;
}