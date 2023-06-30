sec = int(input())
a = input()
b = input()

def flip(s):
    soln = ""
    for c in s:
        if c == '0':
            soln += '1'
        else:
            soln += '0'
    return soln

for _ in range(sec):
    a = flip(a)

print("Deletion succeeded" if a == b else "Deletion failed")
