#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i, l, lf = 0, r, rf = 0, temp;
    vector <int> v1, v2;

    cin >> n;

    for (i = 0; i < n; i++) {
        cin >> temp;

        v1.push_back(temp);
        v2.push_back(temp);
    }

    sort(v1.begin(), v1.end());

    if (v2 == v1) {
        cout << "yes\n1 1\n";

        return 0;
    }

    for (i = 0; i < n - 1; i++) {
        if (!lf && (v2[i] > v2[i + 1])) {
            l = i;

            lf = 1;
        }
        else if (lf && !rf && (v2[i] < v2[i + 1])) {
            r = i;

            rf = 1;
        }
    }

    if (rf == 0) {
        r = n - 1;
    }

    reverse(v2.begin() + l, v2.begin() + r + 1);

    if (v1 == v2) {
        cout << "yes\n";

        cout << l + 1 << " " << r + 1 << "\n";
    }
    else {
        cout << "no\n";
    }

    return 0;
}