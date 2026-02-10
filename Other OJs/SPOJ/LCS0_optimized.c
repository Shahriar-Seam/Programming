/*
 * Bit-parallel LCS length (Allison-Dill / Hyyro algorithm)
 * Time:  O(m * n/64)
 * Space: O(256 * n/64)
 * ~64x faster than standard DP for large inputs.
 */
#pragma GCC optimize("O3,unroll-loops,inline")
#pragma GCC target("popcnt")
#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define MAXN 50001
#define WORDS ((MAXN + 63) >> 6)

typedef uint64_t u64;

static char a[MAXN], b[MAXN];
static u64 PM[256][WORDS];   /* pattern-match bitvectors */
static u64 row[WORDS];       /* current DP-row difference bitvector */

int main(void) {
    scanf("%s %s", a, b);

    int m = (int)strlen(a);
    int n = (int)strlen(b);
    int nw = (n + 63) >> 6;

    /* Build PM: PM[c][w] has bit j set iff b[j] == c */
    for (int j = 0; j < n; j++)
        PM[(unsigned char)b[j]][j >> 6] |= 1ULL << (j & 63);

    /* Mask out unused bits in the last word */
    u64 lastmask = (n & 63) ? (1ULL << (n & 63)) - 1 : ~0ULL;

    /* Process each character of a */
    for (int i = 0; i < m; i++) {
        const u64 *pm = PM[(unsigned char)a[i]];
        u64 prev_high = 1; /* provides the |1 for first word, then carries */
        u64 borrow = 0;

        for (int k = 0; k < nw; k++) {
            u64 x = row[k] | pm[k];

            /* Y = (row << 1) | carry_in */
            u64 y = (row[k] << 1) | prev_high;
            prev_high = row[k] >> 63;

            /* Multi-word subtraction: diff = x - y - borrow */
            u64 t1 = x - y;
            u64 b1 = x < y;
            u64 t2 = t1 - borrow;
            u64 b2 = t1 < borrow;
            borrow = b1 | b2;

            /* row = X & (X ^ (X - Y)) */
            row[k] = x & (x ^ t2);
        }

        /* Keep only valid bits in the last word */
        row[nw - 1] &= lastmask;
    }

    /* LCS length = popcount(row) */
    int ans = 0;
    for (int k = 0; k < nw; k++)
        ans += __builtin_popcountll(row[k]);

    printf("%d\n", ans);
    return 0;
}
