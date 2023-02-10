soln = 0
probs = input().split(";")

for thingy in probs:
    if "-" in thingy:
        start, end = map(int, thingy.split("-"))
        soln += (end - start) + 1
    else:
        soln += 1

print(soln)