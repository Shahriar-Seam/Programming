#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, x, i, temp, count = 0;
    long long prefix = 0; // Prefix sum
    map <long long, long long> prefixCount; // Store the count of prefixes before that index

    cin >> n >> x;

    prefixCount[0] = 1; // empty prefix

    for (i = 0; i < n; i++) {
        cin >> temp;

        prefix += temp;

        count += prefixCount[prefix - x];

        prefixCount[prefix]++;
    }

    cout << count;

    return 0;
}