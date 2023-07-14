from math import sqrt

a, b, c, d = map(int, input().split())

semiperim = (a + b + c + d) / 2

soln = sqrt((semiperim - a) * (semiperim - b) * (semiperim - c) * (semiperim - d))

print(soln)
