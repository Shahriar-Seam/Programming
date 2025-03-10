#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, d, count = 0;
    int power, num;

    cin >> n >> d;

    deque <int> dq(n);

    for (auto &it : dq) {
        cin >> it;
    }

    sort(dq.begin(), dq.end(), greater <int> ());

    while (!dq.empty()) {
        if (dq.front() > d) {
            dq.pop_front();

            count++;
        }
        else {
            power = dq.front();
            dq.pop_front();

            num = d / power;

            while (!dq.empty() && num > 0) {
                dq.pop_back();

                num--;
            }

            if (num == 0) {
                count++;
            }
        }
    }

    cout << count << "\n";

    return 0;
}