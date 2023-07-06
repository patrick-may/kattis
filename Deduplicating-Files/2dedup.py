from math import comb

def hashfile(file):
    soln = 0
    for c in file:
        soln ^= ord(c) 

    return soln


def tc(filect):
    filehashes = {}
    
    intersect, unique = 0, set()
    for _ in range(filect):

        filestr = input()
        h = hashfile(filestr)
        if h in filehashes:
            if filestr in filehashes[h]:
                filehashes[h][filestr] += 1
            else:
                filehashes[h][filestr] = 1
        else:
            filehashes[h] = {}
            filehashes[h][filestr] = 1
        unique.add(filestr)


    for hashval, freqdict in filehashes.items():
        freqs = []
        for _, ct in freqdict.items():
            freqs.append(ct)

        for i in range(len(freqs)-1):
            for j in range(i + 1, len(freqs)):
                intersect += freqs[i]*freqs[j]

    print(len(unique), intersect)

a = int(input())
while (a != 0):
    tc(a)
    a = int(input())
