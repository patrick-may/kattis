import math
a1, b1 = map(int, input().split())
a2, b2 = map(int, input().split())
a3, b3 = map(int, input().split())

abdist = math.sqrt((a1 - a2)**2 + (b1-b2)**2)
bcdist = math.sqrt((a2-a3)**2 + (b2-b3)**2)
print(abdist,bcdist)