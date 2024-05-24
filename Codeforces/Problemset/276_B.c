#include <stdio.h>
#include <string.h>

int main()
{
    char s[1003];
    int i, counter[26] = {}, odd_count = 0;

    gets(s);

    for (i = 0; s[i] != '\0'; i++) {
        counter[s[i] - 'a']++;
    }

    for (i = 0; i < 26; i++) {
        odd_count += (counter[i] % 2 == 1);
    }

    puts((odd_count % 2 == 1) || (odd_count == 0) ? "First" : "Second");

    return 0;
}