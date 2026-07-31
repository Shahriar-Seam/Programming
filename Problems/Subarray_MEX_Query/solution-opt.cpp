#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Pass the tree array by reference to avoid global hardcoded limits
void update(int node, int start, int end, int val, int idx, vector<int>& tree) {
    if (start == end) {
        tree[node] = idx;
        return;
    }
    int mid = start + (end - start) / 2;
    if (val <= mid) {
        update(2 * node, start, mid, val, idx, tree);
    } else {
        update(2 * node + 1, mid + 1, end, val, idx, tree);
    }
    tree[node] = min(tree[2 * node], tree[2 * node + 1]);
}

int query(int node, int start, int end, int L, const vector<int>& tree) {
    if (start == end) {
        return start; 
    }
    int mid = start + (end - start) / 2;
    
    if (tree[2 * node] < L) {
        return query(2 * node, start, mid, L, tree);
    } 
    else {
        return query(2 * node + 1, mid + 1, end, L, tree);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    if (!(cin >> n >> q)) return 0;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<vector<pair<int, int>>> queries(n + 1);
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        queries[r].push_back({l, i});
    }

    vector<int> ans(q);
    int max_val = n + 1; 
    
    // Dynamically size the tree to exactly 4 times the maximum possible value.
    // Zero-initialized by default, preserving your brilliant logic.
    vector<int> tree(4 * (max_val + 1), 0); 

    for (int r = 1; r <= n; r++) {
        if (a[r] <= max_val) {
            update(1, 0, max_val, a[r], r, tree);
        }
        
        for (auto& p : queries[r]) {
            int l = p.first;
            int query_index = p.second;
            ans[query_index] = query(1, 0, max_val, l, tree);
        }
    }

    for (int i = 0; i < q; i++) {
        cout << ans[i] << "\n";
    }

    return 0;
}