r, c = map(int, input().strip().split())

board = []
words = []
for _ in range(r):
    inp = input().strip()
    for w in inp.split("#"):
        if len(w) >= 2:
            words.append(w)
    board.append(inp)

for col in range(c):
    currcol = ""
    for row in range(r):
        currcol += board[row][col]
    
    for w in currcol.split("#"):
        if len(w) >= 2:
            words.append(w)

print(min(words))