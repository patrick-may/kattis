rot, sec = map(int, input().split())
print("up" if round(sec / rot) % 2 != 1 else "down")
