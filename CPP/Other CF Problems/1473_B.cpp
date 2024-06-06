#include <bits/stdc++.h>

using namespace std;

void solve()
{
    string s, t;
    int s_len, t_len, lcm_s_t;
    string s_lcm, t_lcm;
    int i;

    cin >> s >> t;

    s_len = s.size();
    t_len = t.size();

    lcm_s_t = lcm(s_len, t_len);

    for (i = 0; i < lcm_s_t / s_len; i++) {
        s_lcm += s;
    }

    for (i = 0; i < lcm_s_t / t_len; i++) {
        t_lcm += t;
    }

    if (s_lcm == t_lcm) {
        cout << s_lcm << "\n";
    }
    else {
        cout << "-1\n";
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