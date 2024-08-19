#include <bits/stdc++.h>

using namespace std;

vector <int> primes;
int max_size = 1000005;

void sieve()
{
    int i, j;
    bool marked[max_size] = {};

    marked[0] = marked[1] = true;

    for (i = 3; i * i <= max_size; i += 2) {
        if (marked[i] == false) {
            for (j = i * i; j <= max_size; j += i + i) {
                marked[j] = true;
            }
        }
    }

    primes.push_back(2);

    for (i = 3; i < max_size; i += 2) {
        if (marked[i] == false) {
            primes.push_back(i);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();

    int t, h, p, count;

    cin >> t;

    while (t--) {
        cin >> h;
        p = 1;
        count = 0;

        while (h > 0) {
            if (binary_search(primes.begin(), primes.end(), h) == true) {
                count++;
                h = 0;
                break;
            }
            else if (binary_search(primes.begin(), primes.end(), h - p) == true) {
                count++;
                h = h - h + p;
            }
            else {
                h -= p;
                p *= 2;
                count++;
            }
        }

        if (h == 0) {
            cout << count << "\n";
        }
        else {
            cout << "-1\n";
        }
    }

    return 0;
}