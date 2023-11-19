#include <stdio.h>
#include <string.h>

int main()
{
    char str1[100], str2[100], str3[102];
    int i, len1, len2, temp, carry = 0;

    printf("Enter the first number: ");
    fgets(str1, sizeof(str1), stdin);
    printf("Enter the second number: ");
    fgets(str2, sizeof(str2), stdin);

    // Removing trailing newline characters
    len1 = strlen(str1);
    if (str1[len1 - 1] == '\n') {
        str1[len1 - 1] = '\0';
    }

    len2 = strlen(str2);
    if (str2[len2 - 1] == '\n') {
        str2[len2 - 1] = '\0';
    }

    // Determine the maximum length
    int maxLength = (len1 > len2) ? len1 : len2;

    memset(str3, '0', sizeof(str3));

    for (i = maxLength - 1; i >= 0; i--) {
        // Get the digits from both numbers (if available)
        int digit1 = (i >= len1) ? 0 : (str1[i] - '0');
        int digit2 = (i >= len2) ? 0 : (str2[i] - '0');

        temp = digit1 + digit2 + carry;
        carry = temp / 10;
        str3[i + 1] = (temp % 10) + '0';
    }

    str3[0] = carry + '0';
    str3[maxLength + 1] = '\0';

    printf("Sum: %s\n", str3);

    return 0;
}
