a, b = map(int, input().split())

avg = 0
for _ in range(b):
    avg += int(input())

lower = (avg + -3*(a-b)) / a
upper = (avg + 3*(a-b)) / a
print(f"{lower:.4f} {upper:.4f}")