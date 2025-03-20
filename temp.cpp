#include <bits/stdc++.h>
using namespace std;

const int sz = 1e9 + 5;
vector <bool> marked(sz, true);
vector <int> primes;

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

int main() {
  clock_t start, end; // To store clock ticks, clock tick is the smallest unit of time that can be measured by the clock
  start = clock(); // Start the clock
  
    sieve();

  end = clock(); // End the clock
  double time_taken = (double)(end - start) / CLOCKS_PER_SEC; // Calculate the time taken, CLOCKS_PER_SEC is the number of clock ticks per second
  cout << "Time taken by program is : " << fixed << setprecision(5) << time_taken << " sec" << endl;
  return 0;
}
