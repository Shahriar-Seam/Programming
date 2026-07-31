#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>

using namespace std;

// Generate a random integer in [L, R]
long long rnd(long long L, long long R, mt19937_64& rng) {
    uniform_int_distribution<long long> dist(L, R);
    return dist(rng);
}

int main(int argc, char* argv[]) {
    // Seed the random number generator
    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

    // Default sizes (max constraints)
    int n = 100000;
    int q = 100000;

    // Allow overriding N and Q via command line arguments
    // Usage: ./gen [N] [Q]
    if (argc > 1) n = atoi(argv[1]);
    if (argc > 2) q = atoi(argv[2]);

    cout << n << " " << q << "\n";

    // Generate array elements
    // We want a high concentration of small numbers to make the MEX interesting.
    for (int i = 0; i < n; i++) {
        int type = rnd(1, 100, rng);
        
        if (type <= 70) {
            // 70% chance: very small numbers, encouraging higher MEX values
            cout << rnd(0, min(100, n), rng);
        } else if (type <= 90) {
            // 20% chance: numbers up to N
            cout << rnd(0, n, rng);
        } else {
            // 10% chance: massive numbers up to 10^9 (which are ignored by MEX)
            cout << rnd(0, 1000000000, rng);
        }
        cout << (i == n - 1 ? "" : " ");
    }
    cout << "\n";

    // Generate queries
    for (int i = 0; i < q; i++) {
        int l = rnd(1, n, rng);
        int r = rnd(1, n, rng);
        
        if (l > r) swap(l, r); // Ensure L <= R
        
        cout << l << " " << r << "\n";
    }

    return 0;
}