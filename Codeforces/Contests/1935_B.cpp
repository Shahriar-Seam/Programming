#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, temp, i, j, mex = 0;
    set <int> s;
    vector <int> v;

    cin >> n;

    for (i = 0; i < n; i++) {
        cin >> temp;

        s.insert(temp);
        v.push_back(temp);
    }

    i = 0;
    for (auto it = s.begin(); it != s.end(); it++, i++) {
        if (*it != i) {
            mex = i;
            break;
        }
    }

    if (*s.begin() == 0 && mex == 0) {
        mex = *s.rbegin() + 1;
    }

    set <int> cnt;

    i = 0;
    while (cnt.size() < mex && i < n) {
        if (v[i] < mex) {
            cnt.insert(v[i]);
        }

        i++;
    }

    //cout << "mex = " << mex << ", i = " << i << endl;

    if (i == n) {
        cout << -1 << "\n";
    }
    else if (mex == 0) {
        cout << 2 << "\n";
        cout << "1 1\n" ;
        cout << "2 " << n << "\n" ;
    }
    else if (s.size() == 1) {
        cout << "2\n1 1\n2 2\n";
    }
    else {
        set <int> second_part;
        int second_mex = 0;

        for (j = i; j < n; j++) {
            second_part.insert(v[j]);
        }

        j = 0;
        for (auto it = second_part.begin(); it != second_part.end(); it++, j++) {
            if (*it != j) {
                second_mex = j;
                break;
            }
        }

        if (mex == second_mex) {
            cout << 2 << "\n";
            cout << "1 " << i << "\n";
            cout << i + 1 << " " << n << "\n";
        }
        else {
            cout << "-1\n";
        }
    }
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