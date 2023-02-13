alph = input()
cipher = input()

soln = ""
for idx in range(0, len(cipher)-1, 3):
    soln += alph[int(cipher[idx:idx+3])-1]
print(soln)