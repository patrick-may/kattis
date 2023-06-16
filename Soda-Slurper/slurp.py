e, f, c = map(int, input().split())
firstf = f 
soln = 0

while e + f >= c:    
    # drink all full ones
    soln += f

    # they are now empty, add to empty count
    e += f

    # trade in empty bottles for new full ones
    f = e // c

    # keep the leftover for next day
    e = e % c

print(soln + f - firstf)
    

