blimps = []
for _ in range(5):
    blimps.append(input())

found = False
for x, b in enumerate(blimps):
    if "FBI" in b:
        print(x+1)
        found = True

if not found:
    print("HE GOT AWAY!")
    