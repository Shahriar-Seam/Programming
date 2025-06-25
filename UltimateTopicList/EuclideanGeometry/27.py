from sys import stdin
from math import sin, pi

def area(r):
    return pi * r * r

for line in stdin:
    R, n = map(float, line.split())
    
    r = R * sin(pi / n) / (1 + sin(pi / n))
    
    total = area(R)
    area_of_n_gon = .5 * n * (R - r) * (R - r) * sin(2 * pi / n)
    total_area_to_exclude_from_small_n_gon = n * .5 * r * r * (pi - (2 * pi / n))
    total_inner_area = area_of_n_gon - total_area_to_exclude_from_small_n_gon
    total_outer_area = total - n * area(r) - total_inner_area
    
    if n == 1:
        r = R
        total_inner_area = 0
        total_outer_area = 0
    
    print(f"{r:.10f} {total_inner_area:.10f} {total_outer_area:.10f}")