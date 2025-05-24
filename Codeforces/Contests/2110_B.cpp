#include <bits/stdc++.h>

using namespace std;

bool is_balanced(string &s)
{
    stack<char> st;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            st.push(s[i]); 
        }
        else {
            if (!st.empty()) {
                st.pop(); 
            }
            else {
                return false; 
            }
        }
    }
    
    return st.empty();
}

void solve()
{
    string s;
    int n, i, j, f = 1;

    cin >> s;

    n = s.size();

    s.pop_back();
    s.erase(s.begin());

    cout << (!is_balanced(s) ? "YES\n" : "NO\n");
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int32_t t, i;

    cin >> t;

    for (i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";

        solve();
    }

    return 0;
}