friends = int(input())
dates = {}
for _ in range(friends):
    name, pref, date = input().split()
    pref=int(pref)
    if date in dates:
        # print("collision on",date,"between",name,"and",dates[date][1])
        if dates[date][0] < pref:
            dates[date] = (pref, name)
    else:
        dates[date] = (pref, name)

rem = len(dates.keys())
names = sorted(dates.values(), key=lambda x: x[1])
print(rem)
for n in names:
    print(n[1])