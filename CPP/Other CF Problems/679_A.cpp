#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cnt = 0;
    string s;

    vector <int> d = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 4, 9, 25, 49};

    for (auto &it : d) {
        cout << it << endl;

        cin >> s;

        cnt += s == "yes";
    }

    cout << (cnt <= 1 ? "prime" : "composite") << endl;

    return 0;
}