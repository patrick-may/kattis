n = int(input())
solns = []
curr = 1
while curr < n:
    solns.append(curr)
    curr *= 2

print(len(solns))
print(*solns)
