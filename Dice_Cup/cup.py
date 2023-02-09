d1, d2 = map(int, input().split())
vals = {}
for i in range(1, d1+1):
    for j in range(1,d2+1):
        if i + j in vals:
            vals[i + j]+=1
        else:
            vals[i+j] = 1

v = vals.items()
top = max(v, key=lambda x:x[1])

for roll in vals.keys():
    if vals[roll] == top[1]:
        print(roll)