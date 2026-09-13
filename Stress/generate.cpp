#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("C:/Users/Anonymous_HF/Desktop/Programming/input.txt", "w", stdout);

    // sieve();

    srand(time(0));

    int t = 1000;

    cout << t << "\n";

    for (int i = 0; i < t; i++) {
        int n = ((rand() + 1LL) * (rand() + 1)) % ((int) 1e9);
        int w = ((rand() + 1LL) * (rand() + 1)) % ((int) 1e9);
        // int q = rand() % 10 + 1;
        // int x = primes[rand() % 500 + 2];

        cout << n << " " << w << "\n";

        // cout << (long long) (1LL * rand() * 213456) % (long long) 1e15;
        // cout << n << "\n";
        // while (n--) {
        //     cout << rand() % 100000 + 1 << " ";
        // }

        // cout << "\n";
    }

    return 0;
}