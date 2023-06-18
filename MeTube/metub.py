from sys import stdin
from functools import cache
input() # discard row ct

must_see = set()
vids = []
for line in stdin:
    sec, cats = line.split()
    sec = int(sec)
    vids.append((cats, sec))
    for c in cats:
        must_see.add(c)

print(must_see, "\n", vids)

bests = []

@cache
def dp(options, time, visited):
    # all cats done
    if visited == must_see:
        return time

    # no more choices left 
    if not options:
        bests.append(time)
        return 0
    
    best = 1e99
    for idx, v in enumerate(options):
        currcats, currtime = v
        rem_choices = options[:idx] + options[idx + 1:]

        dont_take = dp(rem_choices, time, visited)
        
        updated_vis = visited
        for c in currcats:
            updated_vis.add(c)

        take = dp(rem_choices, time + currtime, updated_vis)
    return best

a = set()
dp(tuple(vids), 0, a)
print(min(bests))
        


