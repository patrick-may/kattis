scores = []
for i in range(1, 6):
    scores.append((i, sum(map(int, input().split()))))

v = max(scores, key=lambda x: x[1])
print(v[0],v[1])