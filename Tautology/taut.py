import sys

def kand(a, b):
    return (a and b)

def aor(a,b):
    return (a or b)

def nor(a):
    return (not a)

def cimplies(a, b):
    return (not a or b)

def equals(a, b):
    return (a == b)

def generate_options():
    mappings = []
    for p in [True, False]:
        for q in [True, False]:
            for r in [True, False]:
                for s in [True, False]:
                    for t in [True, False]:
                        option = {"p": p, "q": q, "r": r, "s": s, "t":t}
                        mappings.append(option)
    return mappings

# bruh.. ugly ass problem fr
def is_taut(line):
    
    truth_vals = generate_options()

    fn_map = {"K": kand, "A": aor, 'N': nor, "C": cimplies, "E": equals}
    for option in truth_vals:
        index = 0
        while index < len(line) - 1:
            c = line[index]
            if c in "KCE":
                l1, l2 = line[index + 1], line[index + 2]
                if fn_map[c](option[l1], option[l2]):
                    return False
                index += 2

            elif c == "AN":
                l1 = line[index + 1]
                if fn_map[c](option[l1]):
                    return False
                index += 1
                
            index += 1
    return True

for line in sys.stdin:
    if "0" in line:
        break
    print("tautology" if is_taut(line) else "not")
