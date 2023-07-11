cases = int(input())

def ssd(n, b):
    soln = 0
    n = int(n)
    b = int(b)
    while n > 0:
        soln += (n % b) ** 2
        n //= b 
    return soln 

for _ in range(cases):
    _, base, numb = input().strip().split()
    print(_, ssd(numb, base))
