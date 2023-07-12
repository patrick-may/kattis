input()
from sys import stdin


def test(a, b, c):
    if (a * b == c  
    or a + b == c 
    or a - b == c 
    or b - a == c 
    or a / b == c 
    or b / a == c):
        return True 
    return False
for line in stdin:
    a, b, c = map(int, line.strip().split())
    print ("Possible" if test(a, b, c) else "Impossible")
