#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k, count = 0;

    cin >> n >> m >> k;

    deque <int> a(n), b(m);

    for (auto &it : a) {
        cin >> it;
    }

    for (auto &it : b) {
        cin >> it;
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    while (!a.empty() && !b.empty()) {
        if (a.front() <= b.front()) {
            if (a.front() + k >= b.front()) {
                a.pop_front();
                b.pop_front();

                count++;
            }
            else {
                a.pop_front();
            }
        }
        else {
            if (a.front() - k <= b.front()) {
                a.pop_front();
                b.pop_front();

                count++;
            }
            else {
                b.pop_front();
            }
        }
    }

    cout << count << "\n";

    return 0;
}