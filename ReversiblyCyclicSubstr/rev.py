s = input()
rots = set()

for idx in range(len(s)):
    rotated = s[idx:] + s[:idx]
    rots.add(rotated)
    for x in range(len(rotated)):
        rots.add(rotated[:x])

soln = True
left, right = s[1:], s[:-1]
print(left[::-1], right[::-1])
print(rots)
if left[::-1] in rots and right[::-1] in rots:
    soln = False
print(1 if soln else 0)

