from collections import Counter
from sys import stdin
# MAN! What a heartbreaker of a problem, the input is the hard part

# given a frequency dictionary of all the items in the query
# print out the correct order of stuff
def right_order(freq_dict):
    if_tie = "ATGC"
    soln = ""
    for tup in sorted(freq_dict.items(), 
                key=lambda e: (e[1], -if_tie.index(e[0])), reverse=True):
        soln += tup[0]
    
    for k in if_tie:
        if k not in soln:
            soln += k
    
    print(soln)
        
strand = input().strip()

# at the very beginning there isn't anything in our array
all_dicts = []
a, act = [0], 0
c, cct = [0], 0
g, gct = [0], 0
t, tct = [0], 0

for character in strand:
    if character == 'A':
        act += 1
    if character == 'T':
        tct += 1
    if character == 'G':
        gct += 1
    if character == 'C':
        cct += 1
    a.append(act)
    c.append(cct)
    g.append(gct)
    t.append(tct)
a.append(act)
c.append(cct)
g.append(gct)
t.append(tct)

cases = int(input())
for line in stdin:
    start, end = map(int, line.split())
    subdict = {"A": a[end] - a[start-1], "C": c[end] - c[start - 1],
               "G": g[end] - g[start - 1], "T": t[end] - t[start - 1]}
    right_order(subdict)
