inp = input()
spots = []
smiles = {":)", ";)", ":-)", ";-)"}
for i in range(len(inp)-1):
    two = inp[i:i+2]
    three= inp[i:i+3]
    if two in smiles or three in smiles:
        spots.append(i)

for s in spots:
    print(s)