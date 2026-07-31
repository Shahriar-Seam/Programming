$sizes = @(
    @(5, 5),         # 1 - small
    @(10, 10),       # 2 - small
    @(3, 3),         # 3 - small
    @(20, 15),       # 4 - small
    @(100, 100),     # 5 - medium
    @(500, 500),     # 6 - medium
    @(1000, 1000),   # 7 - medium
    @(2000, 2000),   # 8 - medium
    @(5000, 3000),   # 9 - medium
    @(8000, 8000),   # 10 - medium
    @(10000, 10000), # 11 - big
    @(20000, 20000), # 12 - big
    @(30000, 30000), # 13 - big
    @(50000, 50000), # 14 - big
    @(70000, 70000), # 15 - big
    @(100000, 100000), # 16 - full
    @(100000, 100000), # 17 - full
    @(100000, 100000), # 18 - full
    @(100000, 100000), # 19 - full
    @(100000, 100000)  # 20 - full
)

$base = "C:\Users\Anonymous_HF\Desktop\Programming\Problems\Subarray_MEX_Query"

for ($i = 0; $i -lt $sizes.Count; $i++) {
    $num = $i + 1
    $n = $sizes[$i][0]
    $q = $sizes[$i][1]
    Write-Host "Generating testcase $num (N=$n, Q=$q)..."
    
    # Use cmd /c with redirection for reliable binary piping
    cmd /c "`"$base\generator.exe`" $n $q > `"$base\testcases\$num.in`""
    cmd /c "`"$base\solution-opt.exe`" < `"$base\testcases\$num.in`" > `"$base\testcases\$num.out`""
}

Write-Host "Done! Generated 20 testcases."
