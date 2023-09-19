a = input()
b = input()
diff = 0
for x, y in zip(a, b):
    if x != y:
        diff += 1

print(2**diff)
