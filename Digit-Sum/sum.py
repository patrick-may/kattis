def naive_sum(n):
    total = 0
    for i in range(n + 1):
        total += sum([int(j) for j in str(i)])
    return total


def digsum(n, first):
    n = int(n)
    if n < 10 and first:
        return sum(range(n+1))
    elif n < 10:
        return 45
    
    leading, trailing = int(str(n)[0]), str(n)[1:]
    below = digsum(trailing, False)
    total = 0

    if first:
        for i in range(leading):
            total += i + below
        total += leading
    else:
        total += 45 + 10*below

    return total
    
def solve():
    start, end = map(int, input().split())
    s = digsum(start, True)
    e = digsum(end, True)
    print(s,e,)
    print(naive_sum(start), naive_sum(end),)

cases = int(input())
for _ in range(cases):
    solve()