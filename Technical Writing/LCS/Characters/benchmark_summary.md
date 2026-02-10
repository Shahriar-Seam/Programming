# LCS Benchmark Summary

## NiCad-Style DP vs Bit-Parallel (Hyyro) Algorithm

**Date:** February 7, 2026  
**Tests:** 100  
**Max string length:** 50,000 (limited by NiCad's `MAXN = 50001` and `unsigned short`)  
**Alphabet:** `{a, b, c, d}` (4 chars — small alphabet stresses both algorithms with longer LCS)  
**Compiler:** GCC with `-O2`, bit-parallel additionally with `-mpopcnt`  
**Correctness:** ✅ **100/100** — both implementations produced identical LCS lengths on every test case.

---

## Timing Summary

| Metric | NiCad-DP | Bit-Parallel | 
|---|---:|---:|
| **Total time** | 108.351s | 1.352s |
| **Mean time** | 1.0835s | 0.0135s |
| **Median time** | 0.0569s | 0.0050s |
| **Max time** | 5.6854s | 0.0517s |
| **Min time** | 0.0038s | 0.0037s |
| **Std deviation** | 1.6410s | 0.0140s |

---

## Speedup by Input Size

| Bucket | # Tests | Avg NiCad | Avg BitParallel | Avg Speedup |
|---|---:|---:|---:|---:|
| Tiny (≤ 100) | 10 | 0.0042s | 0.0040s | **1.04×** |
| Small (≤ 1K) | 20 | 0.0045s | 0.0041s | **1.11×** |
| Medium (≤ 10K) | 30 | 0.0522s | 0.0048s | **10.17×** |
| Large (≤ 40K) | 30 | 1.8517s | 0.0204s | **88.52×** |
| Max (≤ 50K) | 10 | 5.1104s | 0.0473s | **108.06×** |

- **Mean speedup:** 40.74×  
- **Median speedup:** 11.43×  
- **Peak speedup:** 112.26×  

> At small sizes, subprocess overhead dominates so both appear similar.  
> At maximum size (50K × 50K ≈ 2.5 billion cells), the bit-parallel algorithm is **~108× faster**.

---

## Memory Usage

| | NiCad-DP | Bit-Parallel |
|---|---:|---:|
| **Static memory** | 293.0 KB | 1,667.8 KB |
| **Ratio** | 1× | 5.69× |

### Breakdown

**NiCad-DP:**
- `dp[2][50001]` of `unsigned short` = 200,004 bytes  
- `a[50001] + b[50001]` = 100,002 bytes  
- **Total: ~293 KB**

**Bit-Parallel:**
- `PM[256][782]` of `uint64_t` = 1,601,536 bytes  
- `row[782]` of `uint64_t` = 6,256 bytes  
- `a[50001] + b[50001]` = 100,002 bytes  
- **Total: ~1,668 KB**

> The bit-parallel version trades **5.7× more memory** for the `PM` bitvector table, but 1.6 MB is still very modest.

---

## Complexity Comparison

| | NiCad-DP | Bit-Parallel |
|---|---|---|
| **Time** | $O(m \times n)$ | $O(m \times \lceil n/64 \rceil)$ |
| **Space** | $O(n)$ (2-row optimization) | $O(|\Sigma| \times \lceil n/64 \rceil)$ |
| **Theoretical speedup** | — | ~64× |

---

## Key Takeaway

The Hyyro bit-parallel algorithm packs 64 DP cells into a single 64-bit word and updates them all with a few bitwise operations + one subtraction. This delivers a consistent **~100× speedup** on large inputs while using only **5.7× more memory** — an excellent tradeoff. Both algorithms produce identical, correct results.

---

## Files

| File | Description |
|---|---|
| `benchmark_results.csv` | All 100 rows of raw timing data |
| `benchmark_plot.png` | 4-panel visualization (time, speedup, distribution, memory) |
| `benchmark.py` | The benchmark script |
| `LCS0-nicad.c` | NiCad-style 2-row DP implementation |
| `LCS0_optimized.c` | Bit-parallel (Hyyro) implementation |
