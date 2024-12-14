#include <bits/stdc++.h>

using namespace std;

int get_team_number(vector <vector <int> > &teams, int element)
{
    int i;

    for (i = 0; i < teams.size(); i++) {
        if (binary_search(teams[i].begin(), teams[i].end(), element)) {
            return i;
        }
    }

    return 0;
}

void solve(int n)
{
    int num_elements, element, team_num;
    int i, j;
    string op;
    vector <vector <int> > teams(n, vector <int> ());
    queue <int> order;
    vector <bool> marked(n, false);
    vector <queue <int> > team_queues(n, queue <int> ());

    for (i = 0; i < n; i++) {
        cin >> num_elements;

        for (j = 0; j < num_elements; j++) {
            cin >> element;

            teams[i].push_back(element);
        }
    }

    for (i = 0; i < n; i++) {
        sort(teams[i].begin(), teams[i].end());
    }

    while (true) {
        cin >> op;

        if (op == "STOP") {
            break;
        }
        else if (op == "ENQUEUE") {
            cin >> element;

            team_num = get_team_number(teams, element);

            if (!marked[team_num]) {
                marked[team_num] = true;
                order.push(team_num);
            }

            team_queues[team_num].push(element);
        }
        else {
            if (order.empty()) {
                continue;
            }

            team_num = order.front();

            element = team_queues[team_num].front();

            cout << element << "\n";

            team_queues[team_num].pop();

            if (team_queues[team_num].empty() && !order.empty()) {
                marked[team_num] = false;
                order.pop();
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, i;

    for (i = 1; ; i++) {
        cin >> t;

        if (t == 0) {
            break;
        }

        cout << "Scenario #" << i << "\n";

        solve(t);

        cout << "\n";
    }

    return 0;
}