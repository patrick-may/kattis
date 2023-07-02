import math
a1, b1 = map(int, input().split())
a2, b2 = map(int, input().split())
a3, b3 = map(int, input().split())

from collections import Counter

f1 = Counter([a1, a2, a3])
f2 = Counter([b1, b2, b3])

smallest = sorted(f1.items(), key=lambda x: x[1])[0]
smallest2 = sorted(f2.items(), key=lambda x: x[1])[0]
print(smallest[0], smallest2[0])
# the weirdest solution. I'm sure i'm missing the easy way to do this..
