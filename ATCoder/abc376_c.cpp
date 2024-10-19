#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, new_box = 0, i, f = 1;

    cin >> n;

    vector <int> v(n), b(n - 1);

    for (auto &it : v) {
        cin >> it;
    }

    for (auto &it : b) {
        cin >> it;
    }

    sort(v.begin(), v.end(), greater <int> ());
    sort(b.begin(), b.end(), greater <int> ());

    new_box = v[n - 1];

    for (i = 0; i < n - 1; i++) {
        if (v[i] > b[i]) {
            new_box = v[i];

            break;
        }
    }

    b.push_back(new_box);

    sort(b.begin(), b.end(), greater <int> ());

    for (i = 0; i < n; i++) {
        if (v[i] > b[i]) {
            f = 0;
        }
    }

    cout << (f == 1 ? new_box : -1) << "\n";

    return 0;
}