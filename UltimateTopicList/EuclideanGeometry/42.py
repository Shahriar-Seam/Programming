for _ in range(1, int(input()) + 1):
    print(f"Case {_}: {4 * int(input()) ** 2 + 0.25:.2f}")

"""
    AB² + AC² = BC² = (2r)² = 4r²
    AB² = 4r² - AC²
    
    s = AB² + AC
    s = 4r² - AC² + AC
    s = -AC² + AC + 4r² ---- 1
    
    ds/dAC = -2AC + 1
    
    d²s/dAC² = -2 (Maxima can be found)
    
    let,
    ds/dAC = 0
    -2AC + 1 = 0
    AC = 1 / 2
    
    put AC into 1
    s = - 1 / 4 + 1 / 2 + 4r²
    s = 1 / 4 + 4r² (Ans. 👻)
"""