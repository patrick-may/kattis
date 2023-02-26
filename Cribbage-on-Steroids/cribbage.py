from sys import stdin
from collections import Counter
from math import comb
from functools import lru_cache
order = "A23456789TJQK"
# take in a frequency dict and count the number of possible ways
# to sum to 15
# dynamic programming jawn
def count_15s(n):
    worth = {"A":1,"2":2,"3":3,"4":4,"5":5,"6":6,"7":7,"8":8,"9":9,"T":10,"K":10,"J":10,"Q":10}
    point_list = []
    for card, freq in n.items():
        point_list.extend([worth[card]]*freq)
    #print(point_list)

    # cache the call (free dynamic prog?!)
    @lru_cache(maxsize=None)
    def recur(sublist, target):
        local_sum = 0

        # no more possible sums in the entire call branch
        if sum(sublist) < target:
            return 0
        
        for x, item in enumerate(sublist):
            if item > target:
                break

            if item == target:
                local_sum += 1
            
            else:
                local_sum += recur(sublist[x + 1:], target - item)
        
        return local_sum
            
    soln = recur(tuple(point_list), 15)
    return 2 * soln

# take in a frequency dictionary and count the number of pairs that are
# able to be constructed
# returns the number of points from pairs
def pairs(n):
    soln = 0
    for freq in n.values():
        if freq >= 2:
            soln += comb(freq, 2)
    return 2*soln


def calc_run(f_map):

    if len(f_map.keys()) < 3:
        return 0
    
    multiplier = 1
    for card, freq in f_map.items():
        multiplier *= freq
    
    #print("run on",f_map,"is",len(f_map.keys())*multiplier)
    return len(f_map.keys())*multiplier
    
# recall we can reorder the cards as desired
def find_runs(n):
    soln = 0
    run = {}
    seq = list(n.keys())
    for x, key in enumerate(seq):
        run[key] = n[key]

        if x + 1 > len(seq) - 1:
            soln += calc_run(run)
            break
        if order.index(key) + 1 < order.index(seq[x + 1]):
            soln += calc_run(run)
            run = {}

    return soln



# here lies the I/O and getting stuff running
_ = input() # throw out the number of cards, this is not needed in python

hand = []
for line in stdin:
    for card in line.split():
        hand.append(card)


hand = sorted(hand, key= lambda e: order.index(e[0]))
f_map = Counter(hand)

if False:
    print(hand)
    print("15s", count_15s(f_map))
    print("pairs", pairs(f_map))
    print("runs",find_runs(f_map))

print(count_15s(f_map) + pairs(f_map) + find_runs(f_map))