#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cases, i;

    cin >> cases;

    for (i = 0; i < cases; i++) {
        int n, p, l, t;
        std::cin >> n >> p >> l >> t;

        int days_on = 0;
        int tasks = std::ceil((double)n / 7);

        int all_tasks = p - tasks * t;

        if (all_tasks <= 0) {
            std::cout << n - 1 << std::endl;
        }

        while (true) {
            if (p <= 0) {
                std::cout << n - days_on << std::endl;
                break;
            } else {
                days_on += 1;
                p -= (l + 2 * t);
                tasks -= 2;
                if (tasks <= 0) {
                    t = 0;
                }
            }
        }
    }

    return 0;
}