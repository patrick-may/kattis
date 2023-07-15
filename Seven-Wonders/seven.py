from collections import Counter

res = Counter(input())

soln = sum([v**2 for v in res.values()])
if len(res) == 3:
    soln += 7 * min(res.values())
print(soln)
