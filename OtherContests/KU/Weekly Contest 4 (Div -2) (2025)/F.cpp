#include <bits/stdc++.h>

using namespace std;

#define sz int(1e6 + 5)
vector <bool> marked(sz, true);
vector <int> primes;
vector <pair <int, int> > f_counter;
vector <int> counter(sz, 0);

void sieve()
{
    int i, j;

    for (i = 3; i * i < sz; i += 2) {
        if (marked[i]) {
            for (j = i * i; j < sz; j += 2 * i) {
                marked[j] = false;
            }
        }
    }

    primes.push_back(2);

    for (i = 3; i < sz; i += 2) {
        if (marked[i]) {
            primes.push_back(i);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();

    int n, i, j, count, max_sz = 0, a = 2, b = 3;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < n; i++) {
        for (j = 1; j * j <= v[i]; j++) {
            if (v[i] % j == 0) {
                counter[j]++;

                if (j * j < v[i]) {
                    counter[v[i] / j]++;
                }
            }
        }
    }

    for (i = 0; i < primes.size(); i++) {
        f_counter.push_back({counter[primes[i]], primes[i]});
    }

    sort(f_counter.begin(), f_counter.end(), greater <pair <int, int> > ());

    for (i = 0; i < f_counter.size(); i++) {
        if (f_counter[i].first == 0) {
            break;
        }

        for (j = i + 1; j < f_counter.size(); j++) {
            count = f_counter[i].first + f_counter[j].first;

            if (count < max_sz) {
                break;
            }

            if (1LL * f_counter[i].second * f_counter[j].second <= 1e6) {
                count -= counter[f_counter[i].second * f_counter[j].second];
            }

            if (count > max_sz) {
                max_sz = count;

                a = f_counter[i].second;
                b = f_counter[j].second;
            }
        }
    }

    cout << n - max_sz << "\n";
    cout << a << " " << b << "\n";

    return 0;
}