/*
 * Bit-parallel LCS for arrays of 16-bit unsigned integers (Hyyro algorithm).
 *
 * For char-based LCS, PM[256][WORDS] is fine (~1.6MB).
 * For 16-bit integers, PM[65536][WORDS] would be ~410MB — far too large.
 *
 * Solution: only allocate PM rows for distinct values that appear in b.
 *   - val_to_idx[65536] maps each value to a compact index (or -1).
 *   - PM is dynamically allocated with only num_distinct rows.
 *   - Worst case: min(n, 65536) distinct values.
 *
 * Input:  m n
 *         a[0] a[1] ... a[m-1]
 *         b[0] b[1] ... b[n-1]
 * Output: LCS length
 */
#pragma GCC optimize("O3,unroll-loops,inline")
#pragma GCC target("popcnt")
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MAXN 50001
#define WORDS ((MAXN + 63) >> 6)

typedef uint64_t u64;

static unsigned short a_arr[MAXN], b_arr[MAXN];
static int val_to_idx[65536];      /* value → compact PM row index, -1 if absent */
static u64 zero_row[WORDS];        /* all-zero row for values not in b */

int main(void) {
    int m, n;
    scanf("%d %d", &m, &n);

    for (int i = 0; i < m; i++) scanf("%hu", &a_arr[i]);
    for (int j = 0; j < n; j++) scanf("%hu", &b_arr[j]);

    int nw = (n + 63) >> 6;

    /* Map distinct values in b to compact indices */
    memset(val_to_idx, -1, sizeof(val_to_idx));
    int num_distinct = 0;
    for (int j = 0; j < n; j++) {
        if (val_to_idx[b_arr[j]] == -1) {
            val_to_idx[b_arr[j]] = num_distinct++;
        }
    }

    /* Allocate PM: only num_distinct rows × nw words */
    u64 *PM = (u64 *)calloc((size_t)num_distinct * nw, sizeof(u64));

    /* Build PM: PM[idx][w] has bit j set iff b[j] has that value */
    for (int j = 0; j < n; j++) {
        int idx = val_to_idx[b_arr[j]];
        PM[(size_t)idx * nw + (j >> 6)] |= 1ULL << (j & 63);
    }

    /* Mask for the last word */
    u64 lastmask = (n & 63) ? (1ULL << (n & 63)) - 1 : ~0ULL;

    /* DP row bitvector */
    u64 *row = (u64 *)calloc(nw, sizeof(u64));

    /* Process each element of a */
    for (int i = 0; i < m; i++) {
        int idx = val_to_idx[a_arr[i]];
        const u64 *pm = (idx >= 0) ? &PM[(size_t)idx * nw] : zero_row;

        u64 prev_high = 1;
        u64 borrow = 0;

        for (int k = 0; k < nw; k++) {
            u64 x = row[k] | pm[k];

            u64 y = (row[k] << 1) | prev_high;
            prev_high = row[k] >> 63;

            u64 t1 = x - y;
            u64 b1 = x < y;
            u64 t2 = t1 - borrow;
            u64 b2 = t1 < borrow;
            borrow = b1 | b2;

            row[k] = x & (x ^ t2);
        }

        row[nw - 1] &= lastmask;
    }

    /* LCS length = popcount(row) */
    int ans = 0;
    for (int k = 0; k < nw; k++)
        ans += __builtin_popcountll(row[k]);

    printf("%d\n", ans);

    free(PM);
    free(row);
    return 0;
}
