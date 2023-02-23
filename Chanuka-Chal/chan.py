def case():
    _, a = map(int, input().split())
    return (a*(a+1)//2 + a)

c = int(input())
for b in range(1, c+1):
    print(b, case())