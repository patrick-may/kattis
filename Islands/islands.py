from collections import deque

# nah screw this problem bro how is it only a 1.8?
def islands(planet):
    soln = 0
    visited = set()
    to_visit = deque()
    for i in range(len(planet)):
        for j in range(len(planet[0])):
            # skip places we've already diddled
            if (i, j) in visited:
                continue

            to_visit.append(planet[i][j])
            while len(to_visit) > 0:
                working_spot = to_visit.popleft()
                if working_spot == 'W':
                    visited.add((i, j))
                    break
                if working_spot == 'C':
                    break # nothing to do with a cloud here
                if working_spot == 'L':


rows, cols  = map(int, input().split())
planet = []
for a in range(rows):
    planet.append(input())
print(islands(planet))