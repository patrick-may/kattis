from sys import stdin


def tc(n, m):
    jack = set([int(stdin.readline()) for _ in range(n)])
    jill = set([int(stdin.readline()) for _ in range(m)])
    print(len(jack.intersection(jill)))


for line in stdin:
    n, m = map(int, line.strip().split())
    if n == m == 0:
        exit()
    tc(n, m)
