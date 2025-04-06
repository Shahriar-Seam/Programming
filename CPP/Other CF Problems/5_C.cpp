#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    stack <int> st;
    vector <bool> regular(int(1e6 + 5), false);
    map <int, int, greater <int> > mp;
    int i, count = 0;

    cin >> s;

    for (i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            st.push(i);
        }
        else {
            if (!st.empty()) {
                regular[i] = regular[st.top()] = true;
                st.pop();
            }
        }
    }

    for (i = 0; i < s.size(); i++) {
        if (regular[i]) {
            count++;
        }
        else {
            mp[count]++;
            
            count = 0;
        }
    }

    mp[count]++;

    mp[0] = 1;

    cout << (*mp.begin()).first << " " << (*mp.begin()).second << "\n";

    return 0;
}