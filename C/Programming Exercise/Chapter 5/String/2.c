#include <stdio.h>
#include <string.h>

int main()
{
    char n1[60], n2[60], sum[60];
    int n1_len, n2_len, max_len, i;

    // Get the numbers
    gets(n1);
    n1_len = strlen(n1);

    gets(n2);
    n2_len = strlen(n2);

    // Find and assign maximum length
    if (n1_len > n2_len) {
        max_len = n1_len;
    }
    else {
        max_len = n2_len;
    }

    // Change ASCII value to integer digit
    for (i = 0; i < n1_len; i++) {
        n1[i] = n1[i] - '0';
    }
    for (i = 0; i < n2_len; i++) {
        n2[i] = n2[i] - '0';
    }

    // Rotate the number
    for (i = 0; i < n1_len / 2; i++) {
        char c = n1[i];
        n1[i] = n1[n1_len - i - 1];
        n1[n1_len - i - 1] = c;
    }
    // Use 0 to make both numbers of even length
    for (i = n1_len; i < max_len; i++) {
        n1[i] = 0;
    }
    n1[i] = '\0';

    // Rotate the number
    for (i = 0; i < n2_len / 2; i++) {
        char c = n2[i];
        n2[i] = n2[n2_len - i - 1];
        n2[n2_len - i - 1] = c;
    }
    // Use 0 to make both numbers of even length
    for (i = n2_len; i < max_len; i++) {
        n2[i] = 0;
    }
    n2[i] = '\0';

    int carry = 0;

    // Find sum
    for (i = 0; i < max_len; i++) {
        int s = carry + n1[i] + n2[i];
        sum[i] = s % 10 + '0';
        carry = s / 10;
    }
    // Check if sum needs to be lengthier
    if (carry) {
        sum[i] = carry + '0';
        i++;
        max_len++;
    }
    sum[i] = '\0';

    // Rotate sum
    for (i = 0; i < max_len / 2;i++) {
        char c = sum[i];
        sum[i] = sum[max_len - i - 1];
        sum[max_len - i - 1] = c;
    }

    printf("%s\n", sum);

    return 0;
}