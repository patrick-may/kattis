def tc():
    line = input()
    words = line.split()
    if words[0] == "Simon" and words[1] == "says":
        print("",*words[2:])

cases = int(input())
for _ in range(cases):
    tc()
