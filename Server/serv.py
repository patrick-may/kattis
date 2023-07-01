_, time = map(int, input().strip().split())
tasks = map(int, input().strip().split())

soln = 0
for t in tasks:
    if t > time:
        break
    time -= t
    soln += 1
print(soln)

