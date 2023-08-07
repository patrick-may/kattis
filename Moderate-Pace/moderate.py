def median(coll):
    mid = len(coll) // 2
    return sorted(coll)[mid]

runners = int(input())

runs = [[0, 0, 0] for i in range(runners)]

for j in range(3):
    times = map(int, input().strip().split())
    for idx, v in enumerate(times):
        runs[idx][j] = v

for coll in runs:
    print(median(coll), end=" ")

print()
