#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    stack <int> st;
    set <char> sc;
    vector <pair <int, char> > v;
    int i, j, k, n, f = 1;
    
    cin >> s;
    
    n = s.size();

    vector <vector <int> > counter(n + 1, vector <int> (26, 0));

    for (i = 0; i < n; i++) {
        if (isalpha(s[i])) {
            counter[i][s[i] - 'a']++;
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < 26; j++) {
            counter[i + 1][j] += counter[i][j];
        }
    }

    for (i = 0; i < n; i++) {
        if (s[i] == '(') {
            st.push(i);
        }
        else if (s[i] == ')') {
            j = st.top();
            st.pop();

            for (k = 0; k < 26; k++) {
                if (counter[j][k] != counter[i][k]) {
                    auto it = sc.find('a' + k);

                    if (it != sc.end()) {
                        sc.erase(it);
                    }
                }
            }
        }
        else {
            v.push_back({i, s[i]});

            if (sc.find(s[i]) == sc.end()) {
                sc.insert(s[i]);
            }
            else {
                f = 0;

                break;
            }
        }
    }

    cout << (f ? "Yes" : "No") << "\n";

    return 0;
}