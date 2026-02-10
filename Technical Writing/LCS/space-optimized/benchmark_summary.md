# LCS Space-Optimized DP Benchmark Summary

## 2-Row DP vs Single-Array (1-Row) DP — 16-bit Unsigned Integer Arrays

**Tests per suite:** 100  
**Max array length:** 50,000  
**Compiler:** GCC with `-O2`  
**Optimization pragma:** `O3,unroll-loops,inline`  

---

## Small Numbers (0–100)

**Correctness:** 100/100  

### Timing

| Metric | 2-Row DP | 1-Row DP |
|---|---:|---:|
| **Total time** | 54.012s | 31.670s |
| **Mean time** | 0.540124s | 0.316697s |
| **Median time** | 0.061559s | 0.033556s |
| **Max time** | 3.022743s | 1.880004s |
| **Min time** | 0.003915s | 0.003666s |
| **Std dev** | 0.881291s | 0.526358s |

### Speedup (2-Row / 1-Row)

- **Mean:** 1.5184×
- **Median:** 1.6417×
- **Max:** 1.8602×
- **Min:** 0.9187×

> A speedup > 1 means 1-Row is faster. A speedup < 1 means 2-Row is faster.

### By Input Size

| Bucket | Count | Avg 2-Row | Avg 1-Row | Avg Speedup |
|---|---:|---:|---:|---:|
| Tiny (≤100) | 10 | 0.0042s | 0.0041s | **1.0312×** |
| Small (≤1K) | 20 | 0.0050s | 0.0044s | **1.1247×** |
| Medium (≤10K) | 30 | 0.0498s | 0.0295s | **1.6430×** |
| Large (≤40K) | 30 | 0.8081s | 0.4581s | **1.7682×** |
| Max (≤50K) | 10 | 2.8134s | 1.6911s | **1.6693×** |

---

## Sparse Numbers (0–65535)

**Correctness:** 100/100  

### Timing

| Metric | 2-Row DP | 1-Row DP |
|---|---:|---:|
| **Total time** | 61.008s | 22.258s |
| **Mean time** | 0.610081s | 0.222580s |
| **Median time** | 0.070944s | 0.026668s |
| **Max time** | 3.391917s | 1.325079s |
| **Min time** | 0.003844s | 0.003664s |
| **Std dev** | 0.941734s | 0.346659s |

### Speedup (2-Row / 1-Row)

- **Mean:** 2.1523×
- **Median:** 2.5288×
- **Max:** 2.9494×
- **Min:** 0.8283×

> A speedup > 1 means 1-Row is faster. A speedup < 1 means 2-Row is faster.

### By Input Size

| Bucket | Count | Avg 2-Row | Avg 1-Row | Avg Speedup |
|---|---:|---:|---:|---:|
| Tiny (≤100) | 10 | 0.0042s | 0.0040s | **1.0520×** |
| Small (≤1K) | 20 | 0.0048s | 0.0043s | **1.1127×** |
| Medium (≤10K) | 30 | 0.0550s | 0.0220s | **2.3574×** |
| Large (≤40K) | 30 | 0.9835s | 0.3483s | **2.8213×** |
| Max (≤50K) | 10 | 2.9717s | 1.1024s | **2.7095×** |

---

## Memory Comparison

| Component | 2-Row DP | 1-Row DP |
|---|---:|---:|
| `dp` array | 400,008 bytes (2×50001×4) | 200,004 bytes (50001×4) |
| `a` + `b` arrays | 200,004 bytes | 200,004 bytes |
| **Total** | **600,012 bytes (585.9 KB)** | **400,008 bytes (390.6 KB)** |
| **Savings** | — | **200,004 bytes (195.3 KB, 33.3%)** |

---

## Analysis

### Why might 1-Row be faster?

1. **Better cache utilization:** The 1-row approach touches half the memory of 2-row. With large `n`, the 2-row DP alternates between two rows of ~200 KB each, while the 1-row approach keeps a single ~200 KB row hot in cache.
2. **No row-index computation:** The 2-row version computes `i & 1` and `1 - bi` for every cell. The 1-row version just accesses `dp[j]` directly.
3. **Fewer array accesses:** The 2-row version indexes `dp[bi][j]` and `dp[1-bi][j]` (2D array). The 1-row version indexes `dp[j]` (1D array) with a register variable `prev`.

### Why might they be similar?

1. Both have **identical O(mn) time complexity** — same number of comparisons and assignments.
2. The compiler with `-O3` may optimize the 2D indexing into something equally efficient.
3. For small inputs, the overhead is negligible and process startup dominates.
