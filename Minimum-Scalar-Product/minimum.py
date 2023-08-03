from sys import stdin

r = stdin.readline


def testcase(i):
    r()
    p1 = list(map(int, r().split()))
    p2 = list(map(int, r().split()))
    soln = 0

    for a, b in zip(sorted(p1), sorted(p2, reverse=True)):
        soln += a * b

    print(f"Case #{i}: {soln}")


tc = int(r())
for _ in range(tc):
    testcase(_ + 1)
