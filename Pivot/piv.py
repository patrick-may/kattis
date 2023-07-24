from sys import stdin

inp = stdin.readline

nct = int(inp())
nums = list(map(int, inp().strip().split()))

pivct = 0
rightmins = []
currmin = nums[-1]
for n in nums[::-1]:
    currmin = min(currmin, n)
    rightmins.append(currmin)

rightmins = rightmins[::-1]

# left edge case
if nums[0] < rightmins[1]:
    pivct += 1

leftmax = nums[0]
for x, n in enumerate(nums[1 : nct - 1]):
    if leftmax <= n and rightmins[x + 1] >= n:
        pivct += 1
    leftmax = max(leftmax, n)

# right edgecase
if nums[-1] >= leftmax:
    pivct += 1

print(pivct)
