from sys import stdin


def tc(levels, s):
    for _ in range(levels):
        soln = ""
        for c in s:
            if ord("!") <= ord(c) <= ord("*") or ord("[") <= ord(c) <= ord("]"):
                soln += "\\" + c
            else:
                soln += c
        s = soln
    print(s)


for line in stdin:
    levels = int(line.strip())
    s = input().strip()
    tc(levels, s)
