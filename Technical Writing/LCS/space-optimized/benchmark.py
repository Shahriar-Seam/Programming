"""
LCS Space-Optimized Benchmark: 2-Row DP vs Single-Array (1-Row) DP
Two test suites: small-range numbers and sparse-range numbers.
Each suite runs 100 tests with varying array lengths (max 50000).
No bit-parallel optimization — pure DP comparison.
"""

import subprocess
import os
import random
import time
import csv
import sys
import statistics

# ── Configuration ──────────────────────────────────────────────────────
DIR = os.path.dirname(os.path.abspath(__file__))
GCC = "gcc"

TWOROW_SRC  = os.path.join(DIR, "LCS-2row.c")
ONEROW_SRC  = os.path.join(DIR, "LCS-1row.c")
TWOROW_EXE  = os.path.join(DIR, "bench_2row.exe")
ONEROW_EXE  = os.path.join(DIR, "bench_1row.exe")

NUM_TESTS   = 100
MAX_LEN     = 50000
TIMEOUT_SEC = 300

PROFILES = {
    "small": {
        "label": "Small Numbers (0–100)",
        "lo": 0,
        "hi": 100,
        "csv": os.path.join(DIR, "results_small.csv"),
        "plot": os.path.join(DIR, "plot_small.png"),
    },
    "sparse": {
        "label": "Sparse Numbers (0–65535)",
        "lo": 0,
        "hi": 65535,
        "csv": os.path.join(DIR, "results_sparse.csv"),
        "plot": os.path.join(DIR, "plot_sparse.png"),
    },
}

SUMMARY_FILE = os.path.join(DIR, "benchmark_summary.md")


def compile_file(src, exe):
    cmd = [GCC, "-O2", "-o", exe, src]
    print(f"  Compiling: {' '.join(cmd)}")
    r = subprocess.run(cmd, capture_output=True, text=True)
    if r.returncode != 0:
        print(f"  COMPILE ERROR:\n{r.stderr}")
        sys.exit(1)
    print(f"  → {os.path.basename(exe)} OK")


def generate_test(la, lb, lo, hi):
    a = [random.randint(lo, hi) for _ in range(la)]
    b = [random.randint(lo, hi) for _ in range(lb)]
    return a, b


def format_input(m, n, a, b):
    lines = [f"{m} {n}"]
    lines.append(" ".join(map(str, a)))
    lines.append(" ".join(map(str, b)))
    return "\n".join(lines) + "\n"


def run_exe(exe, input_data):
    t0 = time.perf_counter()
    r = subprocess.run(
        [exe], input=input_data, capture_output=True, text=True, timeout=TIMEOUT_SEC
    )
    elapsed = time.perf_counter() - t0
    if r.returncode != 0:
        return None, elapsed
    return r.stdout.strip(), elapsed


def make_length_schedule(num_tests, max_len):
    lengths = []
    buckets = [
        (10,    10,     100),
        (20,   100,    1000),
        (30,  1000,   10000),
        (30, 10000,   40000),
        (10, 40000, max_len),
    ]
    for count, lo, hi in buckets:
        for _ in range(count):
            la = random.randint(lo, hi)
            lb = random.randint(lo, hi)
            lengths.append((la, lb))
    random.shuffle(lengths)
    return lengths


def estimate_mem_2row():
    # dp[2][MAXN] uint32 + a[MAXN]+b[MAXN] uint16
    return 2 * 50001 * 4 + 2 * 50001 * 2


def estimate_mem_1row():
    # dp[MAXN] uint32 + a[MAXN]+b[MAXN] uint16
    return 50001 * 4 + 2 * 50001 * 2


