lookup = {}

from sys import stdin

def dostuff():
    for line in stdin:
        
        l = line.strip()
        print(lookup[l] if l in lookup else "eh")

for line in stdin:

    vals = line.strip().split()
    if len(vals) == 2:
        word, alias = line.strip().split()
        lookup[alias] = word
    else:
        dostuff()
        break
