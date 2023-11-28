#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str1, str2;

    cin >> str1 >> str2;

    cout << str1.size() << " " << str2.size() << "\n";
    cout << str1 + str2 << "\n";
    
    swap(str1[0], str2[0]);
    
    cout << str1 << " " << str2;

    return 0;
}