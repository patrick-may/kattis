import sys

def to_soundex(s:str)->str:
    soln = ""
    key = {'B':1, "F":1, "V":1, "P":1,
            "C":2, "G":2, "J":2, "K":2, "Q":2, "S":2, "X":2, "Z":2,
            "D":3, "T":3, 
            "L":4, 
            "M":5, "N":5, 
            "R":6}
    idx = 0
    while idx < len(s):
        if s[idx] not in key:
            idx += 1
            continue
        letter = key[s[idx]]
        idx += 1
        while s[idx] in key and letter == key[s[idx]]: idx += 1
        soln += str(letter)
    
    print(soln)

for line in sys.stdin:
    to_soundex(line)