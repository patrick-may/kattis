from collections import defaultdict

def tc():
    items = defaultdict(int)
    sub = int(input())
    for _ in range(sub):
        a, b = input().split()
        items[a] += int(b)
    print(len(items))
    for k, v in sorted(items.items(), key= lambda x: (-x[1], x[0])):
        print(k, v)
cases = int(input())
for _ in range(cases):
    tc()
