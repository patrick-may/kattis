a, b = map(int, input().strip().split("/"))

# put 32 in terms of denominator
anew = 32 * b 

c = (a - anew) * 5
d = b * 9

import math
while math.gcd(c, d) != 1:
    #print(f"{c}/{d}, gcd is {math.gcd(c, d)}") 
    div = math.gcd(c, d)
    c //= div
    d //= div 

print(f"{c}/{d}")

