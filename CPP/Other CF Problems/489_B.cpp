#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int b, g, i, j, n, cnt = 0;
    vector <int> boys;
    vector <int> girls;

    cin >> b;

    for (i = 0; i < b; i++) {
        cin >> n;

        boys.push_back(n);
    }

    cin >> g;

    for (i = 0; i < g; i++) {
        cin >> n;

        girls.push_back(n);
    }

    sort(boys.begin(), boys.end());
    sort(girls.begin(), girls.end());

    for (i = 0; i < b; i++) {
        if (boys[i] == -1) {
            continue;
        }
        for (j = 0; j < g; j++) {
            if (boys[i] == girls[j] || boys[i] == girls[j] - 1 || boys[i] == girls[j] + 1) {
                cnt++;
                boys[i] = girls[j] = -1;
                break;
            }
        }
    }

    cout << cnt;

    return 0;
}