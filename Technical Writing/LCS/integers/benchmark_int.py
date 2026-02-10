"""
LCS Integer Benchmark: NiCad-style DP vs Bit-Parallel (Hyyro)
Two test suites: small-range numbers and sparse-range numbers.
Each suite runs 100 tests with varying array lengths (max 50000).
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

NICAD_SRC  = os.path.join(DIR, "LCS0-nicad-int.c")
BITPAR_SRC = os.path.join(DIR, "LCS0_optimized-int.c")
NICAD_EXE  = os.path.join(DIR, "bench_nicad_int.exe")
BITPAR_EXE = os.path.join(DIR, "bench_bitpar_int.exe")

NUM_TESTS   = 100
MAX_LEN     = 50000
TIMEOUT_SEC = 300

# Test profiles
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


def estimate_mem_nicad():
    # dp[2][MAXN] uint32 + a[MAXN]+b[MAXN] uint16
    return 2 * 50001 * 4 + 2 * 50001 * 2


def estimate_mem_bitpar(num_distinct, nw):
    # PM: num_distinct * nw * 8, row: nw * 8, val_to_idx: 65536*4, arrays: 2*MAXN*2
    return num_distinct * nw * 8 + nw * 8 + 65536 * 4 + 2 * 50001 * 2


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

        out_n, t_n = run_exe(NICAD_EXE, inp)
        out_b, t_b = run_exe(BITPAR_EXE, inp)

        match = (out_n == out_b) if (out_n is not None and out_b is not None) else False
        if not match:
            mismatches += 1

        lcs_len = int(out_n) if out_n else -1
        product = la * lb
        distinct_b = len(set(b))

        rows.append({
            "test":        idx + 1,
            "len_a":       la,
            "len_b":       lb,
            "product":     product,
            "distinct_b":  distinct_b,
            "lcs_length":  lcs_len,
            "time_nicad":  round(t_n, 6),
            "time_bitpar": round(t_b, 6),
            "speedup":     round(t_n / t_b, 2) if t_b > 0 else 0,
            "match":       match,
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
    t_nicad  = [r["time_nicad"]  for r in rows]
    t_bitpar = [r["time_bitpar"] for r in rows]
    speedups = [r["speedup"]     for r in rows]

    stats = {
        "label": label,
        "profile": profile_name,
        "mismatches": mismatches,
        "total_nicad": sum(t_nicad),
        "total_bitpar": sum(t_bitpar),
        "mean_nicad": statistics.mean(t_nicad),
        "mean_bitpar": statistics.mean(t_bitpar),
        "median_nicad": statistics.median(t_nicad),
        "median_bitpar": statistics.median(t_bitpar),
        "max_nicad": max(t_nicad),
        "max_bitpar": max(t_bitpar),
        "min_nicad": min(t_nicad),
        "min_bitpar": min(t_bitpar),
        "stdev_nicad": statistics.stdev(t_nicad),
        "stdev_bitpar": statistics.stdev(t_bitpar),
        "mean_speedup": statistics.mean(speedups),
        "median_speedup": statistics.median(speedups),
        "max_speedup": max(speedups),
        "rows": rows,
    }

    print_stats(stats)
    generate_plot(rows, label, plot_file)
    return stats


def print_stats(s):
    print(f"\n  {'':30s} {'NiCad-DP':>12s}  {'Bit-Parallel':>12s}")
    print(f"  {'─'*30} {'─'*12}  {'─'*12}")
    print(f"  {'Total time (s)':30s} {s['total_nicad']:12.3f}  {s['total_bitpar']:12.3f}")
    print(f"  {'Mean time (s)':30s} {s['mean_nicad']:12.6f}  {s['mean_bitpar']:12.6f}")
    print(f"  {'Median time (s)':30s} {s['median_nicad']:12.6f}  {s['median_bitpar']:12.6f}")
    print(f"  {'Max time (s)':30s} {s['max_nicad']:12.6f}  {s['max_bitpar']:12.6f}")
    print(f"  {'Min time (s)':30s} {s['min_nicad']:12.6f}  {s['min_bitpar']:12.6f}")
    print(f"  {'Std dev (s)':30s} {s['stdev_nicad']:12.6f}  {s['stdev_bitpar']:12.6f}")
    print(f"\n  {'Mean speedup':30s} {s['mean_speedup']:12.2f}×")
    print(f"  {'Median speedup':30s} {s['median_speedup']:12.2f}×")
    print(f"  {'Max speedup':30s} {s['max_speedup']:12.2f}×")
    print(f"  {'Correctness':30s} {NUM_TESTS - s['mismatches']}/{NUM_TESTS}")

    # By bucket
    rows = s["rows"]
    buckets_def = [
        ("Tiny   (≤100)",       0,          100*100),
        ("Small  (≤1K)",        100*100,    1000*1000),
        ("Medium (≤10K)",       1e6,        1e8),
        ("Large  (≤40K)",       1e8,        40000*40000),
        ("Max    (≤50K)",       40000*40000, float("inf")),
    ]
    print(f"\n  {'Bucket':22s} {'Count':>5s}  {'Avg Nicad':>10s}  {'Avg BitPar':>10s}  {'Avg Speedup':>11s}")
    print(f"  {'─'*22} {'─'*5}  {'─'*10}  {'─'*10}  {'─'*11}")
    for bname, blo, bhi in buckets_def:
        br = [r for r in rows if blo < r["product"] <= bhi]
        if not br:
            br = [r for r in rows if blo <= r["product"] <= bhi]
        if br:
            avg_n = statistics.mean([r["time_nicad"] for r in br])
            avg_b = statistics.mean([r["time_bitpar"] for r in br])
            avg_s = statistics.mean([r["speedup"] for r in br])
            print(f"  {bname:22s} {len(br):5d}  {avg_n:10.4f}s  {avg_b:10.4f}s  {avg_s:10.2f}×")


def generate_plot(rows, title, plot_file):
    try:
        import matplotlib
        matplotlib.use("Agg")
        import matplotlib.pyplot as plt

        prods = [r["product"] for r in rows]
        t_nicad = [r["time_nicad"] for r in rows]
        t_bitpar = [r["time_bitpar"] for r in rows]
        speedups = [r["speedup"] for r in rows]

        fig, axes = plt.subplots(1, 3, figsize=(18, 5))
        fig.suptitle(f"LCS Integer Benchmark: {title}", fontsize=14, fontweight="bold")

        # Time vs size
        ax = axes[0]
        ax.scatter(prods, t_nicad,  s=12, alpha=0.7, label="NiCad-DP", color="tomato")
        ax.scatter(prods, t_bitpar, s=12, alpha=0.7, label="Bit-Parallel", color="steelblue")
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
        ax.axhline(y=mean_sp, color="red", linestyle="--", label=f"Mean: {mean_sp:.1f}×")
        ax.set_xlabel("Input size (m × n)")
        ax.set_ylabel("Speedup (×)")
        ax.set_title("Speedup (NiCad / BitParallel)")
        ax.legend()
        ax.set_xscale("log")
        ax.grid(True, alpha=0.3)

        # Box plot for large tests
        ax = axes[2]
        large = [r for r in rows if r["product"] > 1e8]
        if large:
            tn_large = [r["time_nicad"] for r in large]
            tb_large = [r["time_bitpar"] for r in large]
            bp = ax.boxplot([tn_large, tb_large],
                            tick_labels=["NiCad-DP", "Bit-Parallel"],
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
    mem_nicad = estimate_mem_nicad()
    with open(SUMMARY_FILE, "w", encoding="utf-8") as f:
        f.write("# LCS Integer Benchmark Summary\n\n")
        f.write("## NiCad-Style DP vs Bit-Parallel (Hyyro) — 16-bit Unsigned Integer Arrays\n\n")
        f.write(f"**Tests per suite:** {NUM_TESTS}  \n")
        f.write(f"**Max array length:** {MAX_LEN:,}  \n")
        f.write(f"**Compiler:** GCC with `-O2`, bit-parallel with `-mpopcnt`  \n\n")
        f.write("---\n\n")

        for s in all_stats:
            f.write(f"## {s['label']}\n\n")
            f.write(f"**Correctness:** {NUM_TESTS - s['mismatches']}/{NUM_TESTS}  \n\n")
            f.write("### Timing\n\n")
            f.write("| Metric | NiCad-DP | Bit-Parallel |\n|---|---:|---:|\n")
            f.write(f"| **Total time** | {s['total_nicad']:.3f}s | {s['total_bitpar']:.3f}s |\n")
            f.write(f"| **Mean time** | {s['mean_nicad']:.6f}s | {s['mean_bitpar']:.6f}s |\n")
            f.write(f"| **Median time** | {s['median_nicad']:.6f}s | {s['median_bitpar']:.6f}s |\n")
            f.write(f"| **Max time** | {s['max_nicad']:.6f}s | {s['max_bitpar']:.6f}s |\n")
            f.write(f"| **Min time** | {s['min_nicad']:.6f}s | {s['min_bitpar']:.6f}s |\n")
            f.write(f"| **Std dev** | {s['stdev_nicad']:.6f}s | {s['stdev_bitpar']:.6f}s |\n\n")
            f.write("### Speedup\n\n")
            f.write(f"- **Mean:** {s['mean_speedup']:.2f}×\n")
            f.write(f"- **Median:** {s['median_speedup']:.2f}×\n")
            f.write(f"- **Max:** {s['max_speedup']:.2f}×\n\n")

            # Bucket table
            rows = s["rows"]
            buckets_def = [
                ("Tiny (≤100)",    0,          100*100),
                ("Small (≤1K)",    100*100,    1000*1000),
                ("Medium (≤10K)",  1e6,        1e8),
                ("Large (≤40K)",   1e8,        40000*40000),
                ("Max (≤50K)",     40000*40000, float("inf")),
            ]
            f.write("### By Input Size\n\n")
            f.write("| Bucket | Count | Avg NiCad | Avg BitPar | Avg Speedup |\n")
            f.write("|---|---:|---:|---:|---:|\n")
            for bname, blo, bhi in buckets_def:
                br = [r for r in rows if blo < r["product"] <= bhi]
                if not br:
                    br = [r for r in rows if blo <= r["product"] <= bhi]
                if br:
                    avg_n = statistics.mean([r["time_nicad"] for r in br])
                    avg_b = statistics.mean([r["time_bitpar"] for r in br])
                    avg_s = statistics.mean([r["speedup"] for r in br])
                    f.write(f"| {bname} | {len(br)} | {avg_n:.4f}s | {avg_b:.4f}s | **{avg_s:.2f}×** |\n")
            f.write("\n---\n\n")

        # Memory section
        f.write("## Memory Comparison\n\n")
        f.write("| | NiCad-DP | Bit-Parallel (small) | Bit-Parallel (sparse) |\n")
        f.write("|---|---:|---:|---:|\n")

        nw = (MAX_LEN + 63) // 64
        mem_bp_small = estimate_mem_bitpar(101, nw)   # 101 distinct values
        mem_bp_sparse = estimate_mem_bitpar(min(MAX_LEN, 65536), nw)
        f.write(f"| **Static memory** | {mem_nicad/1024:.1f} KB | {mem_bp_small/1024:.1f} KB | {mem_bp_sparse/1024:.1f} KB |\n\n")

        f.write("### Breakdown\n\n")
        f.write("**NiCad-DP:**\n")
        f.write("- `dp[2][50001]` of `uint32` = 400,008 bytes\n")
        f.write("- `a[50001] + b[50001]` of `uint16` = 200,004 bytes\n")
        f.write(f"- **Total: ~{mem_nicad/1024:.1f} KB**\n\n")
        f.write("**Bit-Parallel (dynamically allocated PM):**\n")
        f.write(f"- Small numbers: ~{101} distinct → PM = {101*nw*8/1024:.1f} KB\n")
        f.write(f"- Sparse numbers: up to ~{min(MAX_LEN,65536)} distinct → PM = {min(MAX_LEN,65536)*nw*8/1024/1024:.1f} MB\n")
        f.write(f"- `val_to_idx[65536]` = 256 KB (always)\n")
        f.write(f"- `row[{nw}]` = {nw*8/1024:.1f} KB\n\n")

        f.write("> The bit-parallel approach dynamically allocates PM only for distinct values in b, "
                "avoiding the 410 MB static allocation that `PM[65536][WORDS]` would require.\n\n")

        f.write("---\n\n## Key Observations\n\n")
        f.write("1. **Small numbers** (range 0–100): High collision rate → longer LCS. ")
        f.write("Both algorithms do the same work per cell, but bit-parallel packs 64 into one word.\n")
        f.write("2. **Sparse numbers** (range 0–65535): Low collision rate → shorter LCS, more distinct PM rows. ")
        f.write("Bit-parallel uses more memory for PM but computation time is similar per cell.\n")
        f.write("3. The **speedup is consistent** across both modes because it depends on input *size*, not value range.\n")

    print(f"\n  Summary written to {os.path.basename(SUMMARY_FILE)}")


# ── Main ───────────────────────────────────────────────────────────────

def main():
    print("=" * 70)
    print("  LCS INTEGER BENCHMARK")
    print("  NiCad-DP  vs  Bit-Parallel (Hyyro)")
    print("  16-bit unsigned integers")
    print("=" * 70)

    # Compile
    print("\n[Compiling]")
    compile_file(NICAD_SRC, NICAD_EXE)
    compile_file(BITPAR_SRC, BITPAR_EXE, ["-mpopcnt"])

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
