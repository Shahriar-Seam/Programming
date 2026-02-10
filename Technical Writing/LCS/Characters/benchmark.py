"""
LCS Benchmark: NiCad-style DP vs Bit-Parallel (Hyyro)
Runs 100 test cases with varying string lengths, measures time & memory,
verifies correctness, saves data, and plots results.
"""

import subprocess
import os
import random
import string
import time
import csv
import sys
import statistics

# ── Configuration ──────────────────────────────────────────────────────
DIR = os.path.dirname(os.path.abspath(__file__))
GCC = "gcc"

NICAD_SRC   = os.path.join(DIR, "LCS0-nicad.c")
BITPAR_SRC  = os.path.join(DIR, "LCS0_optimized.c")
NICAD_EXE   = os.path.join(DIR, "bench_nicad.exe")
BITPAR_EXE  = os.path.join(DIR, "bench_bitpar.exe")
CSV_FILE    = os.path.join(DIR, "benchmark_results.csv")
PLOT_FILE   = os.path.join(DIR, "benchmark_plot.png")
SUMMARY_FILE = os.path.join(DIR, "benchmark_summary.md")

NUM_TESTS   = 100
MAX_LEN     = 50000        # max supported by nicad (MAXN=50001, unsigned short)
ALPHABET    = "abcd"       # small alphabet → longer LCS → stresses both algorithms
TIMEOUT_SEC = 300          # 5 min timeout per run

# Nicad DP space: 2 * n * 2 bytes (unsigned short) + 2*50001 chars
# Bitpar space : 256*ceil(n/64)*8 + ceil(n/64)*8 + 2*50001 chars
# We also estimate static/BSS from the C source constants.

def estimate_memory_nicad(n):
    """Estimated working memory in bytes for nicad (static arrays)."""
    dp = 2 * 50001 * 2          # dp[2][MAXN] of unsigned short
    strings = 2 * 50001         # a[MAXN], b[MAXN]
    return dp + strings

def estimate_memory_bitpar(n):
    """Estimated working memory in bytes for bitpar (static arrays)."""
    words = (50001 + 63) // 64
    pm  = 256 * words * 8       # PM[256][WORDS] of u64
    row = words * 8             # row[WORDS] of u64
    strings = 2 * 50001         # a[MAXN], b[MAXN]
    return pm + row + strings

# ── Helpers ────────────────────────────────────────────────────────────

def compile_file(src, exe, extra_flags=None):
    cmd = [GCC, "-O2", "-o", exe, src]
    if extra_flags:
        cmd[1:1] = extra_flags
    print(f"  Compiling: {' '.join(cmd)}")
    r = subprocess.run(cmd, capture_output=True, text=True)
    if r.returncode != 0:
        print(f"  COMPILE ERROR:\n{r.stderr}")
        sys.exit(1)
    print(f"  → {os.path.basename(exe)} OK")

def generate_test(length_a, length_b):
    a = ''.join(random.choices(ALPHABET, k=length_a))
    b = ''.join(random.choices(ALPHABET, k=length_b))
    return a, b

def run_exe(exe, input_data):
    """Run executable, return (output_string, elapsed_seconds)."""
    t0 = time.perf_counter()
    r = subprocess.run(
        [exe],
        input=input_data,
        capture_output=True,
        text=True,
        timeout=TIMEOUT_SEC,
    )
    elapsed = time.perf_counter() - t0
    if r.returncode != 0:
        return None, elapsed
    return r.stdout.strip(), elapsed

def make_length_schedule(num_tests, max_len):
    """Generate a spread of test sizes: small, medium, large."""
    lengths = []
    # 10 tiny (10-100), 20 small (100-1000), 30 medium (1000-10000),
    # 30 large (10000-40000), 10 max (40000-50000)
    buckets = [
        (10,   10,    100),
        (20,  100,   1000),
        (30, 1000,  10000),
        (30, 10000, 40000),
        (10, 40000, max_len),
    ]
    for count, lo, hi in buckets:
        for _ in range(count):
            la = random.randint(lo, hi)
            lb = random.randint(lo, hi)
            lengths.append((la, lb))
    random.shuffle(lengths)
    return lengths

