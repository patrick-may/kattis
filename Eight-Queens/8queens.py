board = []
for _ in range(8):
    board.append(input().strip())

def checkBoard(board):
    qlocs = [] 
    # check horizontals
    for x, row in enumerate(board):
        qct = 0
        for y, c in enumerate(row):
            if c == '*':
                qct += 1
                qlocs.append( (x, y) )
        if qct != 1:
            return False
    
    # check columns
    for i in range(8):
        qct = 0
        for c in range(8):
            if board[c][i] == '*':
                qct += 1
                qlocs.append( (c, i) )

        if qct != 1:
            return False
    
    
    for x, y in qlocs:
        xcpy, ycpy = x, y
        # left up
        while xcpy > -1 and ycpy > -1:
            xcpy -= 1
            ycpy -= 1
            if (xcpy, ycpy) in qlocs:
                return False 
        xcpy, ycpy = x, y
        # right up
        while xcpy > -1 and ycpy < 9:
            xcpy -= 1
            ycpy += 1
            if (xcpy, ycpy) in qlocs:
                return False
        
        xcpy, ycpy = x, y
        # left down
        while xcpy < 9 and ycpy > -1:
            xcpy += 1
            ycpy -= 1
            if (xcpy, ycpy) in qlocs:
                return False

        xcpy, ycpy = x, y
        # right down
        while xcpy < 9 and ycpy < 9:
            xcpy += 1
            ycpy += 1
            if (xcpy, ycpy) in qlocs:
                return False

    return True

print("valid" if checkBoard(board) else "invalid")


