h, k, v, s = map(int, input().split())
dist = 0
while h > 0:
    v += s
    v -= max(1, v // 10)
    if v >= k:
        h += 1
    if 0 < v < k:
        h -= 1
    if v <= 0 or h == 0:
        v = 0
        h = 0
    dist += v
    if s > 0:
        s -= 1
print(dist)