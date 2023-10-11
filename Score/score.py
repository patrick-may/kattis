from sys import stdin 
from datetime import time 

lines = int(input())

homeScore, awayScore = 0, 0
homeSecs, awaySecs = 0, 0
priorlead = "N"
priortime = 0
def toSeconds(time):
    h, m = map(int, time.split(":"))
    return 60 * h + m

def toFancy(seconds):
    s = seconds % 60
    if s < 10:
        s = "0" + str(s)
    return f"{seconds // 60}:{s}"

for _ in range(lines):
    line = input()
    line = line.strip()
    team, score, time = line.split(" ")
    time = toSeconds(time)     
    # solving each line 
    if team == "H":
        homeScore += int(score)
        
    else:
        awayScore += int(score)
    
    elapsedtime = time - priortime 
    priortime = time
    
    if priorlead == "H":
        homeSecs += elapsedtime 
    elif priorlead == "A":
        awaySecs += elapsedtime

    if homeScore > awayScore:
        # home leads
        priorlead = "H"
        
    elif awayScore > homeScore:
        # away leads
        priorlead = "A"
    else:
        priorlead = "N"
    
lasttime = toSeconds("32:00")
elapsedtime = lasttime - priortime 
priortime = time

if priorlead == "H":
    homeSecs += elapsedtime 
elif priorlead == "A":
    awaySecs += elapsedtime

print("H" if homeScore > awayScore else "A", toFancy(homeSecs), toFancy(awaySecs))


