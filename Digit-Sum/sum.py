def naive_sum(n):
    total = 0
    for i in range(n + 1):
        total += sum([int(j) for j in str(i)])
    return total

def digsum(n):
    soln, mult = 0, 1
    diglist = list(map(int, str(n)))
    pos = len(diglist) - 1 # start at end of number

    while pos >= 0: # traverse entire number from smallest digit to max
        # account for all different digit sum options
        soln += sum(diglist[:pos]) * diglist[pos] * mult 
        soln += diglist[pos] * (diglist[pos] - 1) // 2 * mult
        soln += 45 * (mult // 10) * (len(diglist) - pos - 1) * diglist[pos]
        # update position and multiplier
        pos -= 1
        mult *= 10
    
    return soln

def solve():
    
    start, end = map(int, input().split())
    s = digsum(start)
    e = digsum(end + 1)
    print(e-s)
    
cases = int(input())
for _ in range(cases):
    solve()