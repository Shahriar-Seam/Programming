#include <bits/stdc++.h>

using namespace std;

#define int long long

int min_fee = 1e18;

int visited_all(vector <int> &visited)
{
    for (auto &it : visited) {
        if (it < 2) {
            return 0;
        }
    }

    return 1;
}

void recurse(vector <int> &v, vector <vector <int> > &z, vector <int> &visited, int index, int fee, vector <int> &index_memo)
{
    if (visited_all(visited)) {
        min_fee = min(min_fee, fee);

        return;
    }

    if (index == v.size()) {
        return;
    }

    if (index_memo[index] < 2) {
        // take it
        // come again
        for (auto &it : z[index]) {
            visited[it]++;
        }
        
        index_memo[index]++;
        
        recurse(v, z, visited, index, fee + v[index], index_memo);
        
        // take it
        // go to next zoo
        recurse(v, z, visited, index + 1, fee + v[index], index_memo);

        // reset
        for (auto &it : z[index]) {
            visited[it]--;
        }

        index_memo[index]--;

        // don't take it
        // go to next
        recurse(v, z, visited, index + 1, fee, index_memo);
    }
    else {
        // don't take it
        // go to next
        recurse(v, z, visited, index + 1, fee, index_memo);
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, i, j, k, a;

    cin >> n >> m;

    vector <int> v(n), visited(m, 0), index_memo(n, 0);
    vector <vector <int> > z(n);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < m; i++) {
        cin >> k;

        for (j = 0; j < k; j++) {
            cin >> a;

            z[a - 1].push_back(i);
        }
    }

    recurse(v, z, visited, 0, 0, index_memo);

    cout << min_fee << "\n";

    return 0;
}