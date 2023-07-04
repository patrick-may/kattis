# fun file name teehee
width = int(input())
pieces = int(input())
area = 0
for _ in range(pieces):
    h, w = map(int, input().strip().split())
    area += (h*w)

print(area//width)
