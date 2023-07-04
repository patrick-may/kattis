moves = input().strip()

def countfreq(needle, haystack):
    ct = 0
    while needle in haystack:
        haystack = haystack.replace(needle,"",1)
        ct += 1 
    return ct 

worst = len(moves)
best = len(moves)
tried = set()
for i in range(len(moves)):
    for j in range(i + 1, len(moves)):
        substrA = moves[i:j]
        if substrA in tried:
            continue

        haystack = moves[:i] + moves[j:]
        count = countfreq(substrA, haystack)
        
        newmac = len(haystack) - (count - 1)*len(substrA) + count
        best = min(best, newmac)
        tried.add(substrA)

print(best)

