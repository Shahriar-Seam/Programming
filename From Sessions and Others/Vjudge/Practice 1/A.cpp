#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, i, first, last, temp;
    vector <int> v;

    cin >> t;

    while (t--) {
        cin >> n;

        first = last = 0;

        for (i = 0; i < n; i++) {
            cin >> temp;

            v.push_back(temp);
        }

        for (i = 0; i < n; i++) {
            if (v[i] == v[0]) {
                first++;
            }
            else {
                break;
            }
        }
        for (i = n - 1; i >= 0; i--) {
            if (v[i] == v[n - 1]) {
                last++;
            }
            else {
                break;
            }
        }

        if (v[0] == v[n - 1]) {
            cout << max(n - first - last, 0) << "\n";
        }
        else {
            cout << n - max(first, last) << "\n";
        }

        v.clear();
    }

    return 0;
}