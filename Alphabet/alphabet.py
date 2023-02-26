# small case size means brute force could work here...
case = input()
alphabet = "abcdefghijklmnopqrstuvwxyz"
best = 26
for x, startpoint in enumerate(case):
    found = 1
    after = alphabet[alphabet.find(startpoint)+1:]
    for after_lets in case[x+1:]:
        c = after.find(after_lets)
        if c == -1:
            break
        after = after[c + 1:]
        found += 1
    best = min(best, 26 - found)
    
print(best)
