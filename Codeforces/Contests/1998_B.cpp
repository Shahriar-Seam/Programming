#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, temp, i;

    cin >> n;

    vector <int> v(n), v_f, v_l;

    for (auto &it : v) {
        cin >> it;
    }

    v_f = v;
    v_l = v;

    if (n % 2 == 0) {
        for (auto it = v.rbegin(); it != v.rend(); it++) {
            cout << *it << " ";
        }
        
        cout << "\n";

        return;
    }

    temp = v[n / 2];

    v_f.erase(v_f.begin() + n / 2);
    v_l.erase(v_l.begin() + n / 2);
    
    v_f.push_back(temp);

    reverse(v_f.begin(), v_f.end());
    reverse(v_l.begin(), v_l.end());

    v_l.push_back(temp);

    int count_f = 0, count_l = 0;

    for (i = 0; i < n - 1; i++) {
        if (v[i] + v[i + 1] == v_f[i] + v_f[i + 1]) {
            count_f++;
        }
    }

    for (i = 0; i < n - 1; i++) {
        if (v[i] + v[i + 1] == v_l[i] + v_l[i + 1]) {
            count_l++;
        }
    }

    for (auto it : v) {
        cout << it << " ";
    }
    cout << "\n";

    if (count_f < count_l) {
        v = v_f;
    }
    else {
        v = v_l;
    }

    for (auto it : v) {
        cout << it << " ";
    }

    cout << "\n" << count_f << " " << count_l;

    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}