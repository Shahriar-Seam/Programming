from math import pi
from sys import stdin

def vol(R, h):
    return pi*(h**2*R-(h**3)/3)

for l in stdin:
    H,h1,h2=map(int,l.split())
    R=H/2
    v=[]
    v.append(vol(R,H-h1))
    v.append(vol(R,h2))
    v.append(vol(R,H)-v[0]-v[1])
    v.sort()
    print(f"{v[0]:.6f} {v[1]:.6f} {v[2]:.6f}")