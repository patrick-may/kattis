from sys import stdin

r, c = map(int, input().split())

table = []
cols = [""] * c
for _ in range(r):
    line = stdin.readline().strip()
    table.append(line)
    for idx in range(c):
        cols[idx] += line[idx]

soln = 0
while len(cols[0]) > 0:
    if len(set(cols)) != len(cols):  # duplicate column
        break
    newcols = [s[1:] for s in cols]
    cols = newcols
    soln += 1

print(soln - 1)
