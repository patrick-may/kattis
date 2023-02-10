p1 = tuple(map(int, input().split()))
p2 = tuple(map(int, input().split()))
p3 = tuple(map(int, input().split()))

a = p1[0] + p2[0] - p3[0]
b = p1[1] + p2[1] - p3[1]

c = p1[0] - p2[0] + p3[0]
d = p1[1] - p2[1] + p3[1]
print(a,b)
print(c,d)