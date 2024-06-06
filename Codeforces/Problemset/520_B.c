#include <stdio.h>

int main() {
    int n, m, count = 0;
    
    scanf("%d %d", &n, &m);
    
    while (1) {
        if (n == m) {
            break;
        }
        if ((m > n) && (m % 2 == 0)) {
            m /= 2;
            count++;
        }
        else {
            m++;
            count++;
        }
    }
    
    printf("%d", count);

    return 0;
}