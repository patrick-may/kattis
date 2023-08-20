import sys

def K(a, b):
    return (a and b)

def A(a,b):
    return (a or b)

def N(a):
    return (not a)

def C(a, b):
    return (not a or b)

def E(a, b):
    return (a == b)

def evaluateWFF(expr, vals):
    op = expr[0] # first character will always be an operator

    # not just is one
    if op == 'N':
        return N(evaluateWFF(expr[1:], vals))

    # op \in K, A, C, E
    # otherwise, break into two WFF 



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


def is_taut(line):
    
    truth_vals = generate_options()
    
    for option in truth_vals:
         

    return True

for line in sys.stdin:
    if "0" in line:
        break
    print("tautology" if is_taut(line) else "not")
