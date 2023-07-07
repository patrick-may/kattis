n = int(input())
b = str(bin(n))[2:]
print(int(b[::-1], 2))
