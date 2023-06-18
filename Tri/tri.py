a, b, c = input().strip().split()

ops = ["+", "-", "/", "*"]
eq = "=="
found = False
for o in ops:
    test = a + o + b + eq + c
    if eval(test):
        print(test.replace("==", "="))
        found = True
        break

if not found:
    for o in ops:
        test = a + eq + b + o + c
        if eval(test):
            print(test.replace("==", "="))
            found = True
            break

