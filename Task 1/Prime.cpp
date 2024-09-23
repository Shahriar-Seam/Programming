#include <bits/stdc++.h>

using namespace std;

// Global vector to store computed prime numbers
vector<int> g_primes; // Stores all prime numbers up to 1,000,000

// Function to generate prime numbers using the Sieve of Eratosthenes
// This function populates the global vector g_primes with all prime numbers
// up to a specified limit (1,000,000).
void sieve_of_eratosthenes() 
{
    const int size = 1000000; // Upper limit for generating primes
    int i, p; // Loop control variables
    vector<bool> isPrime(size + 1, true); // Boolean array to track primality

    // Mark non-prime numbers
    for (p = 3; p * p <= size; p += 2) { 
        if (isPrime[p]) { 
            for (i = p * p; i <= size; i += p + p) {
                isPrime[i] = false; // Marking multiples of p as non-prime
            }
        } 
    }

    // Add the first prime number
    g_primes.push_back(2);

    // Add odd primes to the global vector
    for (i = 3; i <= size; i += 2) {
        if (isPrime[i]) {
            g_primes.push_back(i);
        }
    }
}

// Main function to handle input/output and process test cases
int main()
{
    // Optimize input/output
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);

    int testCases, n; // Variables for number of test cases and input index

    // Generate primes before processing input
    sieve_of_eratosthenes();

    // Read the number of test cases
    cin >> testCases;

    // Process each test case
    while (testCases--) {
        cin >> n; // Read the position of the prime to output
        cout << g_primes[n - 1] << "\n"; // Output the n-th prime
    }

    return 0; // Indicate that the program ended successfully
}
