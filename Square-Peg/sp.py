from math import sqrt
sidelen, radius = map(int, input().split())

print('fits' if sqrt(2)*radius >= sidelen else "nope")