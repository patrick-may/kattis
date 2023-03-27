

inp = input()
digits = "0123456789"
usable = []
# get all possible digits one can use
for d in digits:
    if d not in inp:
        usable.append(int(d))

