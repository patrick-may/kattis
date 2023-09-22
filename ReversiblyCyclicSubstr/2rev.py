# see if a splitting of q can be fit in the ref str
def checkIn(ref, rots, q):

    # simple case where reversed substr exists within default string
    if q in ref:
        return True 

    # check every rotation of source string
    for rot in rots:
        if q in rot:
            return True

    return False

def genRots(src):
    soln = []
    soln.append(src)
    copy = src
    copy = copy[1:] + copy[0]
    for _ in range(len(src)):
        soln.append(copy)
        copy = copy[1:] + copy[0]
    
    return soln

s = input()

rots = genRots(s)
l, r = s[1:], s[:-1]
l, r = l[::-1], r[::-1]
#print(l, r, rots)
print(1 if checkIn(s, rots, l) and checkIn(s, rots, r) else 0)
