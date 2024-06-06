#include <bits/stdc++.h>

using namespace std;

void fast_scan(long long &number) 
{ 
    bool negative = false; 
    register int c; 
  
    number = 0; 
  
    c = getchar(); 
    if (c=='-') 
    { 
        negative = true; 
  
        c = getchar(); 
    } 
  
    for (; (c>47 && c<58); c=getchar()) 
        number = number *10 + c - 48; 

    if (negative) 
        number *= -1;
} 

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, i, num = 0;
    long long s1 = 0, s2 = 0, s3 = 0;

    cin >> n;

    for (i = 0; i < n; i++) {
        fast_scan(num);

        s1 += num;
    }
    for (i = 0; i < n - 1; i++) {
        fast_scan(num);

        s2 += num;
    }
    for (i = 0; i < n - 2; i++) {
        fast_scan(num);

        s3 += num;
    }

    cout << s1 - s2 << "\n" << s2 - s3;

    return 0;
}
