n = int(input())

if n % 2 == 0 and n % 4:  # even, non-divisible by 4
    print("impossible")
    exit()

if n % 2 == 0:
    a = n // 4
    print(a - 1, a + 1)

else:
    a = (n - 1) // 2
    print(a, a + 1)
