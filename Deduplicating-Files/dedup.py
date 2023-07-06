from math import comb

def hashfile(file):
    soln = ord(file[0])
    for c in file:
        soln ^= ord(c) 

    return soln


def tc(filect):
    lookup = {}
    intersect, unique = 0, 0
    for _ in range(filect):

        filestr = input()
        hashed = hashfile(filestr)
        if hashed in lookup:
            if filestr in lookup[hashed]:
                unique -= 1
            lookup[hashed].append(filestr)
        else:
            lookup[hashed] = [filestr]

        unique += 1
    
    for v in lookup.values():
        intersect += 2*comb(len(v), 2)
    print(unique, intersect)

a = int(input())
while (a != 0):
    tc(a)
    a = int(input())
