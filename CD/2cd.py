import sys

r = sys.stdin.readline


def tc(n, m):
    jack = set([int(r()) for _ in range(n)])
    jill = set([int(r()) for _ in range(m)])
    print(len((jack & jill)))


while 1:
    n, m = map(int, r().split())
    if n == m == 0:
        exit()
    tc(n, m)
