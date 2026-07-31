#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

    int mode = atoi(argv[1]);
    int N = 100000, Q = 100000;

    if (mode == 1) {
        // ---- PERMUTATION + LARGE RANGE QUERIES ----
        // Array is a random permutation of [0..N-1].
        // Queries span large ranges (L in first quarter, R in last quarter).
        // Guarantees high MEX values since most queries cover most of the permutation.
        cout << N << " " << Q << "\n";
        vector<int> perm(N);
        iota(perm.begin(), perm.end(), 0);
        shuffle(perm.begin(), perm.end(), rng);
        for (int i = 0; i < N; i++) cout << perm[i] << " \n"[i == N - 1];
        for (int i = 0; i < Q; i++) {
            int l = rng() % (N / 4) + 1;
            int r = N - rng() % (N / 4);
            cout << l << " " << r << "\n";
        }
    }
    else if (mode == 2) {
        // ---- SEQUENTIAL ARRAY + SWEEP QUERIES ----
        // Array = [0, 1, 2, ..., N-1]. Query [1, k] gives MEX = k.
        // Sweeps k from 1 to N across Q queries -> MEX grows linearly to N.
        cout << N << " " << Q << "\n";
        for (int i = 0; i < N; i++) cout << i << " \n"[i == N - 1];
        for (int i = 0; i < Q; i++) {
            long long k = (long long)(i + 1) * N / Q;
            if (k < 1) k = 1;
            if (k > N) k = N;
            cout << 1 << " " << k << "\n";
        }
    }
    else if (mode == 3) {
        // ---- ANTI-MO'S ALGORITHM ----
        // Permutation array. Queries alternate L between first and last blocks
        // while R jumps across the array. Maximizes pointer movement in Mo's.
        int block = max(1, (int)sqrt(N));
        cout << N << " " << Q << "\n";
        vector<int> perm(N);
        iota(perm.begin(), perm.end(), 0);
        shuffle(perm.begin(), perm.end(), rng);
        for (int i = 0; i < N; i++) cout << perm[i] << " \n"[i == N - 1];
        for (int i = 0; i < Q; i++) {
            int l, r;
            if (i % 2 == 0) {
                // L in the first block, R anywhere to the right
                l = rng() % block + 1;
                r = l + rng() % (N - l + 1);
                r = min(r, N);
            } else {
                // L near the end, R at the very end
                l = N - block + rng() % block;
                l = max(l, 1);
                r = N;
            }
            if (l > r) swap(l, r);
            cout << l << " " << r << "\n";
        }
    }
    else if (mode == 4) {
        // ---- ALL FULL-RANGE QUERIES ----
        // Permutation of [0..N-1], every query is [1, N].
        // MEX = N for every query. Stresses solutions that don't cache.
        cout << N << " " << Q << "\n";
        vector<int> perm(N);
        iota(perm.begin(), perm.end(), 0);
        shuffle(perm.begin(), perm.end(), rng);
        for (int i = 0; i < N; i++) cout << perm[i] << " \n"[i == N - 1];
        for (int i = 0; i < Q; i++) {
            cout << 1 << " " << N << "\n";
        }
    }
    else if (mode == 5) {
        // ---- REPEATING BLOCKS + SPANNING QUERIES ----
        // Array = repeating [0, 1, 2, ..., B-1] where B = sqrt(N).
        // Any query spanning >= B consecutive elements has MEX = B.
        // Queries are designed to span multiple blocks with random offsets.
        // This stresses MEX computations with moderate-high MEX values
        // and forces maximum segment tree / pointer updates.
        int B = max(1, (int)sqrt(N));
        cout << N << " " << Q << "\n";
        for (int i = 0; i < N; i++) cout << (i % B) << " \n"[i == N - 1];
        for (int i = 0; i < Q; i++) {
            int l = rng() % (N - B) + 1;
            int len = B + rng() % (N - l - B + 2);
            int r = min(l + len - 1, N);
            if (l > r) swap(l, r);
            cout << l << " " << r << "\n";
        }
    }

    return 0;
}
