def valid10(isbn: str) -> bool:
    if isbn.count('X') > 0 and isbn[-1] != 'X':
        return False
    # cannot begin or end with hyphens
    if isbn[0] == '-' or isbn[-1] == '-':
        return False
    # no adj hyphens:
    if isbn.count('--') > 0 or isbn.count('---') > 0:
        return False
    # if three hyphens, must sep checksum
    if isbn.count('-') == 3 and isbn[-2] != '-':
        return False
    
    dec = 0
    val = 0
    for c in isbn:
        if c == '-':
            continue
        if c == 'X':
            c = 10
        else:
            c = int(c)
        val += ((10 - dec) * c)
        dec += 1
    return val % 11 == 0

def convert13(isbn: str) -> str:
    if not valid10(isbn):
        return "invalid"
    soln = "978-"
    val = (9 * 1) + (7 * 3) + (8 * 1)
    mult = 3
    for c in isbn[:-1]:
        if c == '-':
            soln += '-'
            continue
        soln += c
        c = int(c)
        val += (c * mult)
        mult = 1 if mult == 3 else 3

    # figure checksum
    soln += str(10 - (val % 10))
    return (soln)

input()
from sys import stdin
for line in stdin:
    print(convert13(line.strip()))

