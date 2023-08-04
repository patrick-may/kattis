# a -> h columns
# 1 -> 8 rows
def pv1(piece):
    if len(piece) < 3:
        return 100
    if piece[0] == "N":
        return 50
    if piece[0] == "B":
        return 40
    if piece[0] == "R":
        return 30
    if piece[0] == "Q":
        return 20
    # king
    return 10


def pv2(piece, isblack):
    val = 0
    if len(piece) < 3:
        val = int(piece[1])
    else:
        val = int(piece[2])

    return -val if isblack else val


def pv3(piece):
    if len(piece) < 3:
        return ord(piece[0])
    return ord(piece[1])


def notationify(piece, row, col):
    alph = chr(ord("a") + col)
    if piece.upper() != "P":
        return piece + alph + str(row)
    return alph + str(row)


white = []
black = []

row = 9
for _ in range(16):
    if _ % 2 == 0:
        input()  # consume line, but its just padding
        continue
    line = input()
    row -= 1

    for colidx in range(2, 32, 4):
        piece = line[colidx]
        if piece != ":" and piece != ".":
            if piece.isupper():
                white.append(notationify(piece, row, (colidx - 2) // 4))
            else:
                black.append(notationify(piece.upper(), row, (colidx - 2) // 4))


# print("WHITE:", sorted(white))
# print("BLACK:", sorted(black))
print("White: ", end="")
wsoln = ""
for val in sorted(white, key=lambda x: (pv1(x), pv2(x, False), pv3(x))):
    wsoln += val + ","
print(wsoln[:-1])

bsoln = ""
print("Black: ", end="")
for val in sorted(black, key=lambda x: (pv1(x), pv2(x, True), pv3(x))):
    bsoln += val + ","
print(bsoln[:-1])
