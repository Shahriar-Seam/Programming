#include <bits/stdc++.h>

using namespace std;

#define int long long

struct node {
    int xor_val = -1, pos = -1, count = -1;
};

int build(int index, vector <node> &nodes)
{
    if (nodes[index].count == 1) {
        return nodes[index].xor_val;
    }
    else {
        nodes[index].xor_val = build(index * 2, nodes) ^ build(index * 2 + 1, nodes);

        nodes[index].count = nodes[index * 2].count + nodes[index * 2 + 1].count;

        return nodes[index].xor_val;
    }
}

void go_up(int index, vector <node> &nodes)
{
    if (index > 0) {
        auto l = nodes[index * 2];
        auto r = nodes[index * 2 + 1];

        nodes[index].xor_val = l.xor_val ^ r.xor_val;

        if (l.pos == -1 && r.pos == -1) {
            nodes[index].pos = -1;
        }
        else if (l.xor_val >= r.xor_val) {
            if (l.pos == -1) {
                nodes[index].pos = r.pos + l.count;
            }
            else {
                nodes[index].pos = l.pos;
            }
        }
        else {
            if (r.pos == -1) {
                nodes[index].pos = l.pos + r.count;
            }
            else {
                nodes[index].pos = r.pos;
            }
        }

        go_up(index / 2, nodes);
    }
}

void solve()
{
    int n, n2, m, i, b, c;

    cin >> n >> m;

    n2 = 1 << n;

    vector <int> v(n2);
    vector <node> nodes(n2 * 2);

    for (i = 0; i < n2; i++) {
        cin >> v[i];

        nodes[n2 + i].xor_val = v[i];
        nodes[n2 + i].pos = -1;
        nodes[n2 + i].count = 1;
    }

    build(1, nodes);

    while (m--) {
        cin >> b >> c;

        nodes[n2 + b - 1].xor_val = c;
        nodes[n2 + b - 1].pos = 1;

        go_up((n2 + b - 1) / 2, nodes);
        
        cout << nodes[1].pos - 1 << "\n";

        nodes[n2 + b - 1].xor_val = v[b - 1];
        nodes[n2 + b - 1].pos = -1;

        go_up((n2 + b - 1) / 2, nodes);
    }
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