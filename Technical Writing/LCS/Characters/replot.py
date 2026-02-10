"""Regenerate the benchmark plot from the existing CSV data."""
import os
import csv
import statistics

DIR = os.path.dirname(os.path.abspath(__file__))
CSV_FILE = os.path.join(DIR, "benchmark_results.csv")
PLOT_FILE = os.path.join(DIR, "benchmark_plot.png")
MAX_LEN = 50000

def estimate_memory_nicad(n):
    return 2 * 50001 * 2 + 2 * 50001

def estimate_memory_bitpar(n):
    words = (50001 + 63) // 64
    return 256 * words * 8 + words * 8 + 2 * 50001

with open(CSV_FILE, "r") as f:
    reader = csv.DictReader(f)
    rows = []
    for r in reader:
        rows.append({
            "test": int(r["test"]),
            "len_a": int(r["len_a"]),
            "len_b": int(r["len_b"]),
            "product": int(r["product"]),
            "lcs_length": int(r["lcs_length"]),
            "time_nicad": float(r["time_nicad"]),
            "time_bitpar": float(r["time_bitpar"]),
            "speedup": float(r["speedup"]),
            "match": r["match"] == "True",
            "mem_nicad": int(r["mem_nicad"]),
            "mem_bitpar": int(r["mem_bitpar"]),
        })

t_nicad = [r["time_nicad"] for r in rows]
t_bitpar = [r["time_bitpar"] for r in rows]
speedups = [r["speedup"] for r in rows]
prods = [r["product"] for r in rows]
mem_n = estimate_memory_nicad(MAX_LEN)
mem_b = estimate_memory_bitpar(MAX_LEN)

import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt

fig, axes = plt.subplots(2, 2, figsize=(14, 10))
fig.suptitle("LCS Benchmark: NiCad-DP vs Bit-Parallel (Hyyro)", fontsize=14, fontweight="bold")

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

# (1,0) Time distribution box plot
ax = axes[1][0]
large = [r for r in rows if r["product"] > 1e8]
if large:
    tn_large = [r["time_nicad"] for r in large]
    tb_large = [r["time_bitpar"] for r in large]
    bp = ax.boxplot([tn_large, tb_large], tick_labels=["NiCad-DP", "Bit-Parallel"],
               patch_artist=True)
    colors_box = ["tomato", "steelblue"]
    for patch, color in zip(bp["boxes"], colors_box):
        patch.set_facecolor(color)
        patch.set_alpha(0.5)
    ax.set_ylabel("Time (seconds)")
    ax.set_title(f"Time Distribution (large tests, m×n > 10⁸, count={len(large)})")
ax.grid(True, alpha=0.3)

# (1,1) Memory comparison
ax = axes[1][1]
labels = ["NiCad-DP", "Bit-Parallel"]
mem_vals = [mem_n / 1024, mem_b / 1024]
colors_bar = ["tomato", "steelblue"]
bars = ax.bar(labels, mem_vals, color=colors_bar, alpha=0.7, edgecolor="black")
ax.set_ylabel("Static Memory (KB)")
ax.set_title("Static Memory Usage (at MAXN=50001)")
for bar, val in zip(bars, mem_vals):
    ax.text(bar.get_x() + bar.get_width()/2, bar.get_height() + 5,
            f"{val:.0f} KB", ha="center", va="bottom", fontweight="bold")
ax.grid(True, alpha=0.3, axis="y")

plt.tight_layout()
plt.savefig(PLOT_FILE, dpi=150)
print(f"Plot saved to {PLOT_FILE}")
