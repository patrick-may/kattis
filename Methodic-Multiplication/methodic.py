from collections import Counter
n1 = input()
n2 = input()

ans = ""
if len(n1) != 1 and len(n2) != 1:
    c1 = Counter(n1)
    c2 = Counter(n2)
    reps = c1["S"] * c2["S"]
    
    ans = "S(" * reps
    ans += "0"
    ans += ")" * reps
else:
    ans = "0"

print(ans)
