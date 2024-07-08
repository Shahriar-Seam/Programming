#include <bits/stdc++.h>

using namespace std;

string stem;

void recurse(vector <string> &w, string s)
{
    int f = 1;

    for (auto it : w) {
        if (it.find(s) == string::npos) {
            f = 0;

            break;
        }
    }

    if (f == 1) {
        stem = stem.length() < s.length() ? s : stem;

        return;
    }
    else {
        string temp = s;
        temp.pop_back();

        recurse(w, temp);

        temp = s;

        temp.erase(begin(temp));

        recurse(w, temp);
    }
}

void solve()
{
    int n;
    string s = "0000000000000000000000000000000";
    stem = "";

    cin >> n;

    vector <string> w(n);

    for (auto &it : w) {
        cin >> it;
    }

    for (auto it : w) {
        if (it.length() < s.length()) {
            s = it;
        }
    }

    recurse(w, s);

    cout << stem << "\n";
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