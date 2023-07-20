def printboard(board):
    for r in board:
        print(r)

def checkSquare(smallSquare, checkNum):
    for r in smallSquare:
        for c in r:
            if checkNum == c:
                return False
    return True

def hatchRows(board, hatchNum):
    hatchedBoard = []
    for row in board:
        splits = row.split(hatchNum)
        if len(splits) > 2:
            print("ERROR")
            exit()
        hatchedRow = ""
        for s in splits:
            if s == hatchNum:
                hatchedRow+= s 
            else:
                hatched

            

board = []
for _ in range(9):
    board.append(input())

def solve_cell(board):
    opts = [1, 2, 3, 4, 5, 6, 7, 8, 9]