# ── Main ───────────────────────────────────────────────────────────────

def main():
    print("=" * 70)
    print("  LCS BENCHMARK: NiCad-DP  vs  Bit-Parallel (Hyyro)")
    print("=" * 70)

    # 1. Compile
    print("\n[1/4] Compiling ...")
    compile_file(NICAD_SRC, NICAD_EXE)
    compile_file(BITPAR_SRC, BITPAR_EXE, ["-mpopcnt"])
    print()

    # 2. Generate schedule & run
    print(f"[2/4] Running {NUM_TESTS} tests (max length {MAX_LEN}) ...")
    schedule = make_length_schedule(NUM_TESTS, MAX_LEN)

    rows = []   # for CSV
    mismatches = 0

    for idx, (la, lb) in enumerate(schedule):
        pct = (idx + 1) / NUM_TESTS * 100
        print(f"\r  Test {idx+1:3d}/{NUM_TESTS}  len=({la:5d},{lb:5d})  [{pct:5.1f}%]", end="", flush=True)

        a, b = generate_test(la, lb)
        inp = f"{a} {b}\n"

        # Run nicad
        out_n, t_n = run_exe(NICAD_EXE, inp)
        # Run bitpar
        out_b, t_b = run_exe(BITPAR_EXE, inp)

        # Correctness check
        match = (out_n == out_b) if (out_n is not None and out_b is not None) else False
        if not match:
            mismatches += 1

        lcs_len = int(out_n) if out_n else -1
        product = la * lb

        rows.append({
            "test":        idx + 1,
            "len_a":       la,
            "len_b":       lb,
            "product":     product,
            "lcs_length":  lcs_len,
            "time_nicad":  round(t_n, 6),
            "time_bitpar": round(t_b, 6),
            "speedup":     round(t_n / t_b, 2) if t_b > 0 else 0,
            "match":       match,
            "mem_nicad":   estimate_memory_nicad(max(la, lb)),
            "mem_bitpar":  estimate_memory_bitpar(max(la, lb)),
        })

    print("\n  Done.\n")

    # 3. Save CSV
    print(f"[3/4] Saving data to {os.path.basename(CSV_FILE)} ...")
    fieldnames = list(rows[0].keys())
    with open(CSV_FILE, "w", newline="") as f:
        w = csv.DictWriter(f, fieldnames=fieldnames)
        w.writeheader()
        w.writerows(rows)
    print(f"  → {len(rows)} rows written.\n")

    # 4. Summary statistics
    print("[4/4] Summary")
    print("=" * 70)

    t_nicad  = [r["time_nicad"]  for r in rows]
    t_bitpar = [r["time_bitpar"] for r in rows]
    speedups = [r["speedup"]     for r in rows]
    products = [r["product"]     for r in rows]

    # Overall
    print(f"  Total tests          : {NUM_TESTS}")
    print(f"  Correctness matches  : {NUM_TESTS - mismatches}/{NUM_TESTS}")
    print(f"  Alphabet             : '{ALPHABET}' ({len(ALPHABET)} chars)")
    print()
    print(f"  {'':30s} {'NiCad-DP':>12s}  {'Bit-Parallel':>12s}")
    print(f"  {'─'*30} {'─'*12}  {'─'*12}")
    print(f"  {'Total time (s)':30s} {sum(t_nicad):12.3f}  {sum(t_bitpar):12.3f}")
    print(f"  {'Mean time (s)':30s} {statistics.mean(t_nicad):12.6f}  {statistics.mean(t_bitpar):12.6f}")
    print(f"  {'Median time (s)':30s} {statistics.median(t_nicad):12.6f}  {statistics.median(t_bitpar):12.6f}")
    print(f"  {'Max time (s)':30s} {max(t_nicad):12.6f}  {max(t_bitpar):12.6f}")
    print(f"  {'Min time (s)':30s} {min(t_nicad):12.6f}  {min(t_bitpar):12.6f}")
    print(f"  {'Std dev (s)':30s} {statistics.stdev(t_nicad):12.6f}  {statistics.stdev(t_bitpar):12.6f}")
    print()
    print(f"  {'Mean speedup (×)':30s} {statistics.mean(speedups):12.2f}")
    print(f"  {'Median speedup (×)':30s} {statistics.median(speedups):12.2f}")
    print(f"  {'Max speedup (×)':30s} {max(speedups):12.2f}")
    print()

    # Static memory estimate
    mem_n = estimate_memory_nicad(MAX_LEN)
    mem_b = estimate_memory_bitpar(MAX_LEN)
    print(f"  {'Static memory (nicad)':30s} {mem_n:>10,d} bytes  ({mem_n/1024/1024:.2f} MB)")
    print(f"  {'Static memory (bitpar)':30s} {mem_b:>10,d} bytes  ({mem_b/1024/1024:.2f} MB)")
    print(f"  {'Memory ratio (bitpar/nicad)':30s} {mem_b/mem_n:.2f}×")
    print()

    # By size bucket
    buckets_def = [
        ("Tiny   (≤100)",       0,       100*100),
        ("Small  (≤1K)",        100*100, 1000*1000),
        ("Medium (≤10K)",       1e6,     1e8),
        ("Large  (≤40K)",       1e8,     40000*40000),
        ("Max    (≤50K)",       40000*40000, float("inf")),
    ]
    print(f"  {'Bucket':22s} {'Count':>5s}  {'Avg Nicad':>10s}  {'Avg BitPar':>10s}  {'Avg Speedup':>11s}")
    print(f"  {'─'*22} {'─'*5}  {'─'*10}  {'─'*10}  {'─'*11}")
    for bname, lo, hi in buckets_def:
        br = [r for r in rows if lo < r["product"] <= hi]
        if not br:
            br = [r for r in rows if lo <= r["product"] <= hi]
        if br:
            avg_n = statistics.mean([r["time_nicad"] for r in br])
            avg_b = statistics.mean([r["time_bitpar"] for r in br])
            avg_s = statistics.mean([r["speedup"] for r in br])
            print(f"  {bname:22s} {len(br):5d}  {avg_n:10.4f}s  {avg_b:10.4f}s  {avg_s:10.2f}×")
    print()

    # Save summary to markdown file
    with open(SUMMARY_FILE, "w", encoding="utf-8") as f:
        f.write("# LCS Benchmark Summary\n\n")
        f.write("## NiCad-Style DP vs Bit-Parallel (Hyyro) Algorithm\n\n")
        f.write(f"**Tests:** {NUM_TESTS}  \n")
        f.write(f"**Max string length:** {MAX_LEN:,}  \n")
        f.write(f"**Alphabet:** `{ALPHABET}` ({len(ALPHABET)} chars)  \n")
        f.write(f"**Correctness:** {NUM_TESTS - mismatches}/{NUM_TESTS}\n\n")
        f.write("---\n\n## Timing Summary\n\n")
        f.write("| Metric | NiCad-DP | Bit-Parallel |\n|---|---:|---:|\n")
        f.write(f"| **Total time** | {sum(t_nicad):.3f}s | {sum(t_bitpar):.3f}s |\n")
        f.write(f"| **Mean time** | {statistics.mean(t_nicad):.6f}s | {statistics.mean(t_bitpar):.6f}s |\n")
        f.write(f"| **Median time** | {statistics.median(t_nicad):.6f}s | {statistics.median(t_bitpar):.6f}s |\n")
        f.write(f"| **Max time** | {max(t_nicad):.6f}s | {max(t_bitpar):.6f}s |\n")
        f.write(f"| **Min time** | {min(t_nicad):.6f}s | {min(t_bitpar):.6f}s |\n")
        f.write(f"| **Std dev** | {statistics.stdev(t_nicad):.6f}s | {statistics.stdev(t_bitpar):.6f}s |\n\n")
        f.write("---\n\n## Speedup\n\n")
        f.write(f"- **Mean speedup:** {statistics.mean(speedups):.2f}x\n")
        f.write(f"- **Median speedup:** {statistics.median(speedups):.2f}x\n")
        f.write(f"- **Max speedup:** {max(speedups):.2f}x\n\n")
        f.write("---\n\n## Memory\n\n")
        f.write(f"| | NiCad-DP | Bit-Parallel |\n|---|---:|---:|\n")
        f.write(f"| **Static memory** | {mem_n/1024:.1f} KB | {mem_b/1024:.1f} KB |\n")
        f.write(f"| **Ratio** | 1x | {mem_b/mem_n:.2f}x |\n")

    # 5. Plot
    try:
        import matplotlib
        matplotlib.use("Agg")
        import matplotlib.pyplot as plt
        import numpy as np

        fig, axes = plt.subplots(2, 2, figsize=(14, 10))
        fig.suptitle("LCS Benchmark: NiCad-DP vs Bit-Parallel (Hyyro)", fontsize=14, fontweight="bold")

        prods = [r["product"] for r in rows]

        # (0,0) Time vs input size
        ax = axes[0][0]
        ax.scatter(prods, t_nicad,  s=12, alpha=0.7, label="NiCad-DP", color="tomato")
        ax.scatter(prods, t_bitpar, s=12, alpha=0.7, label="Bit-Parallel", color="steelblue")
        ax.set_xlabel("Input size (m × n)")
        ax.set_ylabel("Time (seconds)")
        ax.set_title("Execution Time vs Input Size")
        ax.legend()
        ax.set_xscale("log")
        ax.set_yscale("log")
        ax.grid(True, alpha=0.3)

        # (0,1) Speedup vs input size
        ax = axes[0][1]
        ax.scatter(prods, speedups, s=12, alpha=0.7, color="forestgreen")
        ax.axhline(y=statistics.mean(speedups), color="red", linestyle="--", label=f"Mean: {statistics.mean(speedups):.1f}×")
        ax.set_xlabel("Input size (m × n)")
        ax.set_ylabel("Speedup (×)")
        ax.set_title("Speedup (NiCad / BitParallel)")
        ax.legend()
        ax.set_xscale("log")
        ax.grid(True, alpha=0.3)

        # (1,0) Time distribution (box plot style with histogram)
        ax = axes[1][0]
        # Only large tests for meaningful comparison
        large = [r for r in rows if r["product"] > 1e8]
        if large:
            tn_large = [r["time_nicad"] for r in large]
            tb_large = [r["time_bitpar"] for r in large]
            bp = ax.boxplot([tn_large, tb_large], tick_labels=["NiCad-DP", "Bit-Parallel"],
                       patch_artist=True)
            colors = ["tomato", "steelblue"]
            for patch, color in zip(bp["boxes"], colors):
                patch.set_facecolor(color)
                patch.set_alpha(0.5)
            ax.set_ylabel("Time (seconds)")
            ax.set_title(f"Time Distribution (large tests, n>10K, count={len(large)})")
        else:
            ax.text(0.5, 0.5, "No large tests", ha="center", va="center", transform=ax.transAxes)
        ax.grid(True, alpha=0.3)

        # (1,1) Memory comparison (bar chart)
        ax = axes[1][1]
        labels = ["NiCad-DP", "Bit-Parallel"]
        mem_vals = [mem_n / 1024, mem_b / 1024]
        colors = ["tomato", "steelblue"]
        bars = ax.bar(labels, mem_vals, color=colors, alpha=0.7, edgecolor="black")
        ax.set_ylabel("Static Memory (KB)")
        ax.set_title("Static Memory Usage (at MAXN=50001)")
        for bar, val in zip(bars, mem_vals):
            ax.text(bar.get_x() + bar.get_width()/2, bar.get_height() + 5,
                    f"{val:.0f} KB", ha="center", va="bottom", fontweight="bold")
        ax.grid(True, alpha=0.3, axis="y")

        plt.tight_layout()
        plt.savefig(PLOT_FILE, dpi=150)
        print(f"  Plot saved to {os.path.basename(PLOT_FILE)}")
    except ImportError:
        print("  (matplotlib not available — skipping plot)")

    print()
    print("=" * 70)
    print("  DONE. All data in benchmark_results.csv")
    print("=" * 70)


if __name__ == "__main__":
    main()
