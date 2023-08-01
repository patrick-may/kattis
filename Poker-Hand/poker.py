from collections import Counter

hand = [x[0] for x in input().split()]
print(max(Counter(hand).values()))
