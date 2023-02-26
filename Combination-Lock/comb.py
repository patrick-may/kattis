# quite literally the stupidest problem that with the worst description so far
def degrees(start,first,sec,third):
    # 360 / 40 = 9
    rot = 120 # two full turns, and the counter rotation
    if first > start:
        rot += 40 - first + start # rotate cw from start to first
    else: # rotate to 0, then to the first val
        rot += abs(start - first)
        
    
    if first > sec:
        rot += (40 - first) + sec# rotate ccw from first to sec
    else:
        rot += abs(first - sec)

    if third > sec:
        rot += (40 - third) + sec
    else: 
        rot += abs(third - sec)

    print(9*rot)

while(1):
    vals = list(map(int, input().split()))
    if sum(vals) == 0:
        break
    degrees(vals[0], vals[1], vals[2], vals[3])