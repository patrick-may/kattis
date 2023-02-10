
n = input()
m = len(n)
ws, upper, lower, symbols = 0,0,0,0
for c in n:
    if c.isupper():
        upper += 1
    elif c.islower():
        lower += 1
    elif c == "_":
        ws += 1
    else:
        symbols += 1

print(ws/m)
print(lower/m)
print(upper/m)
print(symbols/m)
