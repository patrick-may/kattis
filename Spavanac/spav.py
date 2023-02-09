hour, mins = map(int, input().split())

mins -= 45

if mins < 0:
    hour -= 1
    mins += 60
if hour < 0:
    hour = 23

print(hour,mins)