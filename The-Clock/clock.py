rad = int(input())

hrs, mins = 0, 0
hrrad, minrad = 0, 0

while abs(minrad - hrrad) != rad:
    if minrad < hrrad and (3600 - (hrrad - minrad)) == rad:
        break
    hrrad += 5
    minrad += 60
    mins += 1
    if minrad == 3600:
        hrs += 1
        minrad = 0
        mins = 0
    if hrrad == 3600:
        hrs = 0
        hrrad = 0

    # print(hrrad, minrad, hrs, mins, abs(minrad - hrrad))

print (f"{hrs:02d}:{mins:02d}")

