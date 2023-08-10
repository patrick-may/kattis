inp = list(map(float, input().strip().split()))

x1, y1 = inp[:2]
x2, y2 = inp[2:]

l = max(x1, x2) - min(x1, x2)
w = max(y1, y2) - min(y1, y2)

print(f"{l*w:.3f}")
