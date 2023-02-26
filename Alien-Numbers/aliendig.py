# base conversion stuff
def translate():
    number, source, target = input().split()
    print(number, source, target)
    soln = ""

    if len(source) == len(target):
        for c in number:
            soln += target[source.find(c)]
        return soln
    if len(source) > len(target):
        pass

cases = int(input())

for c in range(cases):
    print(f"Case #{c+1}: {translate()}")