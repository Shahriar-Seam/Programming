#include <bits/stdc++.h>

using namespace std;

int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, max_val = 0;
    map <int, int> total, pref;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;

        total[it]++;
    }

    for (auto it : v) {
        pref[it]++;
        total[it]--;

        if (total[it] == 0) {
            total.erase(it);
        }

        max_val = max(max_val, pref.size() + total.size());
    }

    cout << max_val << "\n";

    return 0;
}