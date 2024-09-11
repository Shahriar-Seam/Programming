import math

class Solution:
    def possible(n, a, b, c, m):
        return m // a + m // b + m // c - m // math.lcm(a, b) - m // math.lcm(b, c) - m // math.lcm(a, c) + m // math.lcm(a, b, c) >= n

    def nthUglyNumber(self, n: int, a: int, b: int, c: int) -> int:
        l , r = 0, 1 << 32

        for _ in range(100):
            m = (l + r) // 2

            if Solution.possible(n, a, b, c, m):
                r = m
            else:
                l = m

        return r