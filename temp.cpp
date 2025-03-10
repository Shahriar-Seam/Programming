#include <bits/stdc++.h>
using namespace  std;
 
#define ll long long

const int N=1e7;
bitset<N+1> is_prime;
vector<int> primes;

void set_sieve(int n) {

    is_prime.set();
    is_prime[0]=is_prime[1]=0;

    for(int i = 2; i*i <= n; i++) {
        if(is_prime[i]) {
           // primes.push_back(i);
            for(ll j = 1LL * i * i; j <= n; j += i ) {
                is_prime[j] = 0;
            }
        }
    }


}

void set_prime_vec() {
    for(int i = 2; i <= N; i++){
        if(is_prime[i]) primes.push_back(i);
    }
}

void factorize(int n) {
    if(n == 1) cout << 1;
    else{
        cout << 1 << " x ";
        for(int x: primes) {
            if(x * x > n) break;
            while(n % x == 0) {
                cout << x;
                n /= x;
                if(n != 1) cout << " x " ;
            }
        }
        if(n > 1) cout << n;
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  

    set_sieve(N);
    set_prime_vec();
 
    // int n;

    // while(cin >> n){

    //     factorize(n);
    //     cout << '\n';
    
    // }

    cout << primes.size();
    
}