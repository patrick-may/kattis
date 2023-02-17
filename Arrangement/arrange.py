rooms = int(input())
teams = int(input())

import math

per_room = math.ceil(teams/rooms)
down = math.floor(teams/rooms)

if down == per_room:
    pme = ("*" * down + "\n") * rooms
    print(pme,end="")

else:
    pme = "*" * per_room
    print(pme)
    teams -= per_room
    while teams % down != 0:
        pme = "*" * per_room
        print(pme)
        teams -= per_room
    while teams > 0:
        pme = "*" * down
        print(pme)
        teams -= down