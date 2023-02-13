from collections import Counter
freqmap = Counter(input())
print("1" if max(freqmap.values()) == 1 else "0")
