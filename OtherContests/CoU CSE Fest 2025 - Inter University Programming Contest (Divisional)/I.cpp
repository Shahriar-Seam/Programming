#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define int long long
template <typename T>
using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 1e6 + 7, M = 1e9 + 7;
int arr[N];
int dp[N][30];
string s;
int dpf(int i, int pre)
{
    if(i == s.size())
    {
        return 1;
    }
    
    if(dp[i][pre] != -1) return dp[i][pre];
    
    int ans = (dpf(i + 1, s[i] - 'a' + 1) + 1) % M;
    
    if(pre == 0)
    {
        ans = (ans + dpf(i + 1, s[i] - 'a' + 1)) % M;
    }
    else if(pre == (s[i] - 'a' + 1))
    {
        ans = (ans + dpf(i + 1, 0)) % M;
    }

    return dp[i][pre] = ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tc = 1;
    cin >> tc;
    while (tc--)
    {

       cin >> s;
       for (int i = 0; i <= s.size() + 2; ++i)
       {
           for(int j = 0; j <= 27; j++)
           {
                dp[i][j] = -1;
           }
       }
       cout << dpf(0, 27) - 1 << endl;
    }
    return 0;
}