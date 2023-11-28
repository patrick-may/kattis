
lookup = [21, 12, 66, 55, 44, 33, 22, 11, 65, 64, 63, 62, 61, 54, 53, 52, 51, 43, 42, 41, 32, 31]

def getPlace(num):

    return lookup.index(num)

def checkp1Win(d1, d2, d3, d4) -> bool:
    d1, d2 = sorted([int(d1), int(d2)], reverse = True)
    d3, d4 = sorted([int(d3), int(d4)], reverse= True) 
    
#    print(d1, d2)
#    print(d3, d4)
    roll1 = getPlace(int(str(d1) + str(d2)))
    roll2 = getPlace(int(str(d3) + str(d4)))
    
    return roll1 < roll2 
   
from math import gcd

def lowestForm(top, bot):
    d = gcd(top, bot) 

    bot //= d 
    top //= d

    if top == bot:
        print(1)
    elif top == 0:
        print(0)
    else:
        print(f"{top}/{bot}")


def solve(inp):

    d1, d2, d3, d4 = inp.split()
    if d1 == '0' and d2 == '0' and d3 == '0' and d4 == '0':
        exit(0) 
    opts1 = [str(i) for i in range(1, 7)] if d1 == '*' else [d1]
    opts2 = [str(i) for i in range(1, 7)] if d2 == '*' else [d2]
    opts3 = [str(i) for i in range(1, 7)] if d3 == '*' else [d3]
    opts4 = [str(i) for i in range(1, 7)] if d4 == '*' else [d4]
    solns = 0
    tot = 0
    for fir in opts1:
        for sec in opts2:
            for thir in opts3:
                for four in opts4:
                    tot += 1 
                    if checkp1Win(fir, sec, thir, four):
                        solns += 1

    lowestForm(solns,tot) 

from sys import stdin

for line in stdin:
    solve(line.strip())
