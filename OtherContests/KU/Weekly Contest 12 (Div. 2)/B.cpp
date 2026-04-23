#include <bits/stdc++.h>

using namespace std;

int len;

void dfs(int u, int l, vector <vector <int> > &adj_list, vector <bool> &visited)
{
    visited[u] = true;

    for (int v : adj_list[u]) {
        if (!visited[v]) {
            dfs(v, l + 1, adj_list, visited);
        }
        else {
            len = l;

            return;
        }
    }
}

void solve()
{
    int n, i, j, f;
    string t, s = "";
    vector <vector <int> > adj_list(256, vector <int> ());
    
    cin >> n >> t;
    
    for (auto &C : t) {
        int c = int(C);

        if (adj_list[c].empty()) {
            for (i = 'a'; i <= 'z'; i++) {
                adj_list[c].push_back(i);
                f = 1;
                
                for (j = 'a'; j <= 'z'; j++) {
                    vector <bool> visited(256, false);
                    
                    if (!visited[j]) {
                        len = 26;

                        dfs(j, 0, adj_list, visited);

                        if (len < 26) {
                            f = 0;

                            break;
                        }
                    }
                }

                if (f) {
                    break;
                }
                else {
                    adj_list[c].pop_back();
                }
            }
        }
        
        s += adj_list[c].back();
    }

    cout << s << "\n";
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