#include <bits/stdc++.h>

using namespace std;

#define int long long

int _sum(int n)
{
    return (n * (n + 1)) / 2;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> v(n);
    vector<int> vals(n); // A copy to hold our unique values
    
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        vals[i] = v[i];
    }

    // --- Coordinate Compression ---
    // 1. Sort the copy
    sort(vals.begin(), vals.end());
    // 2. Remove duplicates so we have a strict, ordered list of unique elements
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    // 3. Replace original large values with their compressed index (rank)
    for (int i = 0; i < n; i++) {
        v[i] = lower_bound(vals.begin(), vals.end(), v[i]) - vals.begin();
    }

    // --- Sliding Window ---
    // Now the maximum value in v is strictly less than n. 
    // We can use a lightning-fast standard vector instead of a map.
    vector<int> freq(vals.size(), 0);
    
    int l = 0, r = 0, count = 0;

    for (r = 0; r < n; r++) {
        if (freq[v[r]]) {
            count += _sum(r - l);

            while (v[l] != v[r]) {
                freq[v[l++]]--;
            }

            freq[v[l++]]--;
            count -= _sum(r - l);
        }

        freq[v[r]]++;
    }

    count += _sum(r - l);

    cout << count << "\n";

    return 0;
}