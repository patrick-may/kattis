input()

from sys import stdin

for line in stdin:
    b, p = map(float, line.strip().split())
    calc = 60 * b / p 
    minABPM = ((b - 1) / b) * calc
    maxABPM = ((b + 1) / b) * calc 
    print(f"{minABPM:.4f} {calc:.4f} {maxABPM:.4f}")