def run_suite(profile_name, profile):
    label = profile["label"]
    lo, hi = profile["lo"], profile["hi"]
    csv_file = profile["csv"]
    plot_file = profile["plot"]

    print(f"\n{'='*70}")
    print(f"  Suite: {label}")
    print(f"  Value range: [{lo}, {hi}]   |   Distinct possible: {hi - lo + 1}")
    print(f"{'='*70}")

    schedule = make_length_schedule(NUM_TESTS, MAX_LEN)
    rows = []
    mismatches = 0

    for idx, (la, lb) in enumerate(schedule):
        pct = (idx + 1) / NUM_TESTS * 100
        print(f"\r  Test {idx+1:3d}/{NUM_TESTS}  len=({la:5d},{lb:5d})  [{pct:5.1f}%]", end="", flush=True)

        a, b = generate_test(la, lb, lo, hi)
        inp = format_input(la, lb, a, b)

        out_2, t_2 = run_exe(TWOROW_EXE, inp)
        out_1, t_1 = run_exe(ONEROW_EXE, inp)

        match = (out_2 == out_1) if (out_2 is not None and out_1 is not None) else False
        if not match:
            mismatches += 1

        lcs_len = int(out_2) if out_2 else -1
        product = la * lb

        rows.append({
            "test":       idx + 1,
            "len_a":      la,
            "len_b":      lb,
            "product":    product,
            "lcs_length": lcs_len,
            "time_2row":  round(t_2, 6),
            "time_1row":  round(t_1, 6),
            "speedup":    round(t_2 / t_1, 4) if t_1 > 0 else 0,
            "match":      match,
        })

    print("\n  Done.\n")

    # Save CSV
    fieldnames = list(rows[0].keys())
    with open(csv_file, "w", newline="") as f:
        w = csv.DictWriter(f, fieldnames=fieldnames)
        w.writeheader()
        w.writerows(rows)
    print(f"  → {len(rows)} rows saved to {os.path.basename(csv_file)}")

    # Stats
    t_2row  = [r["time_2row"] for r in rows]
    t_1row  = [r["time_1row"] for r in rows]
    speedups = [r["speedup"]  for r in rows]

    stats = {
        "label": label,
        "profile": profile_name,
        "mismatches": mismatches,
        "total_2row":   sum(t_2row),
        "total_1row":   sum(t_1row),
        "mean_2row":    statistics.mean(t_2row),
        "mean_1row":    statistics.mean(t_1row),
        "median_2row":  statistics.median(t_2row),
        "median_1row":  statistics.median(t_1row),
        "max_2row":     max(t_2row),
        "max_1row":     max(t_1row),
        "min_2row":     min(t_2row),
        "min_1row":     min(t_1row),
        "stdev_2row":   statistics.stdev(t_2row),
        "stdev_1row":   statistics.stdev(t_1row),
        "mean_speedup":   statistics.mean(speedups),
        "median_speedup": statistics.median(speedups),
        "max_speedup":    max(speedups),
        "min_speedup":    min(speedups),
        "rows": rows,
    }

    print_stats(stats)
    generate_plot(rows, label, plot_file)
    return stats


def print_stats(s):
    print(f"\n  {'':30s} {'2-Row DP':>12s}  {'1-Row DP':>12s}")
    print(f"  {'─'*30} {'─'*12}  {'─'*12}")
    print(f"  {'Total time (s)':30s} {s['total_2row']:12.3f}  {s['total_1row']:12.3f}")
    print(f"  {'Mean time (s)':30s} {s['mean_2row']:12.6f}  {s['mean_1row']:12.6f}")
    print(f"  {'Median time (s)':30s} {s['median_2row']:12.6f}  {s['median_1row']:12.6f}")
    print(f"  {'Max time (s)':30s} {s['max_2row']:12.6f}  {s['max_1row']:12.6f}")
    print(f"  {'Min time (s)':30s} {s['min_2row']:12.6f}  {s['min_1row']:12.6f}")
    print(f"  {'Std dev (s)':30s} {s['stdev_2row']:12.6f}  {s['stdev_1row']:12.6f}")
    print(f"\n  {'Mean speedup (2row/1row)':30s} {s['mean_speedup']:12.4f}×")
    print(f"  {'Median speedup':30s} {s['median_speedup']:12.4f}×")
    print(f"  {'Max speedup':30s} {s['max_speedup']:12.4f}×")
    print(f"  {'Min speedup':30s} {s['min_speedup']:12.4f}×")
    print(f"  {'Correctness':30s} {NUM_TESTS - s['mismatches']}/{NUM_TESTS}")

    rows = s["rows"]
    buckets_def = [
        ("Tiny   (≤100)",       0,          100*100),
        ("Small  (≤1K)",        100*100,    1000*1000),
        ("Medium (≤10K)",       1e6,        1e8),
        ("Large  (≤40K)",       1e8,        40000*40000),
        ("Max    (≤50K)",       40000*40000, float("inf")),
    ]
    print(f"\n  {'Bucket':22s} {'Count':>5s}  {'Avg 2row':>10s}  {'Avg 1row':>10s}  {'Avg Speedup':>11s}")
    print(f"  {'─'*22} {'─'*5}  {'─'*10}  {'─'*10}  {'─'*11}")
    for bname, blo, bhi in buckets_def:
        br = [r for r in rows if blo < r["product"] <= bhi]
        if not br:
            br = [r for r in rows if blo <= r["product"] <= bhi]
        if br:
            avg_2 = statistics.mean([r["time_2row"] for r in br])
            avg_1 = statistics.mean([r["time_1row"] for r in br])
            avg_s = statistics.mean([r["speedup"] for r in br])
            print(f"  {bname:22s} {len(br):5d}  {avg_2:10.4f}s  {avg_1:10.4f}s  {avg_s:10.4f}×")


