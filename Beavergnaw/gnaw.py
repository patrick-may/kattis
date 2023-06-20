from sys import stdin
from math import pi

def tc(D, V):
    left = pi * (D**3)/4 - pi * (D**3)/12 - V 
    left = left * (6 / pi)
    print(left ** (1.0/3.0))

for line in stdin:
    D, V = map(int, line.strip().split())
    if D == V and D == 0:
        exit()
    tc(D, V)