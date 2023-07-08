input()
from sys import stdin
from math import sqrt

def rot(line):
    base = int(sqrt(len(line)))
    soln = ""
    for offset in range(base):
        for j in range(base*(base - 1), -1, -base):
            soln += line[j + offset]
    return soln

for line in stdin:
    line = line.strip()
    soln = rot(rot(rot(line)))
    print (soln)


