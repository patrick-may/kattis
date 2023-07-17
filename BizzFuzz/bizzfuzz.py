A, B, C, D = map(int, input().strip().split())


def gcd(a, b):
    while b:
        a, b = b, a % b
    return a


def lcm(a, b):
    return (a * b) // gcd(a, b)


def divrange(a, c, d):
    return a // lcm(c, d)


print(divrange(B, C, D) - divrange(A - 1, C, D))
