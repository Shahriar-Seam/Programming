#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x, i, j, a = -1, b = -1;

    cin >> n >> x;

    vector <pair <int, int> > v(n);

    for (i = 0; i < n; i++) {
        cin >> v[i].first;

        v[i].second = i + 1;
    }

    sort(v.begin(), v.end());

    for (i = 0, j = n - 1; i < j; ) {
        if (v[i].first + v[j].first == x) {
            a = v[i].second;
            b = v[j].second;

            break;
        }
        else if (v[i].first + v[j].first < x) {
            i++;
        }
        else {
            j--;
        }
    }

    if (a == -1 && b == -1) {
        cout << "IMPOSSIBLE" << "\n";
    }
    else {
        cout << a << " " << b << "\n";
    }

    return 0;
}