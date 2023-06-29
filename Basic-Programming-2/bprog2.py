size, t = map(int, input().strip().split())
arr = list(map(int, input().strip().split()))

if t == 1:
    m = {}
    for n in arr:
        if n in m.keys() and n != m[n]:
            print("Yes")
            exit()
        m[7777 - n] = n
    print("No")

elif t == 2:
    print("Unique" if len(arr) == len(set(arr)) else "Contains duplicate")

elif t == 3:
    from collections import Counter
    c = Counter(arr)
    seen = False 
    for k, v in c.items():
        if v >= len(arr) / 2:
            print(k)
            seen = True
            break
    if not seen:
        print("-1")

elif t == 4:
    s = sorted(arr)
    if len(arr) % 2 == 1:
        print(s[len(arr)//2])
    else:
        print(s[len(arr)//2 - 1], s[len(arr)//2])

elif t == 5:
    s  = [i for i in arr if 100 <= i <= 999]
    for n in sorted(s):
        print(n, end=" ")
    print()
    
