from collections import deque

check = [
        "ABCD",
        "EFGH",
        "IJKL",
        "MNO.",
        ]

inp = [input() for _ in range(4)]

soln = 0

def dist(x, y, desired):
    subsoln = 0
    to_visit = deque([(x, y, 0)])
    visited = set()
    
    while to_visit:

        currx, curry, dist = to_visit.popleft()
        if (currx, curry) in visited:
            continue

        if inp[currx][curry] == desired:
            return dist 

        visited.add((currx, curry))
        if currx > 0:
            to_visit.append((currx - 1, curry, dist + 1))
        if currx < 3:
            to_visit.append((currx + 1, curry, dist + 1))
        if curry > 0:
            to_visit.append((currx, curry - 1, dist + 1))
        if curry < 3:
            to_visit.append((currx, curry + 1, dist + 1))



for x, row in enumerate(check):
    for y, c in enumerate(row):
        val = dist(x, y, c)
        soln += val if c != '.' else 0

print(soln)

