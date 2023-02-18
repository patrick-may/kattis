from collections import Counter

s = input()
letters = Counter(s)
already = 0
for i, c in enumerate(s):
    if i%3 == 0 and c == "P":
        already+=1
    elif i%3 == 1 and c == "E":
        already+=1
    elif i%3 == 2 and c =="R":
        already += 1
print(len(s) - already)
    
