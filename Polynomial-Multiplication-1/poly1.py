from sys import stdin

cases = int(stdin.readline())

for _ in range(cases):
    xpwr = int(stdin.readline())
    acoeffs = list(map(int, stdin.readline().split()))
    ypwr = int(stdin.readline())
    bcoeffs = list(map(int, stdin.readline().split()))

    # initialize arr
    product = [0] * (xpwr + ypwr + 1)
    for aloc, ac in enumerate(acoeffs):
        for bloc, bc in enumerate(bcoeffs):
            # sum coeffs based off location
            product[aloc + bloc] += ac * bc
    # print + unpack
    print(len(product) - 1)
    print(*product)
