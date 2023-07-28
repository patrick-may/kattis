b, b_r, b_s, a, a_s = map(int, input().split())

bobMoney = (b_r - b) * b_s

aliceMoney = 0
while aliceMoney <= bobMoney:
    a += 1
    aliceMoney += a_s

print(a)
