#include <bits/stdc++.h>

using namespace std;

long long GCD(long long a, long long b)
{
    return b == 0 ? a : GCD(b, a % b);
}

int num_len(long long n)
{
    int len = 0;

    while (n > 0) {
        len++;

        n /= 10;
    }

    return len;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 1; ; i++) {
        long long n;

        cin >> n;

        if (n == 0) {
            break;
        }

        long long temp, sum = 0;

        for (int j = 0; j < n; j++) {
            cin >> temp;

            sum += temp;
        }

        long long g = GCD(sum < 0 ? -sum : sum, n);

        long long a, b;

        a = sum / g;
        b = n / g;

        int a_sign = 1;
        
        if (a < 0) {
            a_sign = -1;

            a *= -1;
        }

        int l_a = num_len(a);
        int l_b = num_len(b);

        cout << "Case " << i << ":\n";

        if (b == 1) {
            if (a_sign == -1) {
                cout << "- " << a << "\n";
            }
            else {
                cout << a << "\n";
            }
        }

        else {
            if (a_sign == 1) {
                if (a < b) {
                    for (int j = 0; j < l_b - l_a; j++) {
                        cout << " ";
                    }

                    cout << a << "\n";

                    for (int j = 0; j < l_b; j++) {
                        cout << "-";
                    }

                    cout << "\n" << b << "\n";
                }
                else {
                    long long c = a / b;
                    a -= b * c;

                    int l_c = num_len(c);
                    l_a = num_len(a);

                    for (int j = 0; j < l_c + l_b - l_a; j++) {
                        cout << " ";
                    }

                    cout << a << "\n";

                    cout << c;

                    for (int j = 0; j < l_b; j++) {
                        cout << "-";
                    }

                    cout << "\n";

                    for (int j = 0; j < l_c; j++) {
                        cout << " ";
                    }

                    cout << b << "\n";
                }
            }
            else {
                if (a < b) {
                    for (int j = 0; j < l_b - l_a + 2; j++) {
                        cout << " ";
                    }

                    cout << a << "\n";

                    cout << "- ";

                    for (int j = 0; j < l_b; j++) {
                        cout << "-";
                    }

                    cout << "\n  " << b << "\n";
                }
                else {
                    long long c = a / b;
                    a -= b * c;

                    int l_c = num_len(c);
                    l_a = num_len(a);

                    for (int j = 0; j < l_c + l_b - l_a + 2; j++) {
                        cout << " ";
                    }

                    cout << a << "\n";

                    cout << "- " << c;

                    for (int j = 0; j < l_b; j++) {
                        cout << "-";
                    }

                    cout << "\n  ";

                    for (int j = 0; j < l_c; j++) {
                        cout << " ";
                    }

                    cout << b << "\n";
                }
            }
        }
    }

    return 0;
}