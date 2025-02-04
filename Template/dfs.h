#include <bits/stdc++.h>

using namespace std;

/**
 * Author:  Ibnul Abrar Shahriar Seam
 * Date: 2025-02-04
 * License: CC0
 * Description: DFS
 * Time: O(V + E)
**/

int n; // number of vertices
vector <vector <int> > adj_list;
vector <bool> visited;

void dfs(int u)
{
    visited[u] = true;

    // operation on node
    cout << u << " ";

    for (int v : adj_list[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}