def generate_plot(rows, title, plot_file):
    try:
        import matplotlib
        matplotlib.use("Agg")
        import matplotlib.pyplot as plt

        prods   = [r["product"]  for r in rows]
        t_2row  = [r["time_2row"] for r in rows]
        t_1row  = [r["time_1row"] for r in rows]
        speedups = [r["speedup"] for r in rows]

        fig, axes = plt.subplots(1, 3, figsize=(18, 5))
        fig.suptitle(f"LCS Space-Optimized Benchmark: {title}", fontsize=14, fontweight="bold")

        # Time vs size
        ax = axes[0]
        ax.scatter(prods, t_2row, s=12, alpha=0.7, label="2-Row DP", color="tomato")
        ax.scatter(prods, t_1row, s=12, alpha=0.7, label="1-Row DP", color="steelblue")
        ax.set_xlabel("Input size (m × n)")
        ax.set_ylabel("Time (seconds)")
        ax.set_title("Execution Time vs Input Size")
        ax.legend()
        ax.set_xscale("log")
        ax.set_yscale("log")
        ax.grid(True, alpha=0.3)

        # Speedup vs size
        ax = axes[1]
        ax.scatter(prods, speedups, s=12, alpha=0.7, color="forestgreen")
        mean_sp = statistics.mean(speedups)
        ax.axhline(y=mean_sp, color="red", linestyle="--", label=f"Mean: {mean_sp:.4f}×")
        ax.axhline(y=1.0, color="gray", linestyle=":", alpha=0.5, label="1× (equal)")
        ax.set_xlabel("Input size (m × n)")
        ax.set_ylabel("Speedup (2-Row / 1-Row)")
        ax.set_title("Speedup Ratio")
        ax.legend()
        ax.set_xscale("log")
        ax.grid(True, alpha=0.3)

        # Box plot for large tests
        ax = axes[2]
        large = [r for r in rows if r["product"] > 1e8]
        if large:
            t2_large = [r["time_2row"] for r in large]
            t1_large = [r["time_1row"] for r in large]
            bp = ax.boxplot([t2_large, t1_large],
                            tick_labels=["2-Row DP", "1-Row DP"],
                            patch_artist=True)
            for patch, color in zip(bp["boxes"], ["tomato", "steelblue"]):
                patch.set_facecolor(color)
                patch.set_alpha(0.5)
            ax.set_ylabel("Time (seconds)")
            ax.set_title(f"Large Tests Distribution (n={len(large)})")
        ax.grid(True, alpha=0.3)

        plt.tight_layout()
        plt.savefig(plot_file, dpi=150)
        print(f"  → Plot saved to {os.path.basename(plot_file)}")
    except ImportError:
        print("  (matplotlib not available — skipping plot)")


def write_summary(all_stats):
    mem_2row = estimate_mem_2row()
    mem_1row = estimate_mem_1row()

    with open(SUMMARY_FILE, "w", encoding="utf-8") as f:
        f.write("# LCS Space-Optimized DP Benchmark Summary\n\n")
        f.write("## 2-Row DP vs Single-Array (1-Row) DP — 16-bit Unsigned Integer Arrays\n\n")
        f.write(f"**Tests per suite:** {NUM_TESTS}  \n")
        f.write(f"**Max array length:** {MAX_LEN:,}  \n")
        f.write(f"**Compiler:** GCC with `-O2`  \n")
        f.write(f"**Optimization pragma:** `O3,unroll-loops,inline`  \n\n")
        f.write("---\n\n")

        for s in all_stats:
            f.write(f"## {s['label']}\n\n")
            f.write(f"**Correctness:** {NUM_TESTS - s['mismatches']}/{NUM_TESTS}  \n\n")
            f.write("### Timing\n\n")
            f.write("| Metric | 2-Row DP | 1-Row DP |\n|---|---:|---:|\n")
            f.write(f"| **Total time** | {s['total_2row']:.3f}s | {s['total_1row']:.3f}s |\n")
            f.write(f"| **Mean time** | {s['mean_2row']:.6f}s | {s['mean_1row']:.6f}s |\n")
            f.write(f"| **Median time** | {s['median_2row']:.6f}s | {s['median_1row']:.6f}s |\n")
            f.write(f"| **Max time** | {s['max_2row']:.6f}s | {s['max_1row']:.6f}s |\n")
            f.write(f"| **Min time** | {s['min_2row']:.6f}s | {s['min_1row']:.6f}s |\n")
            f.write(f"| **Std dev** | {s['stdev_2row']:.6f}s | {s['stdev_1row']:.6f}s |\n\n")
            f.write("### Speedup (2-Row / 1-Row)\n\n")
            f.write(f"- **Mean:** {s['mean_speedup']:.4f}×\n")
            f.write(f"- **Median:** {s['median_speedup']:.4f}×\n")
            f.write(f"- **Max:** {s['max_speedup']:.4f}×\n")
            f.write(f"- **Min:** {s['min_speedup']:.4f}×\n\n")
            f.write("> A speedup > 1 means 1-Row is faster. A speedup < 1 means 2-Row is faster.\n\n")

            rows = s["rows"]
            buckets_def = [
                ("Tiny (≤100)",    0,          100*100),
                ("Small (≤1K)",    100*100,    1000*1000),
                ("Medium (≤10K)",  1e6,        1e8),
                ("Large (≤40K)",   1e8,        40000*40000),
                ("Max (≤50K)",     40000*40000, float("inf")),
            ]
            f.write("### By Input Size\n\n")
            f.write("| Bucket | Count | Avg 2-Row | Avg 1-Row | Avg Speedup |\n")
            f.write("|---|---:|---:|---:|---:|\n")
            for bname, blo, bhi in buckets_def:
                br = [r for r in rows if blo < r["product"] <= bhi]
                if not br:
                    br = [r for r in rows if blo <= r["product"] <= bhi]
                if br:
                    avg_2 = statistics.mean([r["time_2row"] for r in br])
                    avg_1 = statistics.mean([r["time_1row"] for r in br])
                    avg_s = statistics.mean([r["speedup"] for r in br])
                    f.write(f"| {bname} | {len(br)} | {avg_2:.4f}s | {avg_1:.4f}s | **{avg_s:.4f}×** |\n")
            f.write("\n---\n\n")

        # Memory section
        f.write("## Memory Comparison\n\n")
        f.write("| Component | 2-Row DP | 1-Row DP |\n|---|---:|---:|\n")
        f.write(f"| `dp` array | {2*50001*4:,} bytes (2×50001×4) | {50001*4:,} bytes (50001×4) |\n")
        f.write(f"| `a` + `b` arrays | {2*50001*2:,} bytes | {2*50001*2:,} bytes |\n")
        f.write(f"| **Total** | **{mem_2row:,} bytes ({mem_2row/1024:.1f} KB)** | **{mem_1row:,} bytes ({mem_1row/1024:.1f} KB)** |\n")
        f.write(f"| **Savings** | — | **{mem_2row - mem_1row:,} bytes ({(mem_2row-mem_1row)/1024:.1f} KB, {(1 - mem_1row/mem_2row)*100:.1f}%)** |\n\n")

        f.write("---\n\n## Analysis\n\n")
        f.write("### Why might 1-Row be faster?\n\n")
        f.write("1. **Better cache utilization:** The 1-row approach touches half the memory of 2-row. ")
        f.write("With large `n`, the 2-row DP alternates between two rows of ~200 KB each, ")
        f.write("while the 1-row approach keeps a single ~200 KB row hot in cache.\n")
        f.write("2. **No row-index computation:** The 2-row version computes `i & 1` and `1 - bi` ")
        f.write("for every cell. The 1-row version just accesses `dp[j]` directly.\n")
        f.write("3. **Fewer array accesses:** The 2-row version indexes `dp[bi][j]` and `dp[1-bi][j]` ")
        f.write("(2D array). The 1-row version indexes `dp[j]` (1D array) with a register variable `prev`.\n\n")
        f.write("### Why might they be similar?\n\n")
        f.write("1. Both have **identical O(mn) time complexity** — same number of comparisons and assignments.\n")
        f.write("2. The compiler with `-O3` may optimize the 2D indexing into something equally efficient.\n")
        f.write("3. For small inputs, the overhead is negligible and process startup dominates.\n")

    print(f"\n  Summary written to {os.path.basename(SUMMARY_FILE)}")


# ── Main ───────────────────────────────────────────────────────────────

def main():
    print("=" * 70)
    print("  LCS SPACE-OPTIMIZED BENCHMARK")
    print("  2-Row DP  vs  1-Row (Single-Array) DP")
    print("  16-bit unsigned integers — no bit-parallel")
    print("=" * 70)

    # Compile
    print("\n[Compiling]")
    compile_file(TWOROW_SRC, TWOROW_EXE)
    compile_file(ONEROW_SRC, ONEROW_EXE)

    # Run both suites
    all_stats = []
    for pname, profile in PROFILES.items():
        stats = run_suite(pname, profile)
        all_stats.append(stats)

    # Combined summary
    print("\n" + "=" * 70)
    print("  Writing combined summary ...")
    write_summary(all_stats)

    print("\n" + "=" * 70)
    print("  ALL DONE.")
    print("=" * 70)


if __name__ == "__main__":
    main()
