# LCS Integer Benchmark Summary

## NiCad-Style DP vs Bit-Parallel (Hyyro) — 16-bit Unsigned Integer Arrays

**Tests per suite:** 100  
**Max array length:** 50,000  
**Compiler:** GCC with `-O2`, bit-parallel with `-mpopcnt`  

---

## Small Numbers (0–100)

**Correctness:** 100/100  

### Timing

| Metric | NiCad-DP | Bit-Parallel |
|---|---:|---:|
| **Total time** | 63.535s | 1.931s |
| **Mean time** | 0.635353s | 0.019308s |
| **Median time** | 0.056192s | 0.006752s |
| **Max time** | 3.591562s | 0.085833s |
| **Min time** | 0.003759s | 0.003832s |
| **Std dev** | 0.998708s | 0.022819s |

### Speedup

- **Mean:** 17.05×
- **Median:** 8.48×
- **Max:** 43.78×

### By Input Size

| Bucket | Count | Avg NiCad | Avg BitPar | Avg Speedup |
|---|---:|---:|---:|---:|
| Tiny (≤100) | 10 | 0.0044s | 0.0041s | **1.08×** |
| Small (≤1K) | 20 | 0.0049s | 0.0043s | **1.14×** |
| Medium (≤10K) | 30 | 0.0483s | 0.0065s | **7.09×** |
| Large (≤40K) | 30 | 1.0090s | 0.0279s | **34.91×** |
| Max (≤50K) | 10 | 3.1673s | 0.0770s | **41.16×** |

---

## Sparse Numbers (0–65535)

**Correctness:** 100/100  

### Timing

| Metric | NiCad-DP | Bit-Parallel |
|---|---:|---:|
| **Total time** | 61.295s | 4.477s |
| **Mean time** | 0.612949s | 0.044771s |
| **Median time** | 0.055134s | 0.008125s |
| **Max time** | 3.520874s | 0.277624s |
| **Min time** | 0.003807s | 0.003703s |
| **Std dev** | 0.979141s | 0.071448s |

### Speedup

- **Mean:** 8.50×
- **Median:** 6.92×
- **Max:** 21.53×

### By Input Size

| Bucket | Count | Avg NiCad | Avg BitPar | Avg Speedup |
|---|---:|---:|---:|---:|
| Tiny (≤100) | 10 | 0.0043s | 0.0042s | **1.03×** |
| Small (≤1K) | 20 | 0.0047s | 0.0042s | **1.12×** |
| Medium (≤10K) | 30 | 0.0517s | 0.0077s | **6.05×** |
| Large (≤40K) | 30 | 0.9391s | 0.0585s | **16.73×** |
| Max (≤50K) | 10 | 3.1433s | 0.2367s | **13.35×** |

---

## Memory Comparison

| | NiCad-DP | Bit-Parallel (small) | Bit-Parallel (sparse) |
|---|---:|---:|---:|
| **Static memory** | 585.9 KB | 1074.5 KB | 305926.2 KB |

### Breakdown

**NiCad-DP:**
- `dp[2][50001]` of `uint32` = 400,008 bytes
- `a[50001] + b[50001]` of `uint16` = 200,004 bytes
- **Total: ~585.9 KB**

**Bit-Parallel (dynamically allocated PM):**
- Small numbers: ~101 distinct → PM = 617.0 KB
- Sparse numbers: up to ~50000 distinct → PM = 298.3 MB
- `val_to_idx[65536]` = 256 KB (always)
- `row[782]` = 6.1 KB

> The bit-parallel approach dynamically allocates PM only for distinct values in b, avoiding the 410 MB static allocation that `PM[65536][WORDS]` would require.

---

## Key Observations

1. **Small numbers** (range 0–100): High collision rate → longer LCS. Both algorithms do the same work per cell, but bit-parallel packs 64 into one word.
2. **Sparse numbers** (range 0–65535): Low collision rate → shorter LCS, more distinct PM rows. Bit-parallel uses more memory for PM but computation time is similar per cell.
3. The **speedup is consistent** across both modes because it depends on input *size*, not value range.
