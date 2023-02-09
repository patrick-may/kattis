cases = int(input())

for _ in range(cases):
    l1 = input()
    l2 = input()
    soln=l1+"\n"+l2+"\n"
    for a, b in zip(l1,l2):
        
        if a != b:
            soln+="*"
        else:
            soln+="."
            
    print(soln)