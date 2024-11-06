#include "headers.h"

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // sieve();
    // get_divisors();
    // sieve_phi();

    // cout << count_divisor(24) << "\n";
    
    // vector <int> d = get_factors(24);

    // for (auto it : d) {
    //     cout << it << " ";
    // }

    // cout << binary_exponentiation(15879, 123);

    for (int i = 1; i <= 10; i++) {
        cout << phi(i) << "\n";
    }

    return 0;
}