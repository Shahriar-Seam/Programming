#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
const int N = 1e6 + 9;
int ax = 0, ay = 0;

int phi[N], arr[N];
pair<int, int> val[N], nx[N];

deque<int> v2, v3;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tc = 1;
    cin >> tc;

    while (tc--) 
    {
        int n, q; cin >> n >> q;
        string s; cin >> s;

        for (int i = 0; i < n - 2; ++i)
        {
            if(s[i] == s[i + 2])
            {
                v3.push_back(i);
            }
            else if(s[i] == s[i + 1] or s[i + 1] == s[i + 2])
            {
                v3.push_back(i);
            }

        }
        // for(auto el : v3) cout << el << " ";
        while(q--)
        {
            int l, r; cin >> l >> r;
            l--;
            r--;
            int cnt2 = lower_bound(v3.begin(), v3.end(), r - 1) - lower_bound(v3.begin(), v3.end(), l);
            // cout << cnt2 << endl;
            if(r - l >= 2 and cnt2) cout << "YES\n";
            else cout << "NO\n";
            
        }
        v3.clear();
    }

    return 0;
}