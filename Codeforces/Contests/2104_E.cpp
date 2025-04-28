#include <bits/stdc++.h>

using namespace std;

int min(int a, int b)
{
    return a < b ? a : b;
}

int sub_seq(string &s, string &t)
{
    if (t.size() > s.size()) {
        return -1;
    }

    int i = 0, j = 0;

    while (i < s.length() && j < t.length()) {
        if (s[i] == t[j]) {
            j++;
        }

        i++;
    }

    if (i == s.size() && j == t.size()) {
        return -2;
    }

    return (j == t.size()) ? i : -1;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, q, i, j;
    string s, t;
    int min_val, index;
    
    cin >> n >> k >> s;
    
    vector <int> counter(k, 0);
    vector <pair <int, int> > min_letter(n + 1);

    min_letter[n] = {0, 0};

    for (i = n - 1; i >= 0; i--) {
        counter[s[i] - 'a']++;

        min_val = 1e9;
        index = 0;

        for (j = 0; j < k; j++) {
            if (counter[j] < min_val) {
                min_val = counter[j];
                index = j;
            }
        }

        min_letter[i] = {index, min_val};
    }

    cin >> q;

    while (q--) {
        cin >> t;

        index = sub_seq(s, t);

        if (index == -1) {
            cout << 0 << "\n";
        }
        else if (index == -2) {
            cout << 1 << "\n";
        }
        else {
            cout << min(min_letter[index].second + 1, s.size() - t.size() + 1) << "\n";
        }
    }

    return 0;
}