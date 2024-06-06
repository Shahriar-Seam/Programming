#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, n;

    cin >> a >> b;

    for (n = a; n <= b; n++) {
        switch (n)
        {
        case 1:
            cout << "one" << endl;
            break;
            
        case 2:
            cout << "two" << endl;
            break;
            
        case 3:
            cout << "three" << endl;
            break;
            
        case 4:
            cout << "four" << endl;
            break;
            
        case 5:
            cout << "five" << endl;
            break;
            
        case 6:
            cout << "six" << endl;
            break;
        case 7:
            cout << "seven" << endl;
            break;
        case 8:
            cout << "eight" << endl;
            break;
            
        case 9:
            cout << "nine" << endl;
            break;
        
        default:
            if (n % 2 == 0) {
                cout << "even" << endl;
            }
            else {
                cout << "odd" << endl;
            }
            break;
        }
    }

    return 0;
}