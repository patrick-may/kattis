input()

from sys import stdin

for line in stdin:
    seq = list(map(int, line.strip().split()))
    seq.pop()
    bound = 0
    prior = seq[0]
    for population in seq[1:]:
        diff = population - prior 
        bound += max(0, diff - prior)
        prior = population
    print(bound)
        
