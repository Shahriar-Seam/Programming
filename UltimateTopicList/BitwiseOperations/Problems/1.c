#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void calculate_the_maximum(int n, int k) {
    int m_and, m_or, m_xor;
    int a, o, x;
    int i, j;

    m_and = m_or = m_xor = 0;

    for (i = 1; i <= n; i++) {
        for (j = i + 1; j <= n; j++) {
            a = i & j;
            o = i | j;
            x = i ^ j;

            if (a > m_and && a < k) {
                m_and = a;
            }
            if (o > m_or && o < k) {
                m_or = o;
            }
            if (x > m_xor && x < k) {
                m_xor = x;
            }
        }
    }

    printf("%d\n%d\n%d", m_and, m_or, m_xor);
}

int main() {
    int n, k;
  
    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);
 
    return 0;
}
