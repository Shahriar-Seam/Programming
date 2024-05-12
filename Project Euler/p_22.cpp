#include <bits/stdc++.h>

using namespace std;

int __sum(string &s)
{
    int i, sum = 0;

    for (i = 0; i < s.size(); i++) {
        sum += (s[i] - 'A' + 1);
    }

    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("names.txt", "r", stdin);

    vector <string> v;
    string s;
    long long sum = 0, i = 1;

    while (getline(cin, s)) {
        v.push_back(s);
    }

    sort(v.begin(), v.end());

    for (auto it : v) {
        sum += __sum(it) * i;

        cout << i << " " << it << "\n";

        i++;
    }

    // for (auto it : v) {
    //     cout << it << "\n";
    // }

    cout << sum << "\n";

    s = "COLIN";

    cout << __sum(s);

    return 0;
}