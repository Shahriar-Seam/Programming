#include <bits/stdc++.h>

using namespace std;

#define sz int(1e6 + 5)
vector <bool> marked(sz, true);
vector <int> primes;
vector <vector <int> > factors(sz);
vector <pair <int, int> > counter(sz);

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

void fill_factors()
{
    int i, j;

    for (i = 0; primes[i] * primes[i] < sz; i++) {
        for (j = primes[i]; j < sz; j += primes[i]) {
            factors[j].push_back(primes[i]);
        }
    }
}

void fill_counter(vector <int> &v)
{
    int i;

    for (i = 0; i < counter.size(); i++) {
        counter[i].first = 0;
        counter[i].second = -i;
    }

    counter[0].second = counter[1].second = -2;

    for (i = 0; i < v.size(); i++) {
        for (auto it : factors[v[i]]) {
            counter[it].first++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();
    fill_factors();

    int n, i, f_max = 0, s_max = 0;

    cin >> n;

    vector <int> v(n), temp;

    for (auto &it : v) {
        cin >> it;
    }
    
    fill_counter(v);

    sort(counter.begin(), counter.end(), greater <pair <int, int> > ());

    int a = -(counter[0].second);

    for (i = 0; i < n; i++) {
        if (v[i] % a != 0) {
            temp.push_back(v[i]);
        }
    }

    v = temp;
    temp.clear();

    counter.assign(sz, {});

    fill_counter(v);

    sort(counter.begin(), counter.end(), greater <pair <int, int> > ());

    int b = max(2, -counter[0].second);

    for (i = 0; i < v.size(); i++) {
        if (v[i] % b != 0) {
            temp.push_back(v[i]);
        }
    }

    cout << temp.size() << "\n";
    cout << a << " " << b << "\n";

    return 0;
}