
n = int(input())
bags = 0
groups = n // 4
bags += 4 * (groups * (groups - 1) // 2)
bags += 4

print(bags)
