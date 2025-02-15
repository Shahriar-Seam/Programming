#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i, j, k, count = 0, n;
    string s;
    vector <int> a, b, c;

    cin >> s;

    n = s.size();

    for (i = 0; i < n; i++) {
        if (s[i] == 'A') {
            a.push_back(i);
        }
        else if (s[i] == 'B') {
            b.push_back(i);
        }
        else if (s[i] == 'C') {
            c.push_back(i);
        }
    }

    for (i = 0; i < a.size(); i++) {
        for (j = 0; j < c.size(); j++) {
            if ((a[i] < c[j]) && ((a[i] + c[j]) % 2 == 0) && binary_search(b.begin(), b.end(), (a[i] + c[j]) / 2)) {
                count++;
            }
        }
    }

    cout << count << "\n";

    return 0;
}