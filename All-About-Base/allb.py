# take a num, interpret it as if it were of base base, return value in b10
def convert(n1, base):
    if base == 1:
        for c in str(n1):
            if c != '1':
                return -1
        return len(str(n1))
    try:
        return int(n1, base)
    except:
        return -1


def solve(n1, op, n2, ans):
    soln = ""
    bases = "123456789abcdefghijklmnopqrstuvwxyz0"
    for b in range(1, 37):
        first = convert(n1, b)
        second = convert(n2, b)
        res = convert(ans, b)
        if first == -1 or second == -1 or res == -1:
            continue
        expr = str(first) + " " + op + " " + str(second)
        if eval(expr) == res:
            soln += bases[b-1] 
    print(soln if len(soln) else "invalid")


cases = int(input())
for _ in range(cases):
    n1, op, n2, eq, ans = input().strip().split(" ")
    solve(n1, op, n2, ans)
    #print(n1, op, n2, eq, ans)