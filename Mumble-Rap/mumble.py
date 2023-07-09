input()
s = input()
solns = []
curr = ""
for c in s:
    if c.isdigit():
        curr += c
    elif curr != "":
        solns.append(int(curr))
        curr = ""
if curr != "":
    solns.append(int(curr))
print(max(solns))
