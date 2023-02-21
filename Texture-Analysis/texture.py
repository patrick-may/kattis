import sys

def case(n, inp):
    balanced = [i for i in inp.split("*")]
    balanced = set(balanced[1:len(balanced) - 1])
    # print(balanced)
    print(n, "EVEN" if len(balanced) <= 1 else "NOT EVEN")

idx = 1
for line in sys.stdin:
    if "END" in line:
        break
    case(idx, line)
    idx += 1
