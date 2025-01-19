#include <bits/stdc++.h>

using namespace std;

int possible(string &s, vector <vector <int> > &pref, int len)
{
    vector <int> indices(5, -1);
    int l = 0, r = s.size(), mid, i, temp, f = 1;

    for (i = 0; i < 5; i++) {
        l = (i > 0 ? indices[i - 1] : 0);
        r = s.size();
        temp = ((i > 0) && (indices[i - 1] > 0) ? pref[indices[i - 1]][i] : 0);

        while (l <= r) {
            mid = (l + r) / 2;

            if (pref[mid][i] >= len - temp) {
                indices[i] = mid;

                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }

        if (indices[i] < 0) {
            return 0;
        }
    }

    for (i = 1; i < 5; i++) {
        if (indices[i] <= indices[i - 1]) {
            return 0;
        }
    }

    return 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    int i, power = 0;

    cin >> s;

    vector <vector <int> > pref(s.size() + 1, vector <int> (5, 0));

    for (i = 0; i < s.size(); i++) {
        if (s[i] == 'S') {
            pref[i][0]++;
        }
        else if (s[i] == 'N') {
            pref[i][1]++;
        }
        else if (s[i] == 'A') {
            pref[i][2]++;
        }
        else if (s[i] == 'K') {
            pref[i][3]++;
        }
        else if (s[i] == 'E') {
            pref[i][4]++;
        }
        
        pref[i + 1][0] = pref[i][0];
        pref[i + 1][1] = pref[i][1];
        pref[i + 1][2] = pref[i][2];
        pref[i + 1][3] = pref[i][3];
        pref[i + 1][4] = pref[i][4];
    }

    // binary search on possible length
    int l = 0, r = s.size(), mid;

    for (i = 0; i < 30; i++) {
        mid = (l + r) / 2;

        if (possible(s, pref, mid)) {
            power = mid;

            l = mid;
        }
        else {
            r = mid;
        }
    }

    cout << power << "\n";

    return 0;
}