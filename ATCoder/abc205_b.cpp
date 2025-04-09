#include <bits/stdc++.h>

using namespace std;

bool valid(vector <int> &counter)
{
    for (auto it : counter) {
        if (it != 1) {
            return false;
        }
    }

    return true;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    vector <int> v(n), counter(n, 0);

    for (auto &it : v) {
        cin >> it;

        counter[it - 1]++;
    }

    cout << (valid(counter) ? "Yes" : "No") << "\n";

    return 0;
}