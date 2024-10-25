#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i, j, sorted = 0;

    cin >> n;

    vector <int> a(n), b(n), indices(n + 1, 0);
    vector <tuple <int, int, char> > v;

    for (auto &it : a) {
        cin >> it;
    }

    for (auto &it : b) {
        cin >> it;
    }

    sorted = is_sorted(a.begin(), a.end()) || is_sorted(a.begin(), a.end(), greater <int> ());

    if (a == b) {
        cout << 0;

        return 0;
    }

    if (!sorted) {
        v.push_back({1, n, 'I'});

        sort(a.begin(), a.end());
    }

    for (i = 0; i < n; i++) {
        indices[a[i]] = i;
    }

    for (i = 0; i < n; i++) {
        for (j = i; j < n; j++) {
            indices[a[j]] = j;
        }

        if (a == b) {
            break;
        }

        if (a[i] != b[i]) {
            if (a[i] < b[i]) {
                sort(a.begin() + i, a.begin() + indices[b[i]] + 1, greater <int> ());

                v.push_back({i + 1, indices[b[i]] + 1, 'D'});
            }
            else {
                sort(a.begin() + i, a.begin() + indices[b[i]] + 1);

                v.push_back({i + 1, indices[b[i]] + 1, 'I'});
            }
        }
    }

    cout << v.size() << "\n";

    for (auto it : v) {
        cout << get <0> (it) << " ";
        cout << get <1> (it) << " ";
        cout << get <2> (it) << "\n";
    }

    return 0;
}