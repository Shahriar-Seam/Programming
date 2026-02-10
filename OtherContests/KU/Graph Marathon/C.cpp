#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i, u, v;

    cin >> n;

    vector <set <int> > adj_list(n + 1);
    deque <int> dq, order(n), new_order, temp;

    for (i = 1; i < n; i++) {
        cin >> u >> v;

        adj_list[u].insert(v);
        adj_list[v].insert(u);
    }

    for (auto &it : order) {
        cin >> it;
    }

    temp = order;

    dq.push_back(order.front());

    order.pop_front();

    while (!dq.empty()) {
        u = dq.front();

        new_order.push_back(u);

        dq.pop_front();

        while (adj_list[u].find(order.front()) != adj_list[u].end()) {
            dq.push_back(order.front());

            adj_list[order.front()].erase(u);
            adj_list[u].erase(order.front());

            order.pop_front();
        }
    }

    cout << (new_order == temp && temp.front() == 1 ? "Yes" : "No") << "\n";

    return 0;
}