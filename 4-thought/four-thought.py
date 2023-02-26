def case():
    goal = int(input())
    # lets get into the ugly comps
    ops = ["+", "-", "*", "//"]
    found = False
    for first in ops:
        if found:
            break
        for second in ops:
            if found:
                break
            for third in ops:
                s = f"4 {first} 4 {second} 4 {third} 4 "
                if eval(s) == goal:
                    print(s.replace("//", "/") + f"= {goal}")
                    found = True
                    break
    if not found:
        print("no solution")

c = int(input())
for _ in range(c):
    case()