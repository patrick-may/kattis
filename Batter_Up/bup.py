l = int(input())
bats = map(int, input().split())
s = 0
for i in bats:
    if i == -1:
        l -= 1
    else:
        s += i
print(s/l)