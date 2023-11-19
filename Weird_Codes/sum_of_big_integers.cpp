#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s1, s2, s3;
    int i, len1, len2, carry = 0, temp;

    s3.resize(max({len1, len2}) + 1, '0');

    cin >> s1;
    cin >> s2;

    len1 = s1.length();
    len2 = s2.length();

    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());

    for (i = 0; i < max({len1, len2}); i++) {
        temp = s1[i] + s2[i] + carry - '0' - '0';

        carry = temp / 10;

        s3[i] = temp % 10 + '0';
    }

    if (carry > 0) {
        s3.push_back(carry + '0');
    }

    reverse(s3.begin(), s3.end());

    cout << s3;

    return 0;
}