from sys import stdin

def tc(ct):
    food = {}
    for _ in range(ct):
        inp = input().strip().split()
        person, items = inp[0], inp[1:]
        for f in items:
            if f in food:
                food[f].append(person)
            else:
                food[f] = [person]
    for k in sorted(food.keys()):

        print(k, end=" ")
        for person in sorted(food[k]):
            print(person, end=" ")
        print()
    print()

for line in stdin:
    ct = int(line)
    if ct == 0:
        exit()
    tc(ct)
