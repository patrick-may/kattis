from sys import stdin
from collections import Counter
from math import comb

order = "A23456789TJQK"
# take in a frequency dict and count the number of possible ways
# to sum to 15
def count_15s(n):
    pass

# take in a frequency dictionary and count the number of pairs that are
# able to be constructed
# returns the number of points from pairs
def pairs(n):
    soln = 0
    for freq in n.values():
        if freq >= 2:
            soln += comb(freq, 2)
    return 2*soln

# recall we can reorder the cards as desired
def find_runs(n):
    soln = 0
    run = {}
    for x, key in enumerate(n.keys()):
        run[key] = n[key]

        if n[]


# here lies the I/O and getting stuff running
_ = input() # throw out the number of cards, this is not needed in python

hand = []
for line in stdin:
    for card in line.split():
        hand.append(card)


hand = sorted(hand, key= lambda e: order.index(e[0]))
f_map = Counter(hand)

if True:
    print(hand)
    print("15s", count_15s(hand))
    print("pairs", pairs(f_map))
    print("runs",runs(hand))
