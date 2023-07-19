s = input()
start = s[0]
soln = s[0]

for c in s:
    if c != start:
        soln += c
        start = c

print(soln)
