def solve(words):
    best = "neibb!"
    found = False
    for w in words:
        # duplicate letters
        if len(set(w)) != len(w):
            continue 
        if len(set(w)) < 5: # not long enough
            continue

        if len(w) < len(best) or not found:
            best = w
            found = True 
        elif len(w) == len(best) and w > best:
            best = w
            found = True 

    print(best)

w = int(input())

words = []
for _ in range(w):
    words.append(input().strip())

solve(words)