#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i = 1;
    string s;

    cin >> n;

    vector <int> v(n), temp(n);

    iota(v.begin(), v.end(), 1);

    stable_sort(v.begin(), v.end(), [&] (int a, int b) {
        cout << "? " << a << " " << b << endl;
        cin >> s;

        return s == "YES";
    });

    for (auto &it : v) {
        temp[it - 1] = i++;
    }

    cout << "! ";

    for (auto &it : temp) {
        cout << it << " ";
    }

    cout << endl;

    return 0;
}