# honestly, this problem seems extremely difficult (and a math problem, not programming)
# if the goal is to derive a recursive formula for the catalan numbers.
from math import factorial
from sys import stdin
from functools import lru_cache


@lru_cache(maxsize=None)
def fact(n):
    return factorial(n)


def catalan(n):
    return fact(2 * n) // (fact(n + 1) * fact(n))


stdin.readline()

for line in stdin:
    print(catalan(int(line.strip())))
