from sys import stdin

input() # discard num elems

soln = 0
for line in stdin:
    n = line.strip()
    soln += int(n[:-1]) ** int(n[-1])

print(soln)