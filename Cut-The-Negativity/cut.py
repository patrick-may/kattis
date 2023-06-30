ct = int(input().strip())

flights = []
for i in range(1, ct + 1):
    arrivals = map(int, input().strip().split())
    for j, a in enumerate(arrivals):
        j = j + 1 # 1 based indexing
        if a != -1:
            flights.append((i, j, a))

print(len(flights))
for a, b, c in flights:
    print(a,b,c)

