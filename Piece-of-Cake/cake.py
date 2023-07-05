n, h, v = map(int, input().strip().split())

fullc = n * n * 4
c1 = h * v * 4
c2 = h * (n - v) * 4
c3 = (n - h) * v * 4
c4 = (n - h) * (n - v) * 4
print(max([c1, c2, c3, c4]))
