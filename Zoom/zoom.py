_, step = map(int, input().split())

nums = list(map(int, input().split()))
soln = []

for x, n in enumerate(nums):
    if (x + 1) % step == 0:
        soln.append(n)
print(*soln)
