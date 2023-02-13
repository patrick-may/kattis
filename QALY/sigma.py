cases = int(input())
total = 0
for _ in range(cases):
    a, b = map(float, input().split())
    total += a * b

print(f"{total:.3f}")