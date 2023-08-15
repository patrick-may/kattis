allowed, songct = map(int, input().split())
songs = list(map(int, input().split()))
allowed *= 60
soln = 0
for time in sorted(songs):
    if time > allowed:
        break
    soln += time
    allowed -= time
print(soln)
