
def tc():
    mwidth = int(input())

    if mwidth == 0:
        exit()

    sw, sh = 0, 0
    cw, ch = 0, 0
    
    w, h = map(int, input().split())
    while w != -1 and h != -1:
        if cw + w > mwidth:
            sh += ch
            sw = max(sw, cw) 
            cw = w
            ch = h 
        else:
            ch = max(h, ch)
            cw += w 

        pw, ph = cw, ch 
        w, h = map(int, input().split())

        if w == h == -1:
            sh += ph 
            sw = max(sw, pw)

    print(f"{sw} x {sh}")

while 1:
    tc()