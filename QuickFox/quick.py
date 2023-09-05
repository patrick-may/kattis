def tc():
    line = input()
    alph = set("abcdefghijklmnopqrstuvwxyz")
    miss = set()
    for c in line:
        if c.lower() in alph:
            alph.remove(c.lower())

    if len(alph) == 0:
        print("pangram")
    else:
        print( "missing ", end = "")
        print("".join([i for i in sorted(alph)]))
 

cases = int(input())
for _ in range(cases):
    tc()